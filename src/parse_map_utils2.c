/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:00:03 by marvin            #+#    #+#             */
/*   Updated: 2024/02/20 17:00:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	is_square(t_data *data, char **tile)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (tile[y][x] && tile[y][x] != '\r' && tile[y][x] != '\n')
		x++;
	while (tile[y])
		y++;
	if (x == y)
	{
		ft_printf("map shoudn't be a square\n");
		ft_mess_error(data);
	}
}
