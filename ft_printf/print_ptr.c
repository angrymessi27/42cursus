/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:17:10 by cjung             #+#    #+#             */
/*   Updated: 2026/02/23 15:09:29 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	putptr(unsigned long long ptr, long long *len)
{
	int		is_write;
	char	c;

	if (*len == -1)
		return ;
	if (ptr >= 16)
	{
		putptr(ptr / 16, len);
		putptr(ptr % 16, len);
	}
	else
	{
		if (ptr < 10)
			c = '0' + ptr;
		else
			c = ptr - 10 + 'a';
		is_write = write(1, &c, 1);
		if (is_write == -1)
			*len = -1;
		else
			*len += 1;
	}
}

int	print_ptr(unsigned long long ptr)
{
	long long	len;
	int			head;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = 0;
	head = write(1, "0x", 2);
	if (head == -1)
		return (-1);
	else
		len += head;
	putptr(ptr, &len);
	return (len);
}
