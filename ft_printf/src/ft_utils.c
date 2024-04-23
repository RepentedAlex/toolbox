/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandropetitcollin <alessandropetitc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:33:16 by apetitco          #+#    #+#             */
/*   Updated: 2024/04/23 21:24:45 by alessandrop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(int n)
{
	int		len;
	char	*nb;

	len = 0;
	nb = ft_itoa(n);
	len = ft_print_string(nb);
	free(nb);
	return (len);
}
