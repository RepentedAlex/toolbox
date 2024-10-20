/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:57:52 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/19 16:57:52 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/coverage_tester.h"
#include "../../../include/libft.h"

int	test_digits(void)
{
	if (ft_isalnum('0') != 1)
		return (1);
	if (ft_isalnum('9') != 1)
		return (2);
	return (0);
}

int test_lowercase_letters(void)
{
	if (ft_isalnum('a') != 1)
		return (1);
	if (ft_isalnum('z') != 1)
		return (2);
	return (0);
}

int test_uppercase_letters(void)
{
	if (ft_isalnum('A') != 1)
		return (1);
	if (ft_isalnum('Z') != 1)
		return (2);
	return (0);
}

int	test_non_alphanumeric(void)
{
	if (ft_isalnum('!') != 0)
		return (1);
	if (ft_isalnum('@') != 0)
		return (2);
	if (ft_isalnum('#') != 0)
		return (3);
	if (ft_isalnum('$') != 0)
		return (4);
	return (0);
}

int	test_non_printable(void)
{
	if (ft_isalnum(' ') != 0)
		return (1);
	if (ft_isalnum('\t') != 0)
		return (2);
	if (ft_isalnum('\0') != 0)
		return (3);
	return (0);
}

int	test_edge_cases(void)
{
	if (ft_isalnum('0' - 1) != 0)
		return (1);
	if (ft_isalnum('9' + 1) != 0)
		return (2);
	if (ft_isalnum('A' - 1) != 0)
		return (3);
	if (ft_isalnum('Z' + 1) != 0)
		return (4);
	if (ft_isalnum('a' - 1) != 0)
		return (5);
	if (ft_isalnum('z' + 1) != 0)
		return (6);
	return (0);
}

int	test_extended_ascii(void)
{
	if (ft_isalnum(128) != 0)
		return (1);
	if (ft_isalnum(255) != 0)
		return (2);
	return (0);
}

int test_negative(void)
{
	if (ft_isalnum(-1) != 0)
		return (1);
	if (ft_isalnum(-100) != 0)
		return (2);
	return (0);
}

int	test_ft_isalnum(void)
{
	int	ret;

	ret = 0;
	printf("Testing ft_isalnum():\n");

	ret += run_tests(test_digits, "digits");
	ret += run_tests(test_lowercase_letters, "lowercase letters");
	ret += run_tests(test_uppercase_letters, "uppercase letters");
	ret += run_tests(test_non_alphanumeric, "non-alphanumeric");
	ret += run_tests(test_non_printable, "non printable");
	ret += run_tests(test_edge_cases, "edge cases");
	ret += run_tests(test_extended_ascii, "extended ascii");
	ret += run_tests(test_negative, "negative values");
	if (ret)
		return (1);
	return (0);
}
