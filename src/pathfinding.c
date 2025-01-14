/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:40:16 by marvin            #+#    #+#             */
/*   Updated: 2024/02/20 14:06:07 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	go_to_collec(char **map, char c, int *x, int *y);
char	**create_map(char **tile_set);
int		find_path(char **map, int x, int y, int trigger);
int		is_border(char	**map, int x, int y);
int		is_player(char	**map, int y, int x);

int	find_path2(char **map, int x, int y)
{
	if (map[y][x + 1] != '1' && map[y][x + 1] != '2' && map[y][x + 1] != 'E')
	{
		x++;
		if (find_path(map, x, y, 1) || find_path2(map, x, y))
			return (1);
	}
	if (map[y + 1][x] != '1' && map[y + 1][x] != '2' && map[y + 1][x] != 'E')
	{
		y++;
		if (find_path(map, x, y, 1) || find_path2(map, x, y))
			return (1);
	}
	return (0);
}

int	find_path(char **map, int x, int y, int trigger)
{
	while (!is_player(map, y, x))
	{
		if (trigger == 1)
			map[y][x] = '1';
		if (x != 0 && map[y][x - 1] != '1' && map[y][x - 1] != '2'
			&& map[y][x - 1] != 'E')
		{
			x--;
			if (find_path(map, x, y, 1) || find_path2(map, x, y))
				return (1);
		}
		if (y != 0 && map[y - 1][x] != '1' && map[y - 1][x] != '2'
			&& map[y - 1][x] != 'E')
		{
			y--;
			if (find_path(map, x, y, 1) || find_path2(map, x, y))
				return (1);
		}
		if (find_path2(map, x, y))
			return (1);
		else
			return (0);
	}
	return (1);
}

char	**set_map(char **map, int collectibles, int z)
{
	int	x;
	int	y;

	while (z != collectibles)
	{
		go_to_collec(map, 'C', &x, &y);
		if (map[y][x] == 'C')
			map[y][x] = '0';
		z++;
	}
	return (map);
}

void	check_exit(t_data *data)
{
	char	**map;
	int		x;
	int		y;

	map = create_map(data->tile_set);
	go_to_collec(map, 'E', &x, &y);
	if (!find_path(map, x, y, 0))
	{
		free_tab(map);
		ft_printf("need space for exit\n");
		ft_mess_error(data);
	}
	free_tab(map);
}

void	check_path(t_data *data, char **tile_set)
{
	char	**map;
	int		x;
	int		y;
	int		collec;

	x = 0;
	y = 0;
	collec = data->collec;
	while (collec > 0)
	{
		map = create_map(tile_set);
		map = set_map(map, data->collec, collec);
		go_to_collec(map, 'C', &x, &y);
		if (!find_path(map, x, y, 0))
		{
			free_tab(map);
			ft_printf("need space for collectible\n");
			ft_mess_error(data);
		}
		free_tab(map);
		collec--;
	}
	check_exit(data);
}
