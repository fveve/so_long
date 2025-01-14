/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:48:18 by marvin            #+#    #+#             */
/*   Updated: 2024/02/15 12:48:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_medal(t_data *data, char **tile_set)
{
	int	x;
	int	y;

	x = 0;
	while (tile_set[x])
	{
		y = 0;
		while (tile_set[x][y])
		{
			if (tile_set[x][y] == 'C')
				render_anim(&data->medal, data, y * SIZE_X, x * SIZE_Y);
			y++;
		}
		x++;
	}
}
