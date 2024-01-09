/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:56:04 by chaleira          #+#    #+#             */
/*   Updated: 2024/01/09 10:49:51 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_variables(void);

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit_cub("Usage: ./cub3D <map.cub> ...");
	if (check_variables())
		exit_cub(NULL);
	cub()->map_load(argv);
	window_create();
	cub()->exit(NULL);
}

int	check_variables(void)
{
	if (WIDTH <= 0 || HEIGHT <= 0)
		return (err("Invalid resolution", NULL));
	if (SCALE <= 1)
		return (err("Invalid scale", NULL));
	return (0);
}
