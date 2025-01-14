/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:50:37 by arafa             #+#    #+#             */
/*   Updated: 2024/02/16 13:54:31 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strdup(char *s)
{
	char	*tab;
	int		x;

	x = 0;
	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[x])
	{
		tab[x] = s[x];
		x++;
	}
	tab[x] = '\0';
	return (tab);
}
