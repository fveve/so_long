/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:12:02 by marvin            #+#    #+#             */
/*   Updated: 2024/02/16 13:54:35 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define SIZE_Y 100
# define SIZE_X 100
# define SPEED 2000
//INCLUDES------------------------------------

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../include/get_next_line.h"
# include "../include/ft_printf.h"

//STRUCTURES----------------------------------
typedef struct s_anim
{
	void	*frame1;
	void	*frame2;
	void	*frame3;
	void	*frame4;
	void	*frame5;
	void	*current;
	int		frame_count;
	int		width;
	int		height;
}	t_anim;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*floor;
	void	*bag;
	t_anim	forward;
	t_anim	backward;
	t_anim	medal;
	t_anim	door;
	char	**tile_set;
	int		trigger;
	int		x;
	int		y;
	int		screen_x;
	int		screen_y;
	int		moves;
	int		collec;
}	t_data;

//INPUT---------------------------------------------------------------
int		input(int key, t_data	*data);
//INIT DATA-----------------------------------------------------------
void	init_data(t_data *data, char *path);
//--------------------------------------------------------------------
int		create_trgb(int t, int r, int g, int b);
//RENDER--------------------------------------------------------------
void	render_anim(t_anim *anim, t_data *data, int x, int y);
void	print_map(t_data *data, char **tile_set);
int		ft_render(t_data *data);
//INIT_MAP------------------------------------------------------------
void	parse_map(t_data *data, char *path);
//PATHFINDING---------------------------------------------------------
void	check_path(t_data *data, char **tile_set);
//UTILS---------------------------------------------------------------
int		ft_mess_error(t_data *data);
char	*ft_itoa(int nb);
char	*ft_strdup(char *s);
void	go_to_collec(char **map, char c, int *x, int *y);
void	free_tab(char **tab);
#endif