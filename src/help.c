/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:39:46 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 04:20:10 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	help_message(int instance)
{
	if (instance == 1)
		ft_dprintf(2, "Usage: ./cub3D <map.cub> ...\n");
	else if (instance == 2)
		ft_dprintf(2, "Error: Invalid file.\n");
	else if (instance == 3)
		ft_dprintf(2, "Error: Invalid file extension.\n");
	else if (instance == 4)
		ft_dprintf(2, "Error: Invalid map.\n");
	else if (instance == 5)
		ft_dprintf(2, "Error: Invalid resolution.\n");
	else if (instance == 6)
		ft_dprintf(2, "Error: Invalid texture.\n");
	else if (instance == 7)
		ft_dprintf(2, "Error: Invalid color.\n");
	else if (instance == 8)
		ft_dprintf(2, "Error: Invalid player.\n");
	return (1);
}

void	print_vars(void)
{
	printf("NO: (%s)\n", engine()->map->NO);
	printf("SO: (%s)\n", engine()->map->SO);
	printf("WE: (%s)\n", engine()->map->WE);
	printf("EA: (%s)\n", engine()->map->EA);
	printf("F: (%s)\n", engine()->map->F);
	printf("C: (%s)\n", engine()->map->C);
	for (int i = 0; engine()->map->grid[i]; i++)
		printf("%s", engine()->map->grid[i]);
}
