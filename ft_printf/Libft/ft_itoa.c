/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <askl336622@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:11:07 by cjung             #+#    #+#             */
/*   Updated: 2025/10/17 20:47:27 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned int	len_int(long int n)
{
	unsigned int	len;

	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*fill_itoa(long int n, unsigned int len, char *itoa)
{
	unsigned int	i;
	unsigned int	loop;

	i = 0;
	loop = len;
	if (n < 0)
	{
		itoa[0] = '-';
		n = n * -1;
		loop = len - 1;
	}
	while (loop > i)
	{
		itoa[len - i - 1] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	itoa[len] = '\0';
	return (itoa);
}

char	*ft_itoa(int n)
{	
	char			*itoa;
	unsigned int	len;

	len = len_int(n);
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (itoa == NULL)
		return (NULL);
	return (fill_itoa(n, len, itoa));
}
