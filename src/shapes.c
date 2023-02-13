/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:31:41 by nspeedy           #+#    #+#             */
/*   Updated: 2023/02/09 08:31:41 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**allocate_map(const char *buf, int *temp_height, t_world *world)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strdup(buf);
	*temp_height = ft_count_words(temp, '\n') + 1;
	world->map_file = (char **)malloc(*temp_height * sizeof(char *));
	while (temp)
		world->map_file[i++] = ft_strsep(&temp, "\n");
	return (world->map_file);
}

char	**get_real_map(t_world *world, int *temp_height)
{
	int		i;
	int		j;
	int		q;
	char	*temp;

	i = 0;
	j = 0;
	world->m_height = 0;
	world->m_width[j] = 0;
	while (ft_strncmp(world->map_file[i], "1", 1)
		&& ft_strncmp(world->map_file[i], "0", 1))
	{
		i++;
	}
	world->m_height = *temp_height - i;
	// world->floor_tiles = (t_textures **)malloc(sizeof(t_textures) * world->m_height);
	world->map_actual = (char **)malloc(world->m_height * sizeof(char *));
	while (j < world->m_height)
	{
		world->map_actual[j] = ft_strdup(world->map_file[i]);
		world->m_width[j] = ft_strlen(world->map_actual[j]);
		if (world->m_width[j] >= world->max_width)
			world->max_width = world->m_width[j];
		i++;
		j++;
	}
	return (world->map_actual);
}

void	parse_map_file(const char *filename, t_world *world)
{
	int		fd;
	char	buf[7000];
	int		bytes_read;
	int		temp_height;
	
	fd = open(filename, O_RDONLY);
	open_fail(fd);
	bytes_read = read(fd, buf, sizeof buf - 1);
	buf[bytes_read] = '\0';
	temp_height = 0;
	world->map_file = allocate_map(buf, &temp_height, world);
	world->map_actual = get_real_map(world, &temp_height);
	close_fail(fd);
	// printf("\033[0;31mPRINTING ENTIRE FILE\n");
	// print_file_contents(world, &temp_height);
	// printf("\033[0m\n");
	printf("\033[0;34mPRINTING MAP AREA\n");
	print_map(world);
	printf("\033[0m\n");
	printf("\033[0;32mPROGRAM RAN\033[0m\n");
}
