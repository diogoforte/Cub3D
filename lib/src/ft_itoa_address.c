/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:42:52 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/17 17:35:16 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
Description:
	Converts an integer value to a null-terminated string.
Return Value:
	Returns str if the allocation was sucessful, else it returns NULL.	
*/

static int	counter(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size += 1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa_address(char *str, int n)
{
	int			size;
	long int	nb;

	nb = n;
	size = counter(nb);
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		if (nb < 0)
			nb *= -1;
		str[--size] = (nb % 10) + 48;
		nb /= 10;
	}
	if (str[0] == '0')
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	return (str);
}
