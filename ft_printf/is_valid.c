/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:17:36 by cjung             #+#    #+#             */
/*   Updated: 2025/12/19 12:11:38 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	is_valid(const char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_str(va_arg(args, char *)));
	else if (c == 'p')
		return (print_ptr(va_arg(args, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (print_dex(va_arg(args, int)));
	else if (c == 'u')
		return (print_unsign(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (print_hex(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (print_char('%'));
	else
		return (0);
}
