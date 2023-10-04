/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetensor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:02:09 by dinunes-          #+#    #+#             */
/*   Updated: 2023/08/28 20:22:21 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_freetensor(char ***tensor)
{
	int	i;
	int	j;

	i = -1;
	if (tensor)
	{
		while (tensor[++i] != NULL)
		{
			j = -1;
			while (tensor[i][++j] != NULL)
				free(tensor[i][j]);
			free(tensor[i]);
		}
		free(tensor);
	}
}
