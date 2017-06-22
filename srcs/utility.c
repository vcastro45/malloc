/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 12:50:44 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/22 14:05:10 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"

/*
** `allocsize` must be ALLOCSIZE(size) * 100 for TINY and SMALL, and
** ALLOCSIZE(size) for LARGE
*/

size_t	getmultiplegps(size_t allocsize)
{
	int gps;
	int npages;

	gps = getpagesize();
	npages = allocsize / gps;
	return ((allocsize % gps > 0 ? npages + 1 : npages) * gps);
}

t_block	**identifyenv(size_t size)
{
	if (size <= TINY)
		return (&(g_env.tiny));
	else if (size <= SMALL)
		return (&(g_env.small));
	return (&(g_env.large));
}