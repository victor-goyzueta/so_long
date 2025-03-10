/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:52:43 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/25 21:53:52 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int x)
{
	if (x < 0)
	{
		if (x == INT_MIN)
			return (INT_MAX);
		return (-x);
	}
	else
		return (x);
}
