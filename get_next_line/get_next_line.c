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

static void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = buf;
	new_node->next = NULL;
	if (!*list)
	{
		*list = new_node;
		return ;
	}
	last = get_last_node(*list);
	last->next = new_node;
}

static void	read_and_store(int fd, t_list **list)
{
	char	*buf;
	int		r;

	while (!found_newline(*list))
	{
		buf = malloc((size_t)BUFFER_SIZE + 1);
		if (!buf)
			return ;
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0)
		{
			free(buf);
			return ;
		}
		buf[r] = '\0';
		append(list, buf);
	}
}

char	*catchline(t_list *list)
{
	int		len;
	char	*line;

	if (!list)
		return (NULL);
	len = len_to_newline(list);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	copy_str(list, line);
	return (line);
}

static void	extract_leftover(t_list *last, t_list *clean_node)
{
	int	i;
	int	k;

	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	k = 0;
	while (last->content[i])
		clean_node->content[k++] = last->content[i++];
	clean_node->content[k] = '\0';
}

void	clean_list(t_list **list)
{
	t_list	*clean_node;

	clean_node = malloc(sizeof(t_list));
	if (!*list || !clean_node)
		return ;
	clean_node->next = NULL;
	clean_node->content = malloc(BUFFER_SIZE + 1);
	if (!clean_node->content)
	{
		free(clean_node);
		return ;
	}
	extract_leftover(get_last_node(*list), clean_node);
	free_list(list, clean_node, NULL);
	if ((*list)->content[0] == '\0')
		free_list(list, NULL, NULL);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		free_list(&list, NULL, NULL);
		return (NULL);
	}
	read_and_store(fd, &list);
	if (!list)
		return (NULL);
	line = catchline(list);
	clean_list(&list);
	if (line && line[0] == '\0')
	{
		free_list(&list, NULL, NULL);
		free(line);
		return (NULL);
	}
	return (line);
}
