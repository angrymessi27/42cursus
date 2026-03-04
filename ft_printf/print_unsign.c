/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:18:41 by cjung             #+#    #+#             */
/*   Updated: 2025/12/19 11:03:34 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_unsign(unsigned int num)
{
	int		len;
	char	c;

	len = 0;
	if (num > 9)
	{
		len = print_unsign(num / 10);
		if (len == -1)
			return (-1);
	}
	c = (num % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}
