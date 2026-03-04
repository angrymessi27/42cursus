/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:18:31 by cjung             #+#    #+#             */
/*   Updated: 2025/12/19 12:15:11 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdlib.h>

int	print_dex(int num)
{
	int		temp;
	int		len;
	char	*str;

	temp = num;
	str = ft_itoa(temp);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
