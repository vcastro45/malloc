/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:02:57 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/17 11:08:16 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"

static t_env		g_env;

size_t	getblocksize(size_t allocsize)
{
	size_t	size;
	size_t	npages;

	if (allocsize <= TINY)
		size = ALLOCSIZE(TINY);
	else if (allocsize <= SMALL)
		size = ALLOCSIZE(SMALL);
	else
		size = ALLOCSIZE(allocsize);
	npages = size / getpagesize();
	if (size % getpagesize() > 0)
		npages++;
	ft_putnbr(npages *getpagesize() *100);
	ft_putchar('\n');
	return (npages * getpagesize() * 100);
}

void	*allocblock(size_t size)
{
	t_block		*newblock;
	size_t		newsize;

	newsize = getblocksize(size);
	newblock = mmap(NULL, newsize, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0);
	newblock->isfree = true;
	newblock->size = newsize;
	return (newblock);
}

void	*findmemory(t_block *block, size_t size)
{
	while (block != NULL)
	{
		if (block->isfree && block->size <= ALLOCSIZE(size))
			return (block);
		block->next = allocblock(size);
		block = block->next;
	}
	return (allocblock(size));
}

void	allocmemory(t_block *block, size_t size)
{
	size_t	tmpsize;
	t_block	*tmpnext;

	tmpsize = block->size;
	block->isfree = false;
	block->size = size;
	if (block->size + BSIZE > tmpsize)
		return ;
	tmpnext = block->next;
	block->next = block + size;
	block->next->size = tmpsize - block->size;
	block->next->next = tmpnext;
}

t_block		*suggestenv(size_t size)
{
	if (size <= TINY)
		return (g_env.tiny);
	else if (size <= SMALL)
		return (g_env.small);
	else
		return (g_env.large);
}

void	*malloc(size_t size)
{
	t_block		*env;

	env = suggestenv(size);
	return (findmemory(env, size));
}
