/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:08:55 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/22 15:41:07 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"

size_t	print_env(t_block *ptr)
{
	size_t	size;
	t_block	*tmp;
	t_block *start;

	size = 0;
	start = ptr;
	tmp = ptr;
	while (ptr != NULL)
	{
		if (ptr->prev != NULL && ptr->isfirst) // BUG PRON
			return (print_env(ptr));
		tmp = ptr;
		ptr = ptr->next;
	}
	ft_print_addr(start);
	ft_putstr(" - ");
	if (tmp != NULL)
	{
		ft_print_addr((void*)((unsigned long long int)tmp +
		(unsigned long long int)(tmp->size)));
		size = (unsigned long long int)tmp - (unsigned long long int)start;
	}
	else
		ft_print_addr(tmp);
	ft_putstr(" : ");
	ft_putnbr(size);
	ft_putstr(" octets");
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
	ft_putstr("\nSMALL : ");
	ft_print_addr(g_env.small);
	ft_putchar('\n');
	total += print_env(g_env.small);
	ft_putstr("\nLARGE : ");
	ft_print_addr(g_env.large);
	ft_putchar('\n');
	total += print_env(g_env.large);
	ft_putstr("\nTotal : ");
	ft_putnbr(total);
	ft_putendl(" octets");
}