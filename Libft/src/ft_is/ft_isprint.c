/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:07:30 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 16:46:09 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (c);
	else
		return (0);
}

/*
#include <stdio.h>

int main(void)
{
	int	test = 127;

	int	result = ft_isprint(test);
	printf("%d\n", result);
}
*/
