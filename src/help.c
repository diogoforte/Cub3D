/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:39:46 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 06:30:28 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_vars(t_map *map)
{
	printf("NO: (%s)\n", map->NO);
	printf("SO: (%s)\n", map->SO);
	printf("WE: (%s)\n", map->WE);
	printf("EA: (%s)\n", map->EA);
	printf("F: (%s)\n", map->F);
	printf("C: (%s)\n", map->C);
	printf("Map:\n");
	for (int i = 0; map->map[i]; i++)
		printf("%s\n", map->map[i]);
	// printf("\nGrid:\n");
	// for (int i = 0; map->grid[i]; i++)
	// 	printf("%s", map->grid[i]);
}
void    *ft_realloc(void *ptr, size_t nitems, size_t size)
{
    void    *new_ptr;

    if (!ptr)
        return (ft_calloc(nitems * size, size));
    if (nitems == 0)
    {
        free(ptr);
        return (NULL);
    }
    new_ptr = ft_calloc(nitems * size, size);
    if (!new_ptr)
        return (NULL);
    ft_memmove(new_ptr, ptr, nitems * size);
    free(ptr);
    return (new_ptr);
}

char ***arr_type(t_map	*map)
{
	static char **arr_type[6];

	arr_type[0] = &map->NO;
	arr_type[1] = &map->SO;
	arr_type[2] = &map->WE;
	arr_type[3] = &map->EA;
	arr_type[4] = &map->F;
	arr_type[5] = &map->C;
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
