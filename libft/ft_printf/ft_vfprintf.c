/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:46:34 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/31 08:52:26 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_internal.h"

static int	handle_format_specifier(char format, va_list arg, int *done)
{
	int	tmp;

	tmp = handle_format(format, arg);
	if (tmp == -1)
		return (-1);
	*done += tmp;
	return (1);
}

static int	is_valid_format_specifier(char format)
{
	return (format == 'c' || format == 's' || format == 'i' || format == 'd'
		|| format == 'u' || format == 'p' || format == 'x' || format == 'X'
		|| format == '%'
	);
}

static int	process_format_specifier(const char *format, va_list arg, int *done)
{
	if (is_valid_format_specifier(*format))
	{
		if (handle_format_specifier(*format, arg, done) == -1)
			return (-1);
	}
	else
	{
		if (handle_format_specifier('%', arg, done) == -1)
			return (-1);
	}
	return (1);
}

int	ft_vfprintf(const char *format, va_list arg)
{
	int	done;

	done = 0;
	while (*format != '\0')
	{
		if (*format != '%')
		{
			if (ft_putchar(*format++) == -1)
				return (-1);
			done++;
			continue ;
		}
		format++;
		if (*format == '\0')
			return (-1);
		if (process_format_specifier(format, arg, &done) == -1)
			return (-1);
		format++;
	}
	return (done);
}
