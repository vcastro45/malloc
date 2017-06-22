/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:02:57 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/22 15:38:08 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"

void	push_newblock(size_t allocsize, t_block **env)
{
	size_t	gpssize;
	t_block	*head;

	ft_putendl("new block");
	gpssize = getmultiplegps(allocsize);
	if (*env == NULL)
	{
		*env = mmap(NULL, gpssize, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0);
		(*env)->isfirst = true;
		head = *env;
	}
	else
	{
		head = *env;
		while ((*env)->next != NULL)
			*env = (*env)->next;
		(*env)->next = mmap(NULL, gpssize, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0);
		(*env)->next->isfirst = true;				
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
	(*env)->next = (void*)((unsigned long long int)*env +
		(unsigned long long int)allocsize);
	(*env)->next->isfree = true;
	(*env)->next->size = (*env)->size - allocsize + BSIZE;
	(*env)->next->isfirst = false;
	(*env)->next->prev = *env;
	(*env)->isfree = false;
	(*env)->size = allocsize;
	// debug_print_current_alloc(*env);
	return (true);
}

void	*findalloc(size_t allocs, t_block **env)
{
	t_block	*tmp;

	if (*env == NULL)
		push_newblock(SIZE(allocs) <= SMALL ? allocs * 100 : allocs, env);
	tmp = *env;
	while (tmp != NULL)
	{
		if (tmp->isfree && tmp->size >= allocs)
			if (splitblock(allocs, &tmp))
				return (tmp);
		tmp = tmp->next;
	}
	push_newblock(SIZE(allocs) <= SMALL ? allocs * 100 : allocs, env);
	findalloc(allocs, env);
	return (NULL);
}

void	*malloc(size_t size)
{
	t_block	**env;

	env = identifyenv(size);
	return (findalloc(ALLOCSIZE(size), env));
}
