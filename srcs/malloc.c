/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:02:57 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/21 14:42:58 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"
#include <stdio.h>

static t_env		g_env;

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

void	push_newblock(size_t allocsize, t_block **env)
{
	size_t	gpssize;
	t_block	*head;

	gpssize = getmultiplegps(allocsize);
	if (*env == NULL)
	{
		*env = mmap(NULL, gpssize, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0);
		head = *env;
	}
	else
	{
		head = *env;
		while ((*env)->next != NULL)
			*env = (*env)->next;
		(*env)->next = mmap(NULL, gpssize, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0);
		*env = (*env)->next;
	}
	(*env)->isfree = true;
	(*env)->size = gpssize - BSIZE;
	(*env)->next = NULL;
	*env = head;
}

bool	splitblock(size_t allocsize, t_block **env)
{
	if ((*env)->size < allocsize)
		return (false);
	(*env)->next = *env + allocsize;
	(*env)->next->isfree = true;
	(*env)->next->size = (*env)->size - allocsize;
	(*env)->isfree = false;
	(*env)->size = allocsize;
	return (true);
}

void	*findalloc(size_t allocsize, t_block **env)
{
	t_block *head;
	void*	ret;

	head = *env;
	ret = NULL;
	ft_putstr("find addr: ");
	ft_print_addr(*env);
	ft_putchar('\n');
	while (*env != NULL)
	{
		ft_putendl("while");
		if ((*env)->isfree == true && (*env)->size <= allocsize)
		{
			if (splitblock(allocsize, env) == true)
			{
				ret = *env;
				break ;
			}
		}
		*env = (*env)->next;
	}
	*env = head;
	if (ret == NULL)
	{
		ft_putendl("NEW BLOCK");
		push_newblock(
				SIZE(allocsize) <= SMALL ? allocsize * 100 : allocsize, env);
		findalloc(allocsize, env);
	}
	return (ret);
}

t_block	**identifyenv(size_t size)
{
	if (size <= TINY)
		return (&(g_env.tiny));
	else if (size <= SMALL)
		return (&(g_env.small));
	return (&(g_env.large));
}

void	*malloc(size_t size)
{
	t_block	**env;

	env = identifyenv(size);
	findalloc(ALLOCSIZE(size), env);
	//findalloc(ALLOCSIZE(size), env);
	return (NULL);
}
