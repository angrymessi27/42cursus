/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <askl336622@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:17:06 by cjung             #+#    #+#             */
/*   Updated: 2025/10/18 20:31:38 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*make_unique_ptr(void)
{
	void	*unique_ptr;

	unique_ptr = (void *)malloc(0);
	if (unique_ptr == NULL)
		return (NULL);
	return (unique_ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	size_t		total;

	total = nmemb * size;
	if (total == 0)
		return (make_unique_ptr());
	if (total / size != nmemb)
		return (NULL);
	ptr = (void *) malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
