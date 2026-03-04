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
	
	printf("hi\n");
	ft_printf("hi\n");
	
	printf("");
	ft_printf("");
	
	return (0);
}
