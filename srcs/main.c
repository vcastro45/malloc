/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 10:03:00 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/22 20:27:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

int		main(void)
{
	 void	*ptr = malloc(50);
	ft_putendl("\nfree\n----------------------");
	ft_putendl("void *ptr = malloc(50);\n");
	ft_putendl("\nfree(ptr);\n");
	free(ptr);
	return (0);
}
