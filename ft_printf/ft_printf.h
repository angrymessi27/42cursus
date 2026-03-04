/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:46:37 by cjung             #+#    #+#             */
/*   Updated: 2025/12/19 12:33:21 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int	ft_printf(const char *str, ...);
int	is_valid(const char c, va_list args);
int	print_char(int c);
int	print_dex(int num);
int	print_hex(unsigned int num, char type);
int	print_ptr(unsigned long long ptr);
int	print_str(char *s);
int	print_unsign(unsigned int num);

#endif
