/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:27:48 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/31 08:51:58 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	handle_percent(int format_specifier)
{
	int	done;

	done = 0;
	if (safe_add(&done, ft_putchar(format_specifier)) == -1)
		return (-1);
	return (done);
}
