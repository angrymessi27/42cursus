/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <askl336622@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:23:28 by cjung             #+#    #+#             */
/*   Updated: 2025/10/17 21:04:41 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	int		new;
	size_t	count;

	i = 0;
	new = 1;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			new = 1;
		else
		{
			if (new == 1)
			{
				count++;
				new = 0;
			}
		}
		i++;
	}
	return (count);
}

static char	*str_dup(const char *start, const char *end)
{
	char	*small;
	size_t	len;
	size_t	i;

	i = 0;
	len = end - start;
	small = (char *)malloc(sizeof(char) * (len + 1));
	if (small == NULL)
		return (NULL);
	while (i < len)
	{
		small[i] = start[i];
		i++;
	}
	small[i] = '\0';
	return (small);
}

static	char	**free_all(char **big, size_t big_idx)
{
	while (big_idx-- > 0)
		free(big[big_idx]);
	free(big);
	return (NULL);
}

static char	**fill_big(char const *s, char c, char **big, size_t big_len)
{
	size_t	big_idx;
	size_t	s_idx;
	char	*start;

	big_idx = 0;
	s_idx = 0;
	while (big_idx < big_len)
	{
		while (s[s_idx] != '\0' && s[s_idx] == c)
			s_idx++;
		if (s[s_idx] == '\0')
			break ;
		start = (char *)&s[s_idx];
		while (s[s_idx] != '\0' && s[s_idx] != c)
			s_idx++;
		big[big_idx] = str_dup(start, &s[s_idx]);
		if (big[big_idx] == NULL)
			return (free_all(big, big_idx));
		big_idx++;
	}
	big[big_len] = NULL;
	return (big);
}

char	**ft_split(char const *s, char c)
{
	char	**big;
	size_t	big_len;

	if (s == NULL)
		return (NULL);
	big_len = word_count(s, c);
	big = (char **)malloc(sizeof(char *) * (big_len + 1));
	if (big == NULL)
		return (NULL);
	return (fill_big(s, c, big, big_len));
}
