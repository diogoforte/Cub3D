/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:50:33 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/26 13:43:41 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_and_join_threads(pthread_t *threads, t_tdata **data,
		void *(*func)(void *))
{
	int	i;

	i = -1;
	while (++i < THREADS)
	{
		data[i] = tdata(i);
		data[i]->raycast_start = i * THREAD_WIDTH;
		data[i]->raycast_end = (i + 1) * THREAD_WIDTH;
		data[i]->fc_start = i * THREAD_WIDTH;
		data[i]->fc_end = (i + 1) * THREAD_WIDTH;
		pthread_create(&threads[i], NULL, func, data[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(threads[i], NULL);
}

void	draw_fov_threads(void)
{
	pthread_t	threads[THREADS];
	t_tdata		*data[THREADS];

	create_and_join_threads(threads, data, ceiling_floor);
	create_and_join_threads(threads, data, draw_fov);
}

void	*draw_fov(void *arg)
{
	t_tdata	*data;
	int		x;

	data = (t_tdata *)arg;
	x = data->raycast_start - 1;
	check_door(data);
	data->ray.angle = -(FOV / 2) + player()->angle + data->raycast_start
		* ANGLE;
	while (++x < data->raycast_end)
	{
		calculate_distance(data, 0);
		draw_limits(data);
		draw_wall(x, 0, data);
		data->ray.angle += ANGLE;
	}
	return (NULL);
}
