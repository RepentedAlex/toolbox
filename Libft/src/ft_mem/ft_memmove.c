/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:29:18 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 16:55:14 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dup_src;
	char	*dup_dest;

	if (!src && !dest)
		return (dest);
	dup_src = (char *)src;
	dup_dest = (char *)dest;
	i = 0;
	if (dest > src)
	{
		while (n != 0)
		{
			dup_dest[n - 1] = dup_src[n - 1];
			n--;
		}
	}
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
