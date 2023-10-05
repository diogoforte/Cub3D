/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:49:41 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 06:40:31 by plopes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

typedef struct s_engine	t_engine;
typedef struct s_map	t_map;

struct					s_engine
{
	void				*mlx;
	void				*win;
	t_map				**map;
	void				(*start)(void);
	void				(*free)(t_map *map);
};

struct					s_map
{
	bool				playable;
	int					fd;
	char				*NO;
	char				*SO;
	char				*WE;
	char				*EA;
	char				*F;
	char				*C;
	char				**grid;
	char				**map;
	int					rows;
	int					cols;
	t_map				*next;
};

#endif