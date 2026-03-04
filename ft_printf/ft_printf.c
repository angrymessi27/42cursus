/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:12:13 by cjung             #+#    #+#             */
/*   Updated: 2026/02/24 13:31:12 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	printing(const char *str, va_list args)
{
	int	total;
	int	result;
	int	i;

	total = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			result = is_valid(str[++i], args);
		else
			result = print_char(str[i]);
		if (result == -1 || total > 2147483647 - result)
			return (-1);
		total += result;
		i++;
	}
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	if (!str)
		return (-1);
	va_start(args, str);
	len = printing(str, args);
	va_end(args);
	return (len);
}
