/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:08:55 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/22 19:28:03 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"

size_t	print_block_range(t_block *ptr)
{
	size_t	size;
	t_block	*start;

	size = 0;
	start = ptr;
	ft_print_addr(ptr);
	ft_putstr(" - ");
	if (ptr == NULL)
	{
		ft_print_addr(ptr);
		return (size);
	}
	while (ptr->next != NULL && ptr->next->isfirst == false)
		ptr = ptr->next;
	ft_print_addr(ptr);
	size = (unsigned long long int)ptr - (unsigned long long int)start;
	ft_putstr(" : ");
	ft_putnbr(size);
	ft_putendl(" octets");
	return (size);
}

size_t	print_env(t_block *ptr)
{
	size_t	size;

	size = 0;
	while (ptr != NULL)
	{
		if (ptr->isfirst)
			size += print_block_range(ptr);
		ptr = ptr->next;
	}
	return (size);
}

void	show_alloc_mem(void)
{
	size_t	total;
	
	total = 0;
	ft_putstr("TINY : ");
	ft_print_addr(g_env.tiny);
	ft_putchar('\n');
	total += print_env(g_env.tiny);
	ft_putstr("SMALL : ");
	ft_print_addr(g_env.small);
	ft_putchar('\n');
	total += print_env(g_env.small);
	ft_putstr("LARGE : ");
	ft_print_addr(g_env.large);
	ft_putchar('\n');
	total += print_env(g_env.large);
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putendl(" octets");
}