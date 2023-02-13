/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:57:37 by nspeedy           #+#    #+#             */
/*   Updated: 2023/02/13 12:36:06 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_line(t_world *w1, t_world *w2, t_image *img)
{
	
}

static void	draw_tile(t_world *world, int off_x, int off_y, int colour)
{
	t_textures *tiles;

	tiles = flooring(world);
	printf("f_h = %i f_w = %i\n", tiles->f_height, tiles->f_width);

}

void	render_map(t_world *world, t_image img, t_player *player)
{
	int	x;
	int	y;
	

	x = 0;
	y = 0;
	draw_tile(world, x, y, 0x00FF0000);
	while (y < HEIGHT)
	{
		while (x < world->m_width[y])
		{
			if (world->map_actual[y][x] == '0')
			{
				// put_pixel(&img, WIDTH / 2 + x, HEIGHT / 2 + y, 0x00FF0000);
				// printf("x * m_width = %i\n", (x * world->m_width[y]));

			}
			else if (world->map_actual[y][x] == '1')
				put_pixel(&img, WIDTH / 2 + x, HEIGHT / 2 + y, 0x0000FF00);
			// else if (world->map_actual[y][x] == 'N' || world->map_actual[y][x] == 'E'
			// 	|| world->map_actual[y][x] == 'S' || world->map_actual[y][x] == 'W')
			// {
			// 	player_start(player, x, y);
			// 	put_player_pix(&img, player);
			// }
			x++;
		}
		x = 0;
		y++;
	}
}

// void	render_map(t_world *world, t_image img)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (y < world->m_height)
// 	{
// 		while (x < world->m_width[y])
// 		{
// 			if (world->map_actual[y][x] == '0')
// 				put_pixel(&img, WIDTH / 2 + x, HEIGHT / 2 + y, 0x00FF0000);
// 			else if (world->map_actual[y][x] == '1')
// 				put_pixel(&img, WIDTH / 2 + x, HEIGHT / 2 + y, 0x0000FF00);
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }
