/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:48:30 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/07 14:12:18 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int val, int base)
{
	int		i;
	char	*str;

	i = 0;
	while (ft_power(base, i) - 1 < val)
		i++;
	if (base == 10)
	{
		str = ft_itoa(val);
		return (str);
	}
	str = malloc(sizeof(char) * i);
	str[i] = '\0';
	while (i--)
	{
		str[i] = (val % base) * (val % base > 9 ? 'A' - 10 : '0');
		val = val / base;
	}
	return (str);
}
