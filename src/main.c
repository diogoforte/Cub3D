/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:56:04 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/16 14:28:21 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (int argc, char **argv)
{
	if (argc < 2)
		exit_cub("Usage: ./cub3D <map.cub> ...");
	cub()->map_load(argv);
	window_create();
	cub()->exit(NULL);
}
