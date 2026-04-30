/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:50:05 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/31 09:41:55 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	handle_string(va_list arg)
{
	char	*s;
	int		done;

	s = va_arg(arg, char *);
	done = ft_puts(s);
	if (done == -1)
		return (-1);
	return (done);
}
