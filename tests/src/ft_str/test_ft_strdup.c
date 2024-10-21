/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:24:10 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/21 15:24:12 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/coverage_tester.h"
#include "../../../include/libft.h"
#include <string.h>

int	test_normal(void)
{
	const char	*original = "Hello, World!";
	char		*copy;

	copy = ft_strdup(original);
	if (!copy)
		return (1);
	if (strcmp(original, copy) != 0)
		return (free(copy), 2);
	return (free(copy), 0);
}

int	test_empty(void)
{
	const char	*original = "";
	char		*copy;

	copy = ft_strdup(original);
	if (!copy)
		return (1);
	if (strcmp(original, copy) != 0)
		return (free(copy), 2);
	return (free(copy), 0);
}

int	test_null(void)
{
	const char	*original = NULL;
	char		*copy;

	copy = ft_strdup(original);
	if (copy != NULL)
		return (1);
	return (0);
}

int	test_long(void)
{
	const char	*original = "This is a very long string used to test the ft_strdup function with more data.";
	char		*copy;

	copy = ft_strdup(original);
	if (!copy)
		return (1);
	if (strcmp(original, copy) != 0)
		return (free(copy), 2);
	return (free(copy), 0);
}

int	test_modify_after_strdup(void)
{
	char	*original = ft_strdup("Original String");
	char	*copy;

	copy = ft_strdup(original);
	if (!copy)
		return (1);
	original[0] = 'X';
	if (strcmp(copy, "Original String") != 0)
		return (free(copy), 2);
	return (free(copy), 0);
}

int	test_non_ascii(void)
{
	const char	*original = "こんにちは世界";
	char		*copy;

	copy = ft_strdup(original);
	if (!copy)
		return (1);
	if (strcmp(original, copy) != 0)
		return (free(copy), 2);
	return (free(copy), 0);
}

int	test_single_char(void)
{
	const char	*original = "J";
	char		*copy;

	copy = ft_strdup(original);
	if (!copy)
		return (1);
	if (strcmp(original, copy) != 0)
		return (free(copy), 2);
	return (free(copy), 0);
}

int	test_ft_strdup(void)
{
	int	ret;

	ret = 0;
	printf("\nTesting ft_strdup():\n");

	ret += run_tests(test_normal, "normal string");
	ret += run_tests(test_empty, "empty string");
	ret += run_tests(test_long, "long string");
	ret += run_tests(test_null, "null string");
	ret += run_tests(test_modify_after_strdup, "string modified after strdup");
	ret += run_tests(test_non_ascii, "non ASCII string");
	ret += run_tests(test_single_char, "single char");
	if (ret)
		return (1);
	return (0);
}
