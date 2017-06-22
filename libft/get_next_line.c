/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:40:18 by vcastro-          #+#    #+#             */
/*   Updated: 2016/01/13 14:32:17 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnljoin(t_list *lst)
{
	int		i;
	char	*str;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	str = (void*)0;
	while (tmp)
	{
		i += tmp->content_size;
		tmp = tmp->next;
	}
	str = ft_strnew(i);
	if (str)
		while (lst)
		{
			tmp = lst;
			str = ft_strcat(str, lst->content);
			lst = lst->next;
			free(tmp->content);
			free(tmp);
		}
	return (str);
}

void	ft_lst_push_back(t_list **lst, t_list *newlist)
{
	t_list	*tmp;

	if (*lst == (void*)0)
	{
		*lst = newlist;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newlist;
}

int		gnl_read(int fd, char *buf, t_list **lst, char **line)
{
	char	*tmp;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (ret == 0 && *lst == (void*)0)
		{
			(*line) = (void*)0;
			return (0);
		}
		else if ((tmp = ft_strchr(buf, '\n')))
		{
			ft_lst_push_back(lst, ft_lstnew(buf, tmp - buf));
			ret = 0;
		}
		else
			ft_lst_push_back(lst, ft_lstnew(buf, ret));
	}
	*line = ft_gnljoin(*lst);
	return (1);
}

int		other_read(char *buf, t_list **lst, char **line)
{
	int		i;
	int		k;

	i = 0;
	while (i != BUFF_SIZE)
	{
		if (buf[i] == '\n')
		{
			buf[i++] = '\0';
			k = i;
			while (i != BUFF_SIZE && buf[i] != '\n' && buf[i] != '\0')
				i++;
			if (buf[i] == '\n')
			{
				*line = ft_strndup(&buf[k], i - k);
				return (1);
			}
			else if (i - k == 0)
				return (0);
			ft_lst_push_back(lst, ft_lstnew(&buf[k], i - k));
			return (0);
		}
		buf[i++] = '\0';
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_stat	stat;
	t_list			*lst;

	lst = (void*)0;
	if (fd < 0 || line == (void*)0)
		return (-1);
	if (stat.filedes != fd)
	{
		stat.filedes = fd;
		ft_memset(stat.buf, 0, BUFF_SIZE);
	}
	else if (other_read(stat.buf, &lst, line))
		return (1);
	return (gnl_read(fd, stat.buf, &lst, line));
}
