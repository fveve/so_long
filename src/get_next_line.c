/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:39:41 by arafa             #+#    #+#             */
/*   Updated: 2024/02/20 11:57:51 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	line_size(t_list	*stash)
{
	int	x;
	int	count;

	count = 0;
	while (stash)
	{
		x = 0;
		while (stash->content[x])
		{
			if (stash->content[x] == '\n')
				return (count + 1);
			x++;
			count++;
		}
		stash = stash->next;
	}
	return (count);
}

int	isnewline(t_list	*stash)
{
	t_list	*temp;
	int		x;

	x = 0;
	if (!stash)
		return (0);
	temp = ft_lstlast(stash);
	while (temp->content[x])
	{
		if (temp->content[x] == '\n')
			return (1);
		x++;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	clear_stash(t_list	**stash)
{
	t_list	*temp;
	t_list	*last;
	int		x;
	int		y;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return ;
	temp->next = NULL;
	last = ft_lstlast(*stash);
	x = 0;
	while (last->content[x])
		x++;
	temp->content = malloc(sizeof(char) * ((x - line_size(last)) + 1));
	if (!temp->content)
		return ;
	y = 0;
	x = line_size(last);
	while (last->content[x] != '\0')
		temp->content[y++] = last->content[x++];
	temp->content[y] = '\0';
	free_stash(*stash);
	*stash = temp;
}

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;
	int				nbytes;

	nbytes = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		free_stash(stash);
		stash = NULL;
		return (NULL);
	}
	fill_stash(&stash, fd, &nbytes);
	if (!stash || nbytes < 0)
		return (NULL);
	line = extract_line(line, stash);
	clear_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free (line);
		return (NULL);
	}
	return (line);
}
