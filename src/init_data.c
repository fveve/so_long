/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:26:53 by arafa             #+#    #+#             */
/*   Updated: 2024/02/16 14:12:04 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_pos(t_data *data, char **tile_set);

void	init_forward(t_data *data, t_anim *fd, void *mlx);

void	init_backward(t_data *data, t_anim *bd, void *mlx);

void	init_medal(t_data *data, t_anim *ml, void *mlx);

void	init_door(t_data *data, t_anim *dr, void *mlx);

void	set_to_null(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->forward.frame1 = NULL;
	data->forward.frame2 = NULL;
	data->forward.frame3 = NULL;
	data->forward.frame4 = NULL;
	data->forward.frame5 = NULL;
	data->backward.frame1 = NULL;
	data->backward.frame2 = NULL;
	data->backward.frame3 = NULL;
	data->backward.frame4 = NULL;
	data->backward.frame5 = NULL;
	data->medal.frame1 = NULL;
	data->medal.frame2 = NULL;
	data->medal.frame3 = NULL;
	data->medal.frame4 = NULL;
	data->medal.frame5 = NULL;
	data->door.frame1 = NULL;
	data->door.frame2 = NULL;
	data->door.frame3 = NULL;
	data->door.frame4 = NULL;
	data->door.frame5 = NULL;
	data->bag = NULL;
	data->floor = NULL;
	data->tile_set = NULL;
}

void	set_to_null2(t_data *data)
{
	data->trigger = 0;
	data->moves = 0;
	data->collec = 0;
}

void	init_all(t_data *data)
{
	init_forward(data, &data->forward, data->mlx);
	init_backward(data, &data->backward, data->mlx);
	init_medal(data, &data->medal, data->mlx);
	init_door(data, &data->door, data->mlx);
}

void	init_data(t_data *data, char *path)
{
	int	x;
	int	y;

	set_to_null(data);
	set_to_null2(data);
	parse_map(data, path);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx,
			data->screen_x, data->screen_y, "boxeo");
	if (!data->window || !data->mlx)
	{
		ft_printf("mlx error\n");
		ft_mess_error(data);
	}
	data->bag = mlx_xpm_file_to_image(data->mlx,
			"./sprite/xpm/bag.xpm", &x, &y);
	data->floor = mlx_xpm_file_to_image(data->mlx,
			"./sprite/xpm/floor.xpm", &x, &y);
	if (!data->floor || !data->bag)
	{
		ft_printf("sprite error\n");
		ft_mess_error(data);
	}
	init_all(data);
	get_pos(data, data->tile_set);
}
