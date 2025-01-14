/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:12:42 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/21 22:12:45 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char	*og_dst;

	og_dst = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (og_dst);
}
