/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <askl336622@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:34:31 by cjung             #+#    #+#             */
/*   Updated: 2025/10/24 05:06:52 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	get_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

static size_t	get_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == NULL)
			break ;
		i++;
	}
	if (i == len)
		return (0);
	return (len - i - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	start_idx;
	size_t	end_idx;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start_idx = get_start(s1, set);
	end_idx = get_end(s1, set);
	if (start_idx > end_idx || ft_strlen(s1) == 0)
		return (ft_strdup(""));
	new = (char *)malloc(sizeof(char) * (end_idx - start_idx + 2));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1 + start_idx, end_idx - start_idx + 2);
	return (new);
}
