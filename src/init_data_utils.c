/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:43:54 by arafa             #+#    #+#             */
/*   Updated: 2024/02/16 12:55:32 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_pos(t_data *data, char **tile_set)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tile_set[x])
	{
		y = 0;
		while (tile_set[x][y] != 'P' && tile_set[x][y])
			y++;
		if (tile_set[x][y] == 'P')
			break ;
		x++;
	}
	tile_set[x][y] = '0';
	data->x = y * SIZE_X;
	data->y = x * SIZE_Y;
}

void	init_forward(t_data *data, t_anim *fd, void *mlx)
{
	int	x;
	int	y;

	fd->frame_count = 0;
	fd->current = NULL;
	fd->frame1 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/forward/forward1.xpm", &fd->width, &fd->height);
	fd->frame2 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/forward/forward2.xpm", &x, &y);
	fd->frame3 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/forward/forward3.xpm", &x, &y);
	fd->frame4 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/forward/forward4.xpm", &x, &y);
	fd->frame5 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/forward/forward5.xpm", &x, &y);
	if (!fd->frame1 || !fd->frame2 || !fd->frame3 || !fd->frame4 || !fd->frame5)
	{
		ft_printf("forward animation error\n");
		ft_mess_error(data);
	}
}

void	init_backward(t_data *data, t_anim *bd, void *mlx)
{
	int	x;
	int	y;

	bd->frame_count = 0;
	bd->current = NULL;
	bd->frame1 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/backward/backward1.xpm", &bd->width, &bd->height);
	bd->frame2 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/backward/backward2.xpm", &x, &y);
	bd->frame3 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/backward/backward3.xpm", &x, &y);
	bd->frame4 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/backward/backward4.xpm", &x, &y);
	bd->frame5 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/backward/backward5.xpm", &x, &y);
	if (!bd->frame1 || !bd->frame2 || !bd->frame3 || !bd->frame4 || !bd->frame5)
	{
		ft_printf("backward animation error\n");
		ft_mess_error(data);
	}
}

void	init_medal(t_data *data, t_anim *ml, void *mlx)
{
	int	x;
	int	y;

	ml->frame_count = 0;
	ml->current = NULL;
	ml->frame1 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/medal/medal.xpm", &ml->width, &ml->height);
	ml->frame2 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/medal/medal1.xpm", &x, &y);
	ml->frame3 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/medal/medal2.xpm", &x, &y);
	ml->frame4 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/medal/medal3.xpm", &x, &y);
	ml->frame5 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/medal/medal4.xpm", &x, &y);
	if (!ml->frame1 || !ml->frame2 || !ml->frame3 || !ml->frame4 || !ml->frame5)
	{
		ft_printf("medal animation error\n");
		ft_mess_error(data);
	}
}

void	init_door(t_data *data, t_anim *dr, void *mlx)
{
	int	x;
	int	y;

	dr->frame_count = 0;
	dr->current = NULL;
	dr->frame1 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/door/door1.xpm", &dr->width, &dr->height);
	dr->frame2 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/door/door2.xpm", &x, &y);
	dr->frame3 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/door/door3.xpm", &x, &y);
	dr->frame4 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/door/door4.xpm", &x, &y);
	dr->frame5 = mlx_xpm_file_to_image(mlx,
			"./sprite/xpm/door/door5.xpm", &x, &y);
	if (!dr->frame1 || !dr->frame2 || !dr->frame3 || !dr->frame4 || !dr->frame5)
	{
		ft_printf("door animation error\n");
		ft_mess_error(data);
	}
}
