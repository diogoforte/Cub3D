/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lseek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinunes- <dinunes-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:43:53 by dinunes-          #+#    #+#             */
/*   Updated: 2023/10/04 21:46:21 by dinunes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

off_t	ft_lseek(int fd, off_t offset, int whence)
{
    off_t	new_offset;

    new_offset = -1;
    if (whence == SEEK_SET)
        new_offset = offset;
    else if (whence == SEEK_CUR)
        new_offset = lseek(fd, 0, SEEK_CUR) + offset;
    else if (whence == SEEK_END)
        new_offset = lseek(fd, 0, SEEK_END) + offset;
    if (new_offset >= 0)
        lseek(fd, new_offset, SEEK_SET);
    return (new_offset);
}