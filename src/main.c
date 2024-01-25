/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:56:04 by chaleira          #+#    #+#             */
/*   Updated: 2024/01/25 19:58:43 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_cub("Usage: ./cub3D <map.cub> ...");
	if (WIDTH <= 0 || HEIGHT <= 0 || SCALE <= 1)
		exit_cub(NULL);
	cub()->map_load(argv);
	window_create();
}
