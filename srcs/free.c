/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 13:00:02 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/22 15:19:48 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"

bool	joinblock(t_block *ptr)
{
	ptr->isfree = true;
	if (ptr->next != NULL && ptr->next->isfree)
	{
		ptr->size += ptr->next->size;
		ptr->next = ptr->next->next;
	}
	if (ptr->prev != NULL && ptr->prev->isfree)
	{
		ptr->prev->size += ptr->size;
		ptr->prev->next = ptr;
		ptr = ptr->prev;
	}
	if (ptr->prev != NULL && ptr->isfirst)
		if (ptr->next == NULL || ptr->next->isfirst)
		{
			if (ptr->prev != NULL)
				ptr->prev->next = ptr->next;
			if (ptr->next != NULL)
				ptr->next->prev = ptr->prev;
			return (munmap(ptr, ptr->size) == 0);
		}
	return (true);
}

void	free(void *ptr)
{
	// if (ptr == NULL)
	// 	return ;
	// ft_putstr("addr: ");
	// ft_print_addr(ptr);
	// ft_putchar('\n');
	// ft_putstr("ptr->prev->size: ");
	// if (((t_block*)(ptr))->prev == NULL)
	// 	ft_putstr("ptr->prev == NULL");
	// else
	// 	ft_putnbr(((t_block*)(ptr))->prev->size);
	joinblock(ptr);
	// ft_putstr("\n\n");
}
