/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:00:30 by plopes-c          #+#    #+#             */
/*   Updated: 2023/10/06 21:59:35 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	matrix_biggest_string(char **str)
{
	int i;
	int j;
	int biggest;

	i = 0;
	biggest = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		if (j > biggest)
			biggest = j;
		i++;
	}
	return (biggest);
}

int ft_matrix_len(char **str)
{
	int i;

	i = 0;
	HERE;
	while (str && str[i])
		i++;
	THERE;
	return (i);
}

char ***arr_type(t_map	*map)
{
	static char **arr_type[6];

	arr_type[0] = &map->cords[NO];
	arr_type[1] = &map->cords[SO];
	arr_type[2] = &map->cords[WE];
	arr_type[3] = &map->cords[EA];
	arr_type[4] = &map->cords[F];
	arr_type[5] = &map->cords[C];
	return (arr_type);
}
int all_filled(t_map *map)
{
	char ***arr_type2;
	int i;

	i = 0;
	arr_type2 = arr_type(map);
	while (i < 6)
	{
		if (!*arr_type2[i])
			return (1);
		i++;
	}
	return (0);
}
