/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:34:15 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/13 06:42:56 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_arrays(int count, ...)
{
	va_list		args;
	char		*ptr;
	int			i;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		ptr = va_arg(args, char *);
		if (ptr)
			free(ptr);
		i++;
	}
	va_end(args);
}

void	free_array(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_list(t_list **stack)
{
	t_list	*tmp;

	tmp = NULL;
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		*stack = tmp;
	}
}

static void	free_all(t_list **stack, char **arr)
{
	free_list(stack);
	free_array(arr);
}

void	ft_exit_free(int EXIT, t_list **stack, char **arr)
{
	free_all(stack, arr);
	if (EXIT == EXIT_FAILURE)
		ft_perror(NULL);
	else
		exit(EXIT);
}
