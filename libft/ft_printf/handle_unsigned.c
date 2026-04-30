/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:12:38 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/27 19:42:54 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	handle_unsigned(va_list arg)
{
	const char	*repr;
	int			base;

	base = 10;
	repr = "0123456789";
	return (handle_unsigned_for_base(arg, base, repr));
}
