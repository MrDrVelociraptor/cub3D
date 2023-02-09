/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:44:56 by nspeedy           #+#    #+#             */
/*   Updated: 2023/02/09 13:45:23 by nspeedy          ###   ########.fr       */
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
