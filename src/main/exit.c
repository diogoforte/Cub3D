/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:06:48 by plopes-c          #+#    #+#             */
/*   Updated: 2023/10/06 03:21:35 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err(char *str, t_map *map)
{
	if (map)
		map->playable = false;
	while (str && *str)
		write(2, str++, 1);
	write(2, "\n", 1);
	return (1);
}

void	do_exit(char *str)
{
	int		i;

	i = 0;
	while (engine()->map && engine()->map[i])
	{
		engine_free(engine()->map[i]);
		free(engine()->map[i]);
		i++;
	}
	free(engine()->map);
	if (str)
		exit(err(str, NULL));
	else
		exit(0);
}
