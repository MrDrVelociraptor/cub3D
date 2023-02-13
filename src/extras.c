/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:44:56 by nspeedy           #+#    #+#             */
/*   Updated: 2023/02/09 16:26:12 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	open_fail(int fd)
{
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
}

void	close_fail(int fd)
{
	if (close(fd) == -1)
	{
		perror("Error closing file");
		exit(EXIT_FAILURE);
	}
}

int	ft_count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else
		{
			if (!in_word)
				count++;
			in_word = 1;
		}
		s++;
	}
	return (count);
}

void	print_file_contents(t_world *world, int *temp_height)
{
	int	i;

	i = 0;
	while (i < *temp_height)
	{
		printf("%s\n", world->map_file[i]);
		i++;
	}
}

void	print_map(t_world *world)
{
	int	i;

	i = 0;
	while (i < world->m_height)
	{
		printf("%s\n", world->map_actual[i]);
		i++;
	}
}
