/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 10:03:00 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/22 12:37:05 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"

int		main(void)
{
	char	*str;

	str = malloc(1);
	malloc(512);
	malloc(512);
	malloc(512);
	malloc(512);
	malloc(512);
	malloc(512);
	malloc(512);
	malloc(1000);
	malloc(5000);
	malloc(5000);
	malloc(512);
	str[0] = '*';
	ft_putchar(str[0]);
	return (0);
}
