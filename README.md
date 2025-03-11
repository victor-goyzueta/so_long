# so_long

![so_long](so_long.gif)

## Objetivo general de `so_long`

### Juego

- El objetivo del jugador es recolectar todos los objetos presentes en el mapa y salir eligiendo la ruta más corta posible.
- Las teclas `W`, `A`, `S` y `D` se utilizarán para mover al personaje principal.
- El jugador debe poder moverse en 4 direcciones: subir, bajar, ir a la izquierda o ir a la derecha.
- El jugador no puede entrar dentro de las paredes.
- Tras cada movimiento, el número real de movimientos debe mostrarse en un terminal.
- Utilizarás una perspectiva 2D (vista de pájaro o lateral).
- El juego no necesita ser en tiempo real.

### Gestión de gráficos

- El programa mostrará la imagen en una ventana.
- La gestión de tu ventana debe ser limpia (cambiar de ventana, minimizar, etc).
- Pulsar la tecla `ESC` debe cerrar la ventana y cerrar el programa limpiamente.
- Hacer clic en la cruz roja de la ventana debe cerrar la ventana y terminar el programa limpiamente.
- El uso de imágenes de la `miniLibX` es obligatorio.

### Mapa

- El mapa estará construido de 3 componentes: paredes, objetos y espacio abierto.
- El mapa estará compuesto de solo 5 caracteres:
  - `0` para un espacio vacío.
  - `1` para un muro.
  - `C` para un coleccionable.
  - `E` para salir del mapa.
  - `P` para la posición inicial del jugador.
- El mapa debe tener una salida, al menos un objeto y una posición inicial.
- El mapa debe ser rectangular.
- El mapa deberá estar cerrado/rodeado de muros; en caso contrario, el programa deberá devolver un error.
- Tienes que comprobar si hay un camino válido en el mapa.
- Debes poder procesar cualquier tipo de mapa, siempre y cuando respete las anteriores normas.
- En caso de fallos de configuración de cualquier tipo encontrados en el archivo, el programa debe terminar correctamente y devolver `Error\n` seguido de un mensaje explícito de tu elección.

---

## Bonus

- Haces que el jugador pierda cuando toque una patrulla de enemigos.
- Añades algunas animaciones de sprites.
- Muestras el contador de movimiento directamente en la pantalla en lugar de en el terminal.

## Validación de requisitos

```c
#include "so_long.h"

void check_map(char *file, t_game *game)
{
    int fd;

    fd = 0;
    if (!game || !file || !*file)
        free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
    game->map->matrix = NULL;
    check_map_format(file, game);
    allocate_matrix(game, &fd);
    allocate_object(game);
    check_map_rectangular(game);
    check_map_walls(game);
    check_map_composition(game);
    check_map_playable(game);
}
```

Revisamos que el mapa cumpla con los requisitos que nos impone el subject:

- Formato del archivo debe ser `.ber`.
- El mapa debe ser rectangular.
- El mapa debe estar rodeado de muros.
- El mapa debe estar compuesto por un único jugador, una única salida y al menos un coleccionable.
- El mapa debe tener un camino disponible desde la posición inicial del jugador hasta la salida y que permita recoger todos los coleccionables.

## Inicialización del renderizado

```c
#include "so_long.h"

void init(t_game *game)
{
    if (!game)
        free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
    game->mlx = mlx_init();
    if (!game->mlx)
        free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
    set_window(game);
    game->window->width = WIDTH;
    game->window->height = HEIGHT;
    set_texture(game);
    load_texture_1(game);
    load_texture_2(game);
    load_texture_3(game);
    load_texture_4(game);
    check_load_texture(game);
    game->window->new = mlx_new_window(game->mlx,
            game->map->col * WIDTH, game->map->row * HEIGHT, "so_long_bonus");
    if (!game->window->new)
        free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
    allocate_player(game);
    render_map(game);
}
```

Deberemos cargar nuestros sprites como archivos `.xpm` y renderizarlos en la ventana.

## Juego

```c
#include "so_long.h"

void play(t_game *game)
{
    if (!game)
        free_exit(EXIT_FAILURE, game, FAIL_ALLOC, NULL);
    mlx_key_hook(game->window->new, handle_keypress, game);
    mlx_hook(game->window->new, CLIC_X, 0, handle_exit, game);
    mlx_loop(game->mlx);
}
```

```c
#include "so_long.h"

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == ESC || keycode == Q)
        free_exit(EXIT_SUCCESS, game, CLOSE_WIN, NULL);
    else if (keycode == UP || keycode == W)
        move_player(game, 0, -1);
    else if (keycode == LEFT || keycode == A)
        move_player(game, -1, 0);
    else if (keycode == DOWN || keycode == S)
        move_player(game, 0, 1);
    else if (keycode == RIGHT || keycode == D)
        move_player(game, 1, 0);
    return (0);
}

void move_player(t_game *game, int col, int row)
{
    int new_x;
    int new_y;

    new_x = ft_abs(game->player->x + col);
    new_y = ft_abs(game->player->y + row);
    if (game->map->matrix[new_y][new_x] == '1')
        return;
    display_moves_count(game);
    if (game->map->matrix[new_y][new_x] == 'B')
        free_exit(EXIT_SUCCESS, game, "You lose", NULL);
    else if ((new_y == game->map->end->y && new_x == game->map->end->x)
        && game->map->count_collec == 0)
        free_exit(EXIT_SUCCESS, game, "Completed", NULL);
    else if (game->map->matrix[new_y][new_x] == 'C')
        update_progress(game);
    if (game->map->matrix[game->player->y][game->player->x] == 'T')
        game->map->matrix[game->player->y][game->player->x] = 'E';
    else
        game->map->matrix[game->player->y][game->player->x] = '0';
    if (game->map->matrix[new_y][new_x] == 'E')
        game->map->matrix[new_y][new_x] = 'T';
    else
        game->map->matrix[new_y][new_x] = 'P';
    update_render_pos(game, game->player->x, game->player->y);
    update_render_pos(game, new_x, new_y);
}
```

Debemos ser capaces de darle movimiento a nuestro personaje principal y renderizar nuevamente el mapa, o los sprites afectados para mejor optimización de recursos.



El programa debe cerrarse limpiamente en los siguientes casos:



\- Al clicar sobre la x de la ventana.

\- Al presionar la tecla \`ESC\`

\- Al entrar en contacto con un enemigo o trampa.

\- Al recoger todos los colecionables e ir a la salida.
