/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:56:04 by chaleira          #+#    #+#             */
/*   Updated: 2023/11/02 11:53:44 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_maps(void);

int main (int argc, char **argv)
{
	if (argc < 2)
		exit_cub("Usage: ./cub3D <map.cub> ...");
	cub()->map_load(argv);
	// print_maps();
	window_create();
	cub()->exit(NULL);
}

void print_maps(void)
{
	t_map *tmp_map;

	tmp_map = cub()->maps;
	while (tmp_map)
	{
		tmp_map->print(tmp_map);
		printf("map_width: %d\n", tmp_map->map_width);
		printf("map_height: %d\n", tmp_map->map_height);
		printf("start_x: %d\n", tmp_map->start_x);
		printf("start_y: %d\n", tmp_map->start_y);
		printf("\n");
		tmp_map = tmp_map->next;
	}
}