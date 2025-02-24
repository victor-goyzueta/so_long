#include "so_long.h"

void	fd_free_exit(int fd, t_game *game, char *error, char **cur)
{
	close(fd);
	free_exit(EXIT_FAILURE, game, error, cur);
}
