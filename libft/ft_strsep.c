/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:27:16 by nspeedy           #+#    #+#             */
/*   Updated: 2023/02/09 10:27:41 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsep(char **str, const char *delim)
{
    char *token;
    char *temp_str;
    
    temp_str = *str;
    if (temp_str == NULL)
        return (NULL);
    
    token = strsep(&temp_str, delim);
    *str = temp_str;
    
    return (token);
}