/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:45:00 by cjung             #+#    #+#             */
/*   Updated: 2026/02/28 21:36:40 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
}

static int	add_to_list(t_list **list, char *buf, int r)
{
	t_list	*new_node;

	buf[r] = '\0';
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = buf;
	new_node->next = *list;
	*list = new_node;
	return (1);
}

static int	read_and_store(int fd, t_list **list)
{
	char	*buf;
	int		r;

	while (!*list || !ft_strchr((*list)->content, '\n'))
	{
		buf = malloc((size_t)BUFFER_SIZE + 1);
		if (!buf)
			return (-1);
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0)
			return (free(buf), r);
		if (!add_to_list(list, buf, r))
			return (free(buf), -1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (1);
}

static char	*get_line_from_list(t_list *list)
{
	int		len;
	char	*line;
	int		i;

	len = get_len(list);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (list)
	{
		len -= ft_strlen(list->content);
		i = 0;
		while (list->content[i])
		{
			line[len + i] = list->content[i];
			i++;
		}
		list = list->next;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;
	int				r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r = read_and_store(fd, &list);
	if (r == -1 || (r == 0 && !list))
	{
		free_list(list);
		list = NULL;
		return (NULL);
	}
	line = get_line_from_list(list);
	free_list(list);
	list = NULL;
	return (line);
}
