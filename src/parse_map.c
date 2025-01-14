/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:00:48 by arafa             #+#    #+#             */
/*   Updated: 2024/02/16 14:08:35 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	verify_map(t_data *data, char **tile_set);
void	verify_outline(t_data *data, char **tile);
void	is_ber(t_data *data, char *path);
char	**array_dup(char **tab);
int		set_collectibles(t_data *data, char **tile_set);
int		is_square(t_data *data, char **map);

char	**fill_map(char **tile_set, char *tab, int x)
{
	char	**temp;
	int		y;

	y = 0;
	temp = NULL;
	if (tile_set)
	{
		temp = array_dup(tile_set);
		free_tab(tile_set);
	}
	tile_set = malloc(sizeof(char *) * (x + 8));
	x = 0;
	if (temp)
		while (temp[y])
			tile_set[x++] = ft_strdup(temp[y++]);
	tile_set[x++] = ft_strdup(tab);
	tile_set[x] = NULL;
	if (temp)
		free_tab(temp);
	return (tile_set);
}

void	verify_letters(t_data *data, char **tile_set, char c)
{
	int	x;
	int	y;
	int	trigger;

	x = 0;
	y = 0;
	trigger = 0;
	while (tile_set[x])
	{
		y = 0;
		while (tile_set[x][y])
		{
			if (tile_set[x][y] == c)
				trigger++;
			y++;
		}
		x++;
	}
	if (trigger != 1)
	{
		ft_printf("wrong map\n");
		ft_mess_error(data);
	}
}

void	verify_outline2(t_data *data, char **tile, int y)
{
	int	x;

	x = 0;
	y--;
	while (tile[y][x])
	{
		if ((!tile[y][x] && tile[y][x + 1]) || (tile[y][x] != '1'
		&& tile[y][x] != '\r' && tile[y][x] != '\n'
		&& tile[y][x] != '\0') || tile[0][x] != '1')
		{
			ft_printf("wrong map outline\n");
			ft_mess_error(data);
		}
		x++;
	}
	is_square(data, tile);
}

void	parse_map2(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->tile_set[0][x] != '\n' && data->tile_set[0][x] != '\r')
		x++;
	while (data->tile_set[y])
		y++;
	data->collec = set_collectibles(data, data->tile_set);
	data->screen_x = x * SIZE_X;
	data->screen_y = y * SIZE_Y;
	check_path(data, data->tile_set);
}

void	parse_map(t_data *data, char *path)
{
	char	*tab;
	int		fd;
	int		x;

	is_ber(data, path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("file problem\n");
		ft_mess_error(data);
	}
	x = 1;
	tab = get_next_line(fd);
	while (tab)
	{
		if (!tab)
			break ;
		data->tile_set = fill_map(data->tile_set, tab, x);
		free(tab);
		x++;
		tab = get_next_line(fd);
	}
	verify_map(data, data->tile_set);
	parse_map2(data);
	close(fd);
}
