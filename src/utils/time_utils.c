/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:48:52 by plopes-c          #+#    #+#             */
/*   Updated: 2024/01/17 18:49:00 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool has_passed_x_seconds(double time_in_secs)
{
    static clock_t start_time;
    clock_t current_time;
    double elapsed_time;

	current_time = clock();
	elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
    if (start_time == 0) {
        start_time = clock();
        return 0;
    }
    if (elapsed_time >= time_in_secs)
	{
        start_time = 0;
        return 1;
    }
	else
        return 0;
}
