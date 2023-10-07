/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:16:57 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/07 02:04:48 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err(char *str)
{
	while (str && *str)
		write(2, str++, 1);
	write(2, "\n", 1);
	cub()->status = 1;
	return (1);
}

void	exit_cub(char *str)
{
	cub()->maps_destroy();
	if (str)
		exit(err(str));
	else
		exit(cub()->status);
}

void	maps_destroy(void)
{
	t_map	*tmp;
	t_map	**map;
	int i = -1;
	
	map = &cub()->map;
	while (*map)
	{
		tmp = (*map)->next;
		if ((*map)->file)
			ft_freematrix((*map)->file);
		if ((*map)->map)
			ft_freematrix((*map)->map);
		while ((*map)->cords[++i])
			free((*map)->cords[i]);
		if (*map)
			free(*map);
		*map = tmp;
	}
	*map = NULL;
}
