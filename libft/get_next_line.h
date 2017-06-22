/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <vcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:13:33 by vcastro-          #+#    #+#             */
/*   Updated: 2017/06/22 09:43:10 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 512
# include "libft.h"
# include <fcntl.h>

typedef struct		s_stat
{
	int				filedes;
	char			buf[BUFF_SIZE + 1];
}					t_stat;

int					get_next_line(int const fd, char **line);
#endif
