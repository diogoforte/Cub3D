/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:02:12 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/07 05:05:51 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	matrix_add_back(char ***matrix, char *str)
{
	char **new_matrix;
	int i;
	
	new_matrix = ft_calloc(sizeof(char *), (ft_matrix_len(*matrix) + 2));
	i = 0;
	while (*matrix && (*matrix)[i])
	{
		new_matrix[i] = (*matrix)[i];
		i++;
	}
	new_matrix[i] = str;
	if (*matrix)
		free(*matrix);
	*matrix = new_matrix;
}

void	print_matrix(char **matrix)
{
	while (matrix && *matrix)
	{
		printf("%s", *matrix);
		matrix++;
	}
}

void	map_add_back(t_map **map, t_map *new_map)
{
	t_map *last;

	if (!map || !new_map)
		return ;
	if (!*map)
	{
		*map = new_map;
		return ;
	}
	last = *map;
	while (last->next)
		last = last->next;
	last->next = new_map;
}

char	*ft_stradd(char **original, char *add)
{
	int		i;
	int		j;
	char	*joined;

	if (!original || !(*original) || !add)
		return (NULL);
	joined = ft_calloc(sizeof(char),
			(ft_strlen((*original)) + ft_strlen(add) + 1));
	if (!joined)
		return (NULL);
	i = -1;
	while ((*original)[++i])
		joined[i] = (*original)[i];
	j = -1;
	while (add[++j])
		joined[i + j] = add[j];
	free((*original));
	*original = joined;
	return (joined);
}
