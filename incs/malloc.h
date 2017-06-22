/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:49:20 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/22 15:09:56 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/mman.h>
# include "../libft/libft.h"

# define TINY 512
# define SMALL 4096
# define BSIZE sizeof(t_block)
# define ALLOCSIZE(s) s + BSIZE
# define SIZE(s) s - BSIZE

typedef struct		s_block
{
	size_t			size;
	bool			isfree;
	bool			isfirst;
	struct s_block	*prev;
	struct s_block	*next;
}					t_block;

typedef struct		s_env
{
	t_block			*tiny;
	t_block			*small;
	t_block			*large;
}					t_env;

t_env		g_env;

/*
** debug.c
*/

void				debug_print_current_alloc(t_block *lnk);

/*
** utility.c
*/

size_t				getmultiplegps(size_t allocsize);
t_block				**identifyenv(size_t size);

/*
** malloc.c
*/

void				push_newblock(size_t allocsize, t_block **env);
bool				splitblock(size_t allocsize, t_block **env);
void				*findalloc(size_t allocs, t_block **env);
void				*malloc(size_t size);

/*
** free.c
*/

void				free(void *ptr);

/*
** show_alloc_mem.c
*/

void				show_alloc_mem(void);

#endif
