/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:07:52 by plopes-c          #+#    #+#             */
/*   Updated: 2023/10/05 07:12:00 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	int	i;
	
	i = 0;
	while (engine()->map && engine()->map[i])
	{
		engine()->free(engine()->map[i]);
		free(engine()->map[i]);
		i++;
	}
	if (engine()->map)
		free(engine()->map);
	if (str)
		exit(err(str, NULL));
	else
		exit(0);
}
