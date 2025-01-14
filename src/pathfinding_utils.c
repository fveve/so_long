/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:37 by arafa             #+#    #+#             */
/*   Updated: 2024/02/13 16:31:11 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	go_to_collec(char **map, char c, int *x, int *y)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x] && map[*y][*x] != c)
			(*x)++;
		if (map[*y][*x] == c)
			return ;
		(*y)++;
	}
	*x = 1;
	*y = 1;
}

int	is_border(char	**map, int x, int y)
{
	if (map[y][x + 1] == '2' && map[y][x - 1] == '1' &&
			map[y - 1][x] == '1' && map[y + 1][x] == '1')
		return (1);
	else if (map[y][x - 1] == '2' && map[y][x + 1] == '1'
			&& map[y - 1][x] == '1' && map[y + 1][x] == '1')
		return (1);
	else if (map[y - 1][x] == '2' && map[y][x - 1] == '1' &&
			map[y][x + 1] == '1' && map[y + 1][x] == '1')
		return (1);
	else if (map[y + 1][x] == '2' && map[y][x - 1] == '1' &&
			map[y - 1][x] == '1' && map[y][x + 1] == '1')
		return (1);
	return (0);
}

int	is_player(char	**map, int y, int x)
{
	if ((map[y][x] != '\r' || map[y][x] != '\n') && map[y][x + 1] == 'P')
		return (1);
	else if (x != 0 && map[y][x - 1] == 'P')
		return (1);
	else if ((map[y][x] != '\r' || map[y][x] != '\n' ||
			map[y][x] != '1') && map[y + 1][x] == 'P')
		return (1);
	else if (y != 0 && map[y - 1][x] == 'P')
		return (1);
	else if (map[y][x] == 'P')
		return (1);
	return (0);
}

char	**create_map2(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '1')
				map[x][y] = '2';
			y++;
		}
		x++;
	}
	return (map);
}

char	**create_map(char **tile_set)
{
	char	**map;
	int		x;

	x = 0;
	while (tile_set[x])
		x++;
	map = malloc(sizeof(char *) * (x + 1));
	x = 0;
	while (tile_set[x])
	{
		map[x] = ft_strdup(tile_set[x]);
		x++;
	}
	map[x] = NULL;
	map = create_map2(map);
	return (map);
}
