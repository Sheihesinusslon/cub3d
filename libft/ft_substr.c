/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:55:17 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/17 12:05:49 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alloc_empty(void)
{
	char	*empty;

	empty = (char *)malloc(1);
	if (!empty)
		return (NULL);
	*empty = '\0';
	return (empty);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	char			*substr;

	i = 0;
	while (s[i] && i != start)
		i++;
	if (i != start)
		return (ft_alloc_empty());
	while (s[i] && len)
	{
		i++;
		len--;
	}
	size = i - start;
	substr = (char *)malloc((size + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	j = 0;
	while (start != i)
		substr[j++] = s[start++];
	substr[j] = '\0';
	return (substr);
}
