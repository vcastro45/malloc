/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 12:47:57 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/22 12:48:17 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"

void	debug_print_current_alloc(t_block *lnk)
{
	ft_putendl("new malloc:");
	ft_putstr("  - ");
	ft_print_addr(lnk);
	ft_putstr("\n  - isfree: ");
	ft_putnbr(lnk->isfree);
	ft_putstr("\n  - size: ");
	ft_putnbr(lnk->size);
	ft_putendl("\nnext addr: ");
	ft_putstr("  - ");
	ft_print_addr(lnk->next);
	ft_putstr("\n  - isfree: ");
	ft_putnbr(lnk->next->isfree);
	ft_putstr("\n  - size: ");
	ft_putnbr(lnk->next->size);
	ft_putendl("\n*--------------------*");
}