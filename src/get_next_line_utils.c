/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:13:20 by arafa             #+#    #+#             */
/*   Updated: 2024/02/12 10:18:51 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_stash(t_list	*stash)
{
	t_list	*next;

	while (stash != NULL)
	{
		next = stash->next;
		free(stash->content);
		free(stash);
		stash = next;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new)
	{
		if (!lst)
			return ;
		if (!*lst)
			*lst = new;
		else
		{
			temp = ft_lstlast(*lst);
			temp->next = new;
		}
	}
}

void	fill_node(t_list **stash, char *buff, int nbytes)
{
	t_list	*node;
	int		x;

	x = 0;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->content = malloc(sizeof(char) * (nbytes + 1));
	if (!node->content)
		return ;
	node->next = NULL;
	while (buff[x] && x < nbytes)
	{
		node->content[x] = buff[x];
		x++;
	}
	node->content[x] = '\0';
	ft_lstadd_back(stash, node);
}

void	fill_stash(t_list	**stash, int fd, int	*nbytes)
{
	char	*buff;

	while (isnewline(*stash) == 0 && *nbytes != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		*nbytes = (int)read(fd, buff, BUFFER_SIZE);
		if ((!stash && *nbytes == 0) || *nbytes == -1)
		{
			free (buff);
			return ;
		}
		buff[*nbytes] = '\0';
		fill_node(stash, buff, *nbytes);
		free(buff);
	}
}

char	*extract_line(char	*line, t_list	*stash)
{
	int	x;
	int	y;

	if (!stash)
		return (NULL);
	y = 0;
	line = malloc(sizeof(char) * (line_size(stash) + 1));
	if (!line)
		return (NULL);
	while (stash)
	{
		x = 0;
		while (stash->content[x])
		{
			if (stash->content[x] == '\n')
			{
				line[y++] = stash->content[x++];
				break ;
			}
			line[y++] = stash->content[x++];
		}
		stash = stash->next;
	}
	line[y] = '\0';
	return (line);
}
