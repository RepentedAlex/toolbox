/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:46:41 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 16:50:21 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c -= 32);
	else
		return (c);
}

/*
#include <stdio.h>

int	main(void)
{
	int test = 99;

	int	result = ft_toupper(test);
	printf("%c\n", result);
}
*/
