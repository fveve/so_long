/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:53:30 by marvin            #+#    #+#             */
/*   Updated: 2024/02/20 11:58:27 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_medal(t_data *data, char **tile_set);

void	print_map(t_data *data, char **tile_set)
{
	int	x;
	int	y;

	x = 0;
	while (tile_set[x])
	{
		y = 0;
		while (tile_set[x][y])
		{
			if (tile_set[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->bag,
					y * SIZE_X, x * SIZE_Y);
			if (tile_set[x][y] == '0')
				mlx_put_image_to_window(data->mlx, data->window, data->floor,
					y * SIZE_X, x * SIZE_Y);
			if (tile_set[x][y] == 'E' && data->collec > 0)
				mlx_put_image_to_window(data->mlx, data->window,
					data->door.frame1, y * SIZE_X, x * SIZE_Y);
			y++;
		}
		x++;
	}
}

void	render_door(t_anim *anim, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	go_to_collec(data->tile_set, 'E', &x, &y);
	if (anim->frame_count == 0)
		anim->current = anim->frame1;
	if (anim->frame_count == SPEED / 2)
		anim->current = anim->frame2;
	if (anim->frame_count == SPEED / 1.5)
		anim->current = anim->frame3;
	if (anim->frame_count == SPEED)
		anim->current = anim->frame4;
	if (anim->frame_count == SPEED * 1.5)
		anim->current = anim->frame5;
	mlx_put_image_to_window(data->mlx, data->window, anim->current,
		x * SIZE_X, y * SIZE_Y);
	if (anim->frame_count < SPEED * 1.5)
		anim->frame_count++;
}

void	render_anim(t_anim *anim, t_data *data, int x, int y)
{
	if (anim->frame_count == 0)
		anim->current = anim->frame1;
	if (anim->frame_count == SPEED / 2)
		anim->current = anim->frame2;
	if (anim->frame_count == SPEED / 1.5)
		anim->current = anim->frame3;
	if (anim->frame_count == SPEED)
		anim->current = anim->frame4;
	if (anim->frame_count == SPEED * 1.5)
	{
		anim->current = anim->frame5;
		anim->frame_count = 0;
	}
	mlx_put_image_to_window(data->mlx, data->window, anim->current, x, y);
	anim->frame_count++;
}

void	print_moves(t_data *data)
{
	char	*tab;
	int		color;

	color = create_trgb(255, 255, 100, 100);
	tab = ft_itoa(data->moves);
	mlx_string_put(data->mlx, data->window, 10, 10, color, tab);
	free(tab);
}

int	ft_render(t_data *data)
{
	if (data->trigger == 0)
		render_anim(&data->forward, data, data->x, data->y);
	else if (data->trigger == 1)
		render_anim(&data->backward, data, data->x, data->y);
	if (data->collec == 0)
		render_door(&data->door, data);
	render_medal(data, data->tile_set);
	print_moves(data);
	return (0);
}
