/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:21:10 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 16:55:36 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		length;

	length = (ft_strlen((char *)s) + 1);
	duplicate = (char *)ft_calloc(length, sizeof(char));
	if (!duplicate)
		return (NULL);
	ft_strlcpy(duplicate, s, length);
	duplicate[length - 1] = 0;
	return (duplicate);
}
