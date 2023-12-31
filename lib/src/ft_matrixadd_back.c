/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 06:15:37 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/07 15:27:47 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrixadd_back(char ***matrix, char *str)
{
	int	len;

	len = ft_matrix_len(*matrix);
	*matrix = ft_realloc(*matrix, len + 2, sizeof(char *));
	(*matrix)[len] = ft_strdup(str);
	(*matrix)[len + 1] = NULL;
}
