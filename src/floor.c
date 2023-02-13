/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:03:16 by nspeedy           #+#    #+#             */
/*   Updated: 2023/02/13 12:13:32 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_textures	*flooring(t_world *world)
{
	t_textures	*floor_data;

	floor_data = (t_textures *)malloc(sizeof(t_textures) * 1);
	floor_data->f_height = 100;
	floor_data->f_width = 100;
	floor_data->w_height = 200;
	floor_data->w_width = 300;
	floor_data->the_ture = (char **)malloc(sizeof(char **) * floor_data->f_height);
	return (floor_data);
}

