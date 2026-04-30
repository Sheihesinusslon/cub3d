/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:28:14 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/29 19:06:40 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

char	*convert_to_base(unsigned long num, int base, const char *base_repr)
{
	static char	buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	*--ptr = base_repr[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = base_repr[num % base];
		num /= base;
	}
	return (ptr);
}

int	handle_unsigned_for_base(va_list arg, int base, const char *base_repr)
{
	unsigned int		i;
	int					done;

	done = 0;
	i = va_arg(arg, unsigned int);
	if (
		safe_add(
			&done,
			ft_puts(convert_to_base(i, base, base_repr))
		) == -1)
		return (-1);
	return (done);
}

int	handle_format(int format_specifier, va_list arg)
{
	if (format_specifier == 'c')
		return (handle_char(arg));
	if (format_specifier == 's')
		return (handle_string(arg));
	if (format_specifier == 'p')
		return (handle_pointer(arg));
	if (format_specifier == 'd')
		return (handle_decimal(arg));
	if (format_specifier == 'i')
		return (handle_integer(arg));
	if (format_specifier == 'u')
		return (handle_unsigned(arg));
	if (format_specifier == 'x')
		return (handle_hexadecimal(arg));
	if (format_specifier == 'X')
		return (handle_hexadecimal_upper(arg));
	return (handle_percent(format_specifier));
}
