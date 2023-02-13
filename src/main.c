/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:31:56 by nspeedy           #+#    #+#             */
/*   Updated: 2023/02/13 10:16:04 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cub3D.h"

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_image		img;
	t_world		world;
	t_player	player;

	if (ac != 2)
	{
		printf("Usage: %s filename\n", av[0]);
		exit(EXIT_FAILURE);
	}
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Square Outline");
	parse_map_file(av[1], &world);
	img = new_image(&mlx, WIDTH, HEIGHT);
	render_map(&world, img, &player);
	// print_xpm(flooring(&world));
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	my_mlx_window(mlx.win, mlx.mlx);
	return (0);
}
