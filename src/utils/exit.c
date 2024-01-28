/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:16:57 by chaleira          #+#    #+#             */
/*   Updated: 2024/01/25 16:09:25 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err(char *str, t_map *map)
{
	if (map)
	{
		free(map->error);
		map->error = ft_strdup(str);
		map->playable = false;
	}
	if (!map)
		ft_dprintf(2, "%s\n", str);
	else
		ft_dprintf(2, "%s -> %s\n", map->map_name, str);
	cub()->status = 1;
	return (1);
}

int	exit_cub(char *str)
{
	int	i;

	i = -1;
	while (++i < 4 && map()->textures[i].img)
		mlx_destroy_image(cub()->window.mlx, map()->textures[i].img);
	i = -1;
	while (++i < 6 && map()->door_texture[i].img)
		mlx_destroy_image(cub()->window.mlx, map()->door_texture[i].img);
	map_destroy(map());
	if (cub()->window.win)
		mlx_destroy_window(cub()->window.mlx, cub()->window.win);
	if (cub()->window.img.img)
		mlx_destroy_image(cub()->window.mlx, cub()->window.img.img);
	if (cub()->window.mlx)
	{
		mlx_destroy_display(cub()->window.mlx);
		free(cub()->window.mlx);
	}
	if (str)
		exit(err(str, NULL));
	else
		exit(cub()->status);
	return (0);
}
