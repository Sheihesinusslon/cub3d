/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:54:41 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/15 19:59:07 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static void	free_all(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*substr(char const *s, size_t start, size_t end)
{
	char	*str;
	size_t	i;

	str = malloc(end - start + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static char	**fill_arr(char const *s, char c, char **arr, size_t wc)
{
	size_t	i;
	size_t	start;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i] && k < wc)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		arr[k] = substr(s, start, i);
		if (!arr[k])
		{
			free_all(arr, k);
			return (NULL);
		}
		k++;
	}
	arr[wc] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = word_count(s, c);
	arr = malloc((wc + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (fill_arr(s, c, arr, wc));
}
