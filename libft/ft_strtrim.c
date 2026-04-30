/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:26:33 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/17 12:06:42 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ltrim(char const *s1, char const *set)
{
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	return ((char *)s1);
}

static char	*rtrim(char const *s1, char const *set)
{
	char	*end;

	end = (char *)s1 + ft_strlen(s1) - 1;
	while (end != s1 && ft_strchr(set, *end))
		end--;
	return (end);
}

static char	*ft_alloc_empty(void)
{
	char	*empty;

	empty = (char *)malloc(1);
	if (!empty)
		return (NULL);
	*empty = '\0';
	return (empty);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*b;
	char	*e;
	char	*new;
	char	*tmp;
	size_t	size;

	b = ltrim(s1, set);
	e = rtrim(s1, set);
	if (e < b)
		return (ft_alloc_empty());
	size = e - b + 1;
	new = (char *)malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	tmp = new;
	while (b <= e)
		*tmp++ = *b++;
	*tmp = '\0';
	return (new);
}
