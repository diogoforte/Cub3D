/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:56:04 by chaleira          #+#    #+#             */
/*   Updated: 2024/01/06 03:39:56 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_maps(void);
int check_variables();

int main (int argc, char **argv)
{
	if (argc < 2)
		exit_cub("Usage: ./cub3D <map.cub> ...");
	if (check_variables())
		exit_cub(NULL);
	cub()->map_load(argv);
	// print_maps();
	window_create();
	cub()->exit(NULL);
}

int check_variables(void)
{
	if (WIDTH <= 0 || HEIGHT <= 0)
		return (err("Invalid resolution", NULL));
	if (SCALE <= 1)
		return (err("Invalid scale", NULL));
	return (0);
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
		printf("start_dir: %c\n", tmp_map->start_dir);
		printf("\n");
		tmp_map = tmp_map->next;
	}
}