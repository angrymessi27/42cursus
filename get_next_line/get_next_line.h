/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:45:19 by cjung             #+#    #+#             */
/*   Updated: 2026/02/28 20:45:23 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		found_newline(t_list *list);
t_list	*get_last_node(t_list *list);
char	*catchline(t_list *list);
void	copy_str(t_list *list, char *str);
int		len_to_newline(t_list *list);
void	clean_list(t_list **list);
void	free_list(t_list **list, t_list *clean_node, char *buf);

#endif
