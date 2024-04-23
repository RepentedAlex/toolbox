/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:54:13 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 16:50:16 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c += 32);
	else
		return (c);
}

/*
#include <stdio.h>

int main(void)
{
    int test = 79;

    int result = ft_toupper(test);
    printf("%c\n", result);
}
*/
