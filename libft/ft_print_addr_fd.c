/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:08:16 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/21 14:10:09 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_nb(unsigned long long int nb, int fd)
{
	unsigned long long int	mem;

	if (nb == 0)
	{
		ft_putstr_fd("0x", fd);
		return ;
	}
	mem = nb % 16;
	print_nb(nb / 16, fd);
	if (mem < 10)
		ft_putchar_fd(mem + '0', fd);
	else
	{
		mem -= 10;
		ft_putchar_fd(mem + 'a', fd);
	}
}

void			ft_print_addr_fd(void *addr, int fd)
{
	unsigned long long int		val_addr;

	val_addr = (unsigned long long int)addr;
	if (val_addr == 0)
		ft_putstr_fd("0x0", fd);
	else
		print_nb(val_addr, fd);
}