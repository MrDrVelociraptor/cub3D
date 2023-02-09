/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:31:56 by nspeedy           #+#    #+#             */
/*   Updated: 2023/02/09 15:27:41 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cub3D.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_image	img;
	t_world	world;


	int i = 0;
	if (ac != 2)
	{
		printf("Usage: %s filename\n", av[0]);
		exit(EXIT_FAILURE);
	}
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Square Outline");
	parse_map_file(av[1], &world);
	img = new_image(&mlx, WIDTH, HEIGHT);
	while (world.m_width[i] != '\0')
	{
		printf("world->m_width[i] = %i\n", world.m_width[i]);
		i++;	
	}
	printf("hehehe\n");
	// render_map(&world, &img);
	// mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	my_mlx_window(mlx.win, mlx.mlx);
	return (0);
}
