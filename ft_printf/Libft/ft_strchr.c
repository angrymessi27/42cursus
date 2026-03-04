/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <askl336622@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:12:29 by cjung             #+#    #+#             */
/*   Updated: 2025/10/18 20:42:39 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*found;

	i = 0;
	found = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			found = (char *)&s[i];
			return (found);
		}
		i++;
	}
	if ((char)c == '\0')
		found = (char *)&s[i];
	return (found);
}
