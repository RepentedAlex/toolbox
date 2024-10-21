/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_str_append.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:22:17 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/21 22:22:17 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/coverage_tester.h"
#include "../../../include/libft.h"
#include <string.h>

int	test_normal(void)
{
	char	*res;

	res = ft_str_append("Hello, ", "World!");
	if (strcmp(res, "Hello, World!") != 0)
		return (free(res), 1);
	return (free(res), 0);
}

int	test_empty_s2(void)
{
	char	*res;

	res = ft_str_append("Hello", "");
	if (strcmp(res, "Hello") != 0)
		return (free(res), 1);
	return (free(res), 0);
}

int	test_empty_s1(void)
{
	char	*res;

	res = ft_str_append("", "World!");
	if (strcmp(res, "World!") != 0)
		return (free(res), 1);
	return (free(res), 0);
}

int	test_empty_both(void)
{
	char	*res;

	res = ft_str_append("", "");
	if (strcmp(res, "") != 0)
		return (free(res), 1);
	return (free(res), 0);
}

int	test_s2_null(void)
{
	char	*res;

	res = ft_str_append("Hello", NULL);
	if (res != NULL)
		return (1);
	return (0);
}

int	test_s1_null(void)
{
	char	*res;

	res = ft_str_append(NULL, "World!");
	if (res != NULL)
		return (1);
	return (0);
}

int	test_special_char(void)
{
	char	*res;

	res = ft_str_append("Hello\n", "World!");
	if (strcmp(res, "Hello\nWorld!") != 0)
		return (1);
	return (0);
}

int	test_ft_str_append(void)
{
	int	ret;

	ret = 0;
	printf("\nTesting ft_str_append():\n");
	ret += run_tests(test_normal, "Basic functionnality");
	ret += run_tests(test_empty_s2, "Append empty string");
	ret += run_tests(test_empty_s1, "Append to empty string");
	ret += run_tests(test_empty_both, "Both string empty");
	ret += run_tests(test_s2_null, "s2 == NULL");
	ret += run_tests(test_s1_null, "s1 == NULL");
	if (ret)
		return (1);
	return (0);
}
