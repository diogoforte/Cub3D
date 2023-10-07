/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixadd_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:14:41 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/07 13:17:33 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrixadd_front(char ***matrix, char *str)
{
	int	rows;

	rows = 0;
	while ((*matrix)[rows])
		rows++;
	*matrix = ft_realloc(*matrix, rows + 2, sizeof(char *));
	ft_memmove((*matrix) + 1, (*matrix), (rows + 1) * sizeof(char *));
	(*matrix)[0] = ft_strdup(str);
}
