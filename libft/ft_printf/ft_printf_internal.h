/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:36:18 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/31 08:52:52 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include "ft_printf.h"

int		handle_char(va_list arg);
int		handle_string(va_list arg);
int		handle_pointer(va_list arg);
int		handle_decimal(va_list arg);
int		handle_integer(va_list arg);
int		handle_unsigned(va_list arg);
int		handle_hexadecimal(va_list arg);
int		handle_hexadecimal_upper(va_list arg);
int		handle_format(int format_specifier, va_list arg);
int		handle_unsigned_for_base(
			va_list arg, int base, const char *base_repr
			);
int		handle_percent(int format_specifier);
char	*convert_to_base(unsigned long num, int base, const char *base_repr);

static inline int	safe_add(int *acc, int rv)
{
	if (rv == -1)
		return (-1);
	*acc += rv;
	return (0);
}

#endif
