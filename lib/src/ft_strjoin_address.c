/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_address.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 06:18:27 by dinunes-          #+#    #+#             */
/*   Updated: 2024/01/06 05:01:44 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_address(char **original, char *add)
{
	int		i;
	int		j;
	char	*joined;

	if (!original || !(*original) || !add)
		return (NULL);
	joined = ft_calloc(sizeof(char), (ft_strlen((*original)) + ft_strlen(add)
				+ 1));
	if (!joined)
		return (NULL);
	i = -1;
	while ((*original)[++i])
		joined[i] = (*original)[i];
	j = -1;
	while (add[++j])
		joined[i + j] = add[j];
	free((*original));
	*original = joined;
	return (joined);
}
