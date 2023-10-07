/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:04:19 by chaleira          #+#    #+#             */
/*   Updated: 2023/10/07 21:08:16 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub	*cub(void)
{
	static t_cub cub = {
		NULL,
		0,
		map_add_list,
		map_load,
		exit_cub,
		maps_destroy,
		map_new,
		NULL,
		{}
	};

	return (&cub);
}
