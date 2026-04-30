/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:12:38 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/27 18:03:17 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	handle_char(va_list arg)
{
	unsigned int	i;
	int				done;

	i = va_arg(arg, int);
	done = ft_putchar(i);
	if (done == -1)
		return (-1);
	return (done);
}
