/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:06:05 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/15 19:59:56 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	tmp;
	char	*ptr;

	tmp = 0;
	while (s[tmp])
		tmp++;
	ptr = (char *)malloc((tmp + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	tmp = 0;
	while (s[tmp])
	{
		ptr[tmp] = s[tmp];
		tmp++;
	}
	ptr[tmp] = '\0';
	return (ptr);
}
