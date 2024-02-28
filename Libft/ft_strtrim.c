/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:29:49 by apetitco          #+#    #+#             */
/*   Updated: 2023/11/24 14:30:24 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_string;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	(void)end;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end] && ft_strchr(set, s1[end]) && end > start)
		end--;
	trimmed_string = ft_calloc(end - start + 2, sizeof(char));
	if (!trimmed_string)
		return (NULL);
	ft_strlcpy(trimmed_string, &s1[start], end - start + 2);
	return (trimmed_string);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*test="xxxtripouille   ";
	char	*charset=" x";

	char	*resultat = ft_strtrim(test, charset);
	printf("%s\n", resultat);
	free(resultat);
}
*/
