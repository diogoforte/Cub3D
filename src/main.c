/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:56:04 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/07 00:33:16 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (int argc, char **argv)
{
	if (argc < 2)
		exit_cub("Usage: ./cub3D <map.cub> ...");
	cub()->load_all_maps(argv);
	for (t_map *map = cub()->map; map; map = map->next)
		print_matrix(map->file);
	cub()->exit(NULL);
}
