/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:51:41 by arafa             #+#    #+#             */
/*   Updated: 2024/02/20 14:31:43 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	verify_letters(t_data *data, char **tile_set, char c);
void	verify_outline2(t_data *data, char **tile, int y);

int	set_collectibles(t_data *data, char **tile_set)
{
	int	x;
	int	y;
	int	collec;

	x = 0;
	collec = 0;
	while (tile_set[x])
	{
		y = 0;
		while (tile_set[x][y])
		{
			if (tile_set[x][y] == 'C')
				collec++;
			y++;
		}
		x++;
	}
	if (collec == 0)
	{
		ft_printf("no collectible\n");
		ft_mess_error(data);
	}
	return (collec);
}

char	**array_dup(char **tab)
{
	char	**dup;
	int		x;

	x = 0;
	while (tab[x])
		x++;
	dup = malloc(sizeof(char *) * (x + 1));
	x = 0;
	while (tab[x])
	{
		dup[x] = ft_strdup(tab[x]);
		x++;
	}
	dup[x] = NULL;
	return (dup);
}

void	verify_outline(t_data *data, char **tile)
{
	int	x;
	int	y;
	int	max;

	x = 0;
	y = 0;
	max = 0;
	while (tile[0][max] != '\n' && tile[0][max] != '\r' && tile[0][max])
		max++;
	while (tile[y])
	{
		x = 0;
		while (tile[y][x] && tile[y][x] != '\n' && tile[y][x] != '\r')
			x++;
		if (x != max || tile[y][0] != '1' || tile[y][x - 1] != '1')
		{
			ft_printf("wrong map outline\n");
			ft_mess_error(data);
		}
		y++;
	}
	verify_outline2(data, tile, y);
}

void	verify_map(t_data *data, char **tile_set)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tile_set[x])
	{
		y = 0;
		while (tile_set[x][y++])
		{
			if (tile_set[x][y] != '1' && tile_set[x][y] != '0'
				&& tile_set[x][y] != 'P'
				&& tile_set[x][y] != 'C' && tile_set[x][y] != 'E'
				&& tile_set[x][y] != '\n'
				&& tile_set[x][y] != '\r' && tile_set[x][y] != '\0')
			{
				ft_printf("wrong map\n");
				ft_mess_error(data);
			}
		}
		x++;
	}
	verify_letters(data, tile_set, 'P');
	verify_letters(data, tile_set, 'E');
	verify_outline(data, tile_set);
}

void	is_ber(t_data *data, char *path)
{
	char	*reb;
	int		x;
	int		y;

	reb = "reb.";
	x = 0;
	y = 0;
	while (path[x])
		x++;
	x--;
	while (x != 0 && reb[y])
	{
		if (path[x] != reb[y])
		{
			ft_printf("map file need to be finished by .ber\n");
			ft_mess_error(data);
		}
		x--;
		y++;
	}
}
