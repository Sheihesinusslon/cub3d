/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:34:30 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/17 11:29:01 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	ptr_dest = dest;
	ptr_src = src;
	i = 0;
	while (i < n)
	{
		*ptr_dest++ = *ptr_src++;
		i++;
	}
	return (dest);
}
