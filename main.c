/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:03:19 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/16 15:45:23 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int main(void)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(str) * 10);
	while (i < 9)
		str[i++] = 'a';
	str[i] = '\0';
	ft_putendl(str);

	i = 0;
	str = (char*)malloc(sizeof(str) * 10);
	while (i < 9)
		str[i++] = 'a';
	str[i] = '\0';
	ft_putendl(str);

	return (0);
}
