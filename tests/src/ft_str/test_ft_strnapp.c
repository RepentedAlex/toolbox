/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnapp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:07:02 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/22 13:07:05 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/coverage_tester.h"
#include "../../../include/libft.h"
#include <string.h>

static int	test_normal(void)
{
	char	*res;

	res = ft_strnapp("Hello, ", "world!", 6);
	if	(!res)
		return (1);
	if (strcmp(res, "Hello, world!") != 0)
		return (free(res), 2);
	return (free(res), 0);
}

static int	test_partial(void)
{
	char	*res;

	res = ft_strnapp("Hello, ", "world!", 3);
	if	(!res)
		return (1);
	if (strcmp(res, "Hello, wor") != 0)
		return (free(res), 2);
	return (free(res), 0);
}

static int	test_empty_s1(void)
{
	char	*res;

	res = ft_strnapp("", "world!", 6);
	if (!res)
		return (1);
	if (strcmp(res, "world!") != 0)
		return (free(res), 2);
	return (free(res), 0);
}

static int	test_empty_s2(void)
{
	char	*res;

	res = ft_strnapp("Hello, ", "", 0);
	if (!res)
		return (1);
	if (strcmp(res, "Hello, ") != 0)
		return (free(res), 2);
	return (free(res), 0);
}

static int	test_n_greater_s2(void)
{
	char	*res;

	res = ft_strnapp("Hello, ", "world!", 10);
	if (!res)
		return (1);
	if (strcmp(res, "Hello, world!") != 0)
		return (free(res), 2);
	return (free(res), 0);
}

static int	test_empty_both(void)
{
	char	*res;

	res = ft_strnapp("", "", 0);
	if (strcmp(res, "") != 0)
		return (free(res), 1);
	return (free(res), 0);
}

static int	test_s2_null(void)
{
	char	*res;

	res = ft_strnapp("Hello, ", NULL, 6);
	if (res != NULL)
		return (1);
	return (0);
}

static int	test_s1_null(void)
{
	char	*res;

	res = ft_strnapp(NULL, "world!", 6);
	if (res != NULL)
		return (1);
	return (0);
}

static int	test_special_char(void)
{
	char	*res;

	res = ft_strnapp("Hello\n", "World!", 6);
	if (strcmp(res, "Hello\nWorld!") != 0)
		return (1);
	return (0);
}

int	test_ft_strnapp(void)
{
	int	ret;

	ret = 0;
	printf("\nTesting ft_strnapp():\n");
	ret += run_tests(test_normal, "Basic functionnality");
	ret += run_tests(test_partial, "Append partially");
	ret += run_tests(test_empty_s1, "Append to empty string");
	ret += run_tests(test_empty_s2, "Append empty string");
	ret += run_tests(test_empty_both, "Both string empty");
	ret += run_tests(test_n_greater_s2, "n greater than s2");
	ret += run_tests(test_s2_null, "s2 == NULL");
	ret += run_tests(test_s1_null, "s1 == NULL");
	ret += run_tests(test_special_char, "Special chararcter");
	if (ret)
		return (1);
	return (0);
}
