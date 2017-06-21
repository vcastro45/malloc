/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:49:20 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/21 13:52:05 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/mman.h>

#include "../libft/libft.h"

# define TINY 512
# define SMALL 4096
# define BSIZE sizeof(t_block)
# define ALLOCSIZE(s) s + BSIZE
# define SIZE(s) s - BSIZE

# define WHERE ft_putnbr(__LINE__); ft_putstr(" "); ft_putendl(__FILE__);

typedef struct		s_block
{
	size_t			size;
	bool			isfree;
	struct s_block	*prev;
	struct s_block	*next;
}					t_block;

typedef struct		s_env
{
	t_block			*tiny;
	t_block			*small;
	t_block			*large;
}					t_env;

void				*malloc(size_t size);

#endif
