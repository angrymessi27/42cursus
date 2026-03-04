/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:18:49 by cjung             #+#    #+#             */
/*   Updated: 2025/12/19 11:03:12 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_hex(unsigned int num, char type)
{
	static char	lower_hex[16] = "0123456789abcdef";
	static char	upper_hex[16] = "0123456789ABCDEF";
	int			len;
	char		c;
	char		*base;

	len = 0;
	if (type == 'x')
		base = lower_hex;
	else
		base = upper_hex;
	if (num > 15)
	{
		len = print_hex(num / 16, type);
		if (len == -1)
			return (-1);
	}
	c = base[num % 16];
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}
