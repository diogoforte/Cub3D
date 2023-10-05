/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 02:01:32 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/05 04:49:29 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_realloc(void *ptr, size_t nitems, size_t size)
{
    void    *new_ptr;

    if (!ptr)
        return (ft_calloc(nitems * size, size));
    if (nitems == 0)
    {
        free(ptr);
        return (NULL);
    }
    new_ptr = ft_calloc(nitems * size, size);
    if (!new_ptr)
        return (NULL);
    ft_memmove(new_ptr, ptr, nitems * size);
    free(ptr);
    return (new_ptr);
}
