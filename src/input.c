/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:27:28 by arafa             #+#    #+#             */
/*   Updated: 2024/02/20 11:59:17 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	key_left(t_data *data)
{
	if (data->tile_set[data->y / SIZE_Y][(data->x - SIZE_X) / SIZE_X] != 'E'
	|| (data->tile_set[data->y / SIZE_Y][(data->x - SIZE_X) / SIZE_X] == 'E'
	&& data->collec == 0))
	{
		if (data->tile_set[data->y / SIZE_Y][(data->x - SIZE_X) / SIZE_X]
			== 'C')
		{
			data->collec--;
			data->tile_set[data->y / SIZE_Y][(data->x - SIZE_X) / SIZE_X] = '0';
		}
		else if (data->tile_set[data->y / SIZE_Y][(data->x - SIZE_X) / SIZE_X]
			== 'E' && data->door.frame_count >= SPEED * 1.5)
		{
			ft_printf("Congrats ! you won in %d moves.", data->moves);
			ft_mess_error(data);
		}
		data->trigger = 1;
		data->x -= SIZE_X;
		data->moves++;
		ft_printf("Moves : %d\n", data->moves);
	}
}

void	key_right(t_data *data)
{
	if (data->tile_set[data->y / SIZE_Y][(data->x + SIZE_X) / SIZE_X] != 'E'
	|| (data->tile_set[data->y / SIZE_Y][(data->x + SIZE_X) / SIZE_X] == 'E'
	&& data->collec == 0))
	{
		if (data->tile_set[data->y / SIZE_Y][(data->x + SIZE_X) / SIZE_X]
			== 'C')
		{
			data->collec--;
			data->tile_set[data->y / SIZE_Y][(data->x + SIZE_X) / SIZE_X] = '0';
		}
		else if (data->tile_set[data->y / SIZE_Y][(data->x + SIZE_X) / SIZE_X]
				== 'E' && data->door.frame_count >= SPEED * 1.5)
		{
			ft_printf("Congrats ! you won in %d moves.", data->moves);
			ft_mess_error(data);
		}
		data->trigger = 0;
		data->x += SIZE_X;
		data->moves++;
		ft_printf("Moves : %d\n", data->moves);
	}
}

void	key_up(t_data *data)
{
	if (data->tile_set[(data->y - SIZE_Y) / SIZE_Y][data->x / SIZE_X] != 'E'
		|| (data->tile_set[(data->y - SIZE_Y) / SIZE_Y][data->x / SIZE_X] == 'E'
		&& data->collec == 0))
	{
		if (data->tile_set[(data->y - SIZE_Y) / SIZE_Y][data->x / SIZE_X] ==
			'C')
		{
			data->collec--;
			data->tile_set[(data->y - SIZE_Y) / SIZE_Y][data->x / SIZE_X] = '0';
		}
		else if (data->tile_set[(data->y - SIZE_Y) / SIZE_Y][data->x / SIZE_X]
				== 'E' && data->door.frame_count >= SPEED * 1.5)
		{
			ft_printf("Congrats ! you won in %d moves.", data->moves);
			ft_mess_error(data);
		}
		data->y -= SIZE_Y;
		data->moves++;
		ft_printf("Moves : %d\n", data->moves);
	}
}

void	key_down(t_data *data)
{
	if (data->tile_set[(data->y + SIZE_Y + 60) / SIZE_Y][data->x / SIZE_X] !=
		'E'
		|| (data->tile_set[(data->y + SIZE_Y + 60) / SIZE_Y][data->x / SIZE_X]
			== 'E' && data->collec == 0))
	{
		if (data->tile_set[(data->y + SIZE_Y + 60) / SIZE_Y][data->x / SIZE_X]
				== 'C')
		{
			data->collec--;
			data->tile_set[(data->y + SIZE_Y + 60) / SIZE_Y][data->x / SIZE_X]
				= '0';
		}
		if (data->tile_set[(data->y + SIZE_Y + 60) / SIZE_Y][data->x / SIZE_X]
				== 'E' && data->door.frame_count >= SPEED * 1.5)
		{
			ft_printf("Congrats ! you won in %d moves.", data->moves);
			ft_mess_error(data);
		}
		data->y += SIZE_Y;
		data->moves++;
		ft_printf("Moves : %d\n", data->moves);
	}
}

int	input(int key, t_data	*data)
{
	print_map(data, data->tile_set);
	if (key == 97
		&& data->tile_set[data->y / SIZE_Y][(data->x - SIZE_X) / SIZE_X] != '1')
		key_left(data);
	else if (key == 100
		&& data->tile_set[data->y / SIZE_Y][(data->x + SIZE_X) / SIZE_X] != '1')
		key_right(data);
	else if (key == 119
		&& data->tile_set[(data->y - SIZE_Y) / SIZE_Y][data->x / SIZE_X] != '1')
		key_up(data);
	else if (key == 115
		&& data->tile_set[(data->y + SIZE_Y + 60) / SIZE_Y][data->x / SIZE_X]
		!= '1')
		key_down(data);
	if (key == 65307)
		ft_mess_error(data);
	return (0);
}
