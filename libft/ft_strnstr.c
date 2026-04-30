/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:56:30 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/17 16:38:11 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size_little;

	if (!*little)
		return ((char *)big);
	i = 0;
	size_little = ft_strlen(little);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] && big[i + j] == little[j] && (i + j) < len)
				j++;
			if (j == size_little)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
