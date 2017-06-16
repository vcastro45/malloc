/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:30:41 by vcastro-          #+#    #+#             */
/*   Updated: 2016/01/13 13:30:58 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, unsigned int size)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * (size + 1));
	if (tmp == NULL)
		return (NULL);
	else
		while (i < size && *str)
		{
			tmp[i] = str[i];
			i++;
		}
	tmp[i] = '\0';
	return (tmp);
}
