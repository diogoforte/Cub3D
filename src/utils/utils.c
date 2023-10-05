/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:05:33 by plopes-c          #+#    #+#             */
/*   Updated: 2023/10/05 20:06:02 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_vars(t_map *map)
{
	printf("\nMap number: %d\n", map->map_number);
	printf("NO: (%s)\n", map->cords[NO]);
	printf("SO: (%s)\n", map->cords[SO]);
	printf("WE: (%s)\n", map->cords[WE]);
	printf("EA: (%s)\n", map->cords[EA]);
	printf("F: (%s)\n", map->cords[F]);
	printf("C: (%s)\n", map->cords[C]);
	printf("Map: \n");
	for (int i = 0; map->map[i]; i++)
		printf("%s\n", map->map[i]);
}

void    *ft_realloc(void *ptr, size_t nitems, size_t size)
{
    void    *new_ptr;

    if (!ptr)
        return (ft_calloc(nitems * size + 1, size));
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
