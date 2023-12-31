/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:02:12 by chaleira          #+#    #+#             */
/*   Updated: 2024/01/05 06:58:28 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int stoi(double nb)
{
	return (nb / SCALE);
}

double itos(int nb)
{
	return (nb * SCALE);
}

void	print_matrix(char **matrix)
{
	if (!matrix)
	{
		printf("Can't print matrix\n");
		return ;	
	}
	while (*matrix)
	{
		printf("%s\n", *matrix);
		matrix++;
	}
}
