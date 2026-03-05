/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <askl336622@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:57:52 by cjung             #+#    #+#             */
/*   Updated: 2026/01/12 18:30:27 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"
int	main(void)
{
	char* str = NULL;
	printf(" NULL %s NULL \n", str);
	ft_printf(" NULL %s NULL \n", str);
	
	printf(" %p         1    %p \n", NULL, NULL);
	ft_printf(" %p         1    %p \n", NULL, NULL);
	
	printf(NULL);
	ft_printf(NULL);
	
	printf("%c\n %s\n %p\n %d\n %i\n %u\n %x\n %X\n %%\n", '\0', "", NULL, 0, 0, 0, 0, 0);
	ft_printf("%c\n %s\n %p\n %d\n %i\n %u\n %x\n %X\n %%\n", '\0', "", NULL, 0, 0, 0, 0, 0);
	
	printf("");
	ft_printf("");
	
	return (0);
}
