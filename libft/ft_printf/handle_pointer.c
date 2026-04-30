/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngusev <ngusev@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:12:38 by ngusev            #+#    #+#             */
/*   Updated: 2025/05/29 18:11:33 by ngusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	handle_pointer(va_list arg)
{
	int				base;
	int				done;
	void			*ptr;
	char			*repr;
	unsigned long	address;

	done = 0;
	base = 16;
	repr = "0123456789abcdef";
	ptr = va_arg(arg, void *);
	address = (unsigned long)ptr;
	if (address == 0)
	{
		if (safe_add(&done, ft_puts("(nil)")) == -1)
			return (-1);
		return (done);
	}
	if (safe_add(&done, ft_puts("0x")) == -1)
		return (-1);
	if (safe_add(&done, ft_puts(convert_to_base(address, base, repr))) == -1)
		return (-1);
	return (done);
}
