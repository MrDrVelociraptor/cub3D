/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:31:54 by nspeedy           #+#    #+#             */
/*   Updated: 2023/02/13 11:40:23 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <stdbool.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 1200
# define HEIGHT 800
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124


typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_image
{
	int		*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		ln_len;
	int		endian;
	t_mlx	*ptr;
}	t_image;

typedef struct s_textures
{
	char	**the_ture;
	int		f_height;
	int		f_width;
	int		w_height;
	int		w_width;
	// struct s_textures *next;
	// struct s_textures *prev;

}	t_textures;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	pos_z;
	int		colour;

}	t_player;

typedef struct s_world
{
	t_mlx		*mlx;
	t_image		*img;
	t_textures	*floor_tiles;
	char		**map_file;
	char		**map_actual;
	int			m_height;
	int			m_width[2000000];
	int			max_width;
}	t_world;

int		close_win(void);
void	put_pixel(t_image *img, int x, int y, int color);
void	put_player_pix(t_image *img, t_player *p);

void	player_start(t_player *player, int x, int y);
void	map_area(t_world *world, t_image img, int x, int y);
// t_textures	**map_area(t_world *world, t_image img, int x, int y);


void	my_mlx_window(void *win, void *mlx);
t_image	new_image(t_mlx *mlx, int width, int height);

void	parse_map_file(const char *filename, t_world *world);
void	open_fail(int fd);
void	close_fail(int fd);
char	**allocate_map(const char *buf, int *temp_height, t_world *world);
int		ft_count_words(const char *s, char c);
char	**split_map_data(const char *buf, int *temp_height);
char	**get_real_map(t_world *world, int *temp_height);
void	render_map(t_world *world, t_image img, t_player *player);
void	print_file_contents(t_world *world, int *temp_height);
void	print_map(t_world *world);
t_textures	*flooring(t_world *world);
// void	put_pixel_f(t_image *img, t_textures *floor, int color);
void	print_xpm(t_textures *t_money);




#endif