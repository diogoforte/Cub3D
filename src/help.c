/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:39:46 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/04 01:20:16 by dinunes-         ###   ########.fr       */
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
