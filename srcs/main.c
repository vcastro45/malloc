/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 10:03:00 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/22 19:35:30 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"

int		main(void)
{
	 void	*ptr = malloc(50);
	ft_putendl("\nfree\n----------------------");
	ft_putendl("void *ptr = malloc(50);\n");
	show_alloc_mem();
	ft_putendl("\nfree(ptr);\n");
	free(ptr);
	show_alloc_mem();
	return (0);
}
