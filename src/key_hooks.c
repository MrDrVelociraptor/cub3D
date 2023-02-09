/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:32:11 by nspeedy           #+#    #+#             */
/*   Updated: 2023/02/09 13:47:51 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_win(void)
{
	exit(0);
	return (0);
}

int	keypress(int key, void *data)
{
	data = 0;
	if (key == 53)
		close_win();
	return (0);
}

void	my_mlx_window(void *win, void *mlx)
{
	mlx_hook(win, 2, 1L << 0, keypress, 0);
	mlx_hook(win, 17, 1L << 17, close_win, 0);
	mlx_loop(mlx);
}
