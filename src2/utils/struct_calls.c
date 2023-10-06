/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaleira <chaleira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:04:19 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/06 23:21:55 by chaleira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d2.h"

t_cub	*cub(void)
{
	static t_cub cub;

	cub.map_add_list = &map_add_list;
	cub.map_new = &map_new;
	cub.load_all_maps = &load_all_maps;
	cub.exit = &exit_cub;
	cub.maps_destroy = &maps_destroy;
	return (&cub);
}
