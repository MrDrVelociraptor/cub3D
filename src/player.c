/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:38:35 by nspeedy           #+#    #+#             */
/*   Updated: 2023/02/13 10:40:16 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	player_start(t_player *player, int x, int y)
{
	player->pos_x = (double)x;
	player->pos_y = (double)y;
	player->colour = 0x0000FF;
}