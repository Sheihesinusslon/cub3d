/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:24:46 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/31 09:52:13 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puts(const char *str)
{
	int	done;

	done = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		if (ft_putchar(*str++) == -1)
			return (-1);
		done++;
	}
	return (done);
}
