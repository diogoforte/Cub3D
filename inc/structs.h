/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:49:41 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 00:52:08 by dinunes-         ###   ########.fr       */
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
	bool				playable;
	int					fd;
	char				*NO;
	char				*SO;
	char				*WE;
	char				*EA;
	char				*F;
	char				*C;
	char				**grid;
	int					rows;
	int					cols;
	t_map				*next;
};

#endif