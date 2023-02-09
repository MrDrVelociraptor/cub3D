/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:57:37 by nspeedy           #+#    #+#             */
/*   Updated: 2023/02/09 15:10:54 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void render_map(t_world *world, t_image *img)
{
	int i = 0;
    int x = 0;
    int y = 0;
    while (y < world->m_height)
    {
		printf("world->map_actual[y][x] = %c\n", world->map_actual[y][x]);

        while (x < world->m_width[i])
        {
			printf("world->m_width[i] = %i\n", world->m_width[i]);

            if (world->map_actual[y][x] == '0')
			{
                put_pixel(img, x, y, 0x000000);
			}
            else if (world->map_actual[y][x] == '1')
			{
                put_pixel(img, x, y, 0x000000);
			}
            x++;
			i++;
        }
        x = 0;
        y++;
    }
    mlx_put_image_to_window(world->mlx->mlx, world->mlx->win, world->img->addr, 0, 0);
}