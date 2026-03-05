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

static char	*read_to_backup(int fd, char *backup)
{
	char	*buf;
	char	*tmp;
	int		read_bytes;

	if (ft_strchr(backup, '\n'))
		return (backup);
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (free(backup), NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buf), free(backup), NULL);
		buf[read_bytes] = '\0';
		tmp = ft_strjoin(backup, buf);
		free(backup);
		backup = tmp;
		if (!backup || ft_strchr(buf, '\n'))
			break ;
	}
	return (free(buf), backup);
}

static char	*extract_line(char *backup)
{
	char	*line;
	int		i;

	i = 0;
	if (!backup || !backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	line = malloc(i + (backup[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_backup(char *backup)
{
	char	*res;
	int		i;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	res = ft_strdup(backup + i + 1);
	free(backup);
	if (res && !*res)
	{
		free(res);
		res = NULL;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_to_backup(fd, backup);
	if (!backup)
		return (NULL);
	line = extract_line(backup);
	if (!line)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = update_backup(backup);
	return (line);
}
