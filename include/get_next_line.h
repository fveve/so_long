/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:09:15 by arafa             #+#    #+#             */
/*   Updated: 2024/02/13 11:38:26 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

//LIST-----------------------------------------------
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

//FUNCTIONS------------------------------------------
void	fill_stash(t_list	**stash, int fd, int	*nbytes);
void	fill_node(t_list **stash, char *buff, int nbytes);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	clear_stash(t_list	**stash);
void	free_stash(t_list	*stash);
t_list	*ft_lstlast(t_list *lst);
int		line_size(t_list	*stash);
int		isnewline(t_list	*stash);
char	*extract_line(char	*line, t_list	*stash);
char	*get_next_line(int fd);
#endif