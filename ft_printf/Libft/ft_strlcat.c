/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <askl336622@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:39:15 by cjung             #+#    #+#             */
/*   Updated: 2025/10/17 21:05:52 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	dst_end;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	dst_end = dst_len;
	if (dst_len >= size)
		return (size + src_len);
	else
	{
		while (src[i] != '\0' && i + dst_len + 1 < size)
		{
			dst[dst_end] = src[i];
			dst_end++;
			i++;
		}
		dst[dst_end] = '\0';
		return (dst_len + src_len);
	}
}
