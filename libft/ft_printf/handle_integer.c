/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:12:38 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/27 19:00:55 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include "limits.h"

static int	handle_int_min(int *done, int i)
{
	int	res;

	if (i == INT_MIN)
	{
		res = ft_puts("-2147483648");
		if (*done == -1)
			return (-1);
		*done += res;
		return (1);
	}
	return (0);
}

int	handle_integer(va_list arg)
{
	int			i;
	int			done;
	const char	*digits;

	done = 0;
	digits = "0123456789";
	i = va_arg(arg, int);
	if (i < 0)
	{
		if (handle_int_min(&done, i))
			return (done);
		if (safe_add(&done, ft_putchar('-')) == -1)
			return (01);
		i = -i;
	}
	if (safe_add(&done, ft_puts(convert_to_base(i, 10, digits))) == -1)
		return (-1);
	return (done);
}
