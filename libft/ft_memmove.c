/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:50:09 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/17 14:06:56 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	if (dest == src || n == 0)
		return (dest);
	if (ptr_dest < ptr_src || ptr_dest >= ptr_src + n)
	{
		i = -1;
		while (++i < n)
			ptr_dest[i] = ptr_src[i];
	}
	else
	{
		i = n;
		while (i-- > 0)
			ptr_dest[i] = ptr_src[i];
	}
	return (dest);
}
