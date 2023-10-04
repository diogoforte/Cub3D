/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:49:41 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/04 01:19:43 by dinunes-         ###   ########.fr       */
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
	t_map				*map;
	void				(*start)(void);
	void				(*free)(void);
};

struct					s_map
{
	int					fd;
	char				*line;
	char				**grid;
	bool				playable;
	t_map				*next;
};

#endif