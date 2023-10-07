/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 06:15:37 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/07 06:16:29 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrixadd_back(char ***matrix, char *str)
{
	char	**new_matrix;
	int		i;

	new_matrix = ft_calloc(sizeof(char *), (ft_matrix_len(*matrix) + 2));
	i = 0;
	while (*matrix && (*matrix)[i])
	{
		new_matrix[i] = (*matrix)[i];
		i++;
	}
	new_matrix[i] = str;
	if (*matrix)
		free(*matrix);
	*matrix = new_matrix;
}
