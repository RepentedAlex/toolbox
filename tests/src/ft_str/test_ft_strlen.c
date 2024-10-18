/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:49:53 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/18 14:49:56 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/coverage_tester.h"
#include "../../../include/libft.h"

int	test_typical_string(void)
{
	if (ft_strlen("hello") != 5)
		return (1);
	return (0);
}

/// @brief Check if ft_strlen works as expected with empty strings.
/// @return
int	test_empty_string(void)
{
	if (ft_strlen("\0") != 0)
		return (1);
	if (ft_strlen("") != 0)
		return (2);
	return (0);
}

int	test_single_char_string(void)
{
	if (ft_strlen("a") != 1)
		return (1);
	return (0);
}

int	test_null_termination_string(void)
{
	char	str[] = {'h', 'e', 'l', 'l', 'o', '\0'};
	if (ft_strlen(str) != 5)
		return (1);
	return (0);
}

int	test_spaced_string(void)
{
	if (ft_strlen("hello world") != 11)
		return (1);
	if (ft_strlen("  MARCO   VERRATTI  ") != 20)
		return (2);
	return (0);
}

int	test_special_char_string(void)
{
	if (ft_strlen("a!@#$\"\'\"\'") != 9)
		return (1);
	return (0);
}

int	test_unicode_char_string(void)
{
	if (ft_strlen("🖥️") != 4)
		return (1);
	return (0);
}

int	test_long_string(void)
{
	if (ft_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") \
	!= 1000)
		return (1);
	return (0);
}

int	test_null_string(void)
{
	char	*str;

	str = NULL;
	if (ft_strlen(str) != 0)
		return (1);
	return (0);
}

int	test_non_printable_string(void)
{
	if (ft_strlen("a\tb\nc") != 5)
		return (1);
	return (0);
}

int	run_tests(int (*f)(void), char *test)
{
	int	ret;

	ret = f();
	if (!ret)
		printf("%s: \e[0;32mOK\e[0;0m\n", test);
	else
		printf("%s: \e[0;31mKO\e[0;0m\n", test);
	return (ret);
}

int	test_ft_strlen(void)
{
	int	ret;

	ret = 0;
	printf("Testing ft_strlen():\n");

	ret += run_tests(test_typical_string, "typical string");
	ret += run_tests(test_empty_string, "empty string");
	ret += run_tests(test_single_char_string, "single char string");
	ret += run_tests(test_null_termination_string, "null termination string");
	ret += run_tests(test_spaced_string, "strings with spaces");
	ret += run_tests(test_special_char_string, "special characters");
//	ret += run_tests(test_unicode_char_string, "unicode characters");
	ret += run_tests(test_long_string, "long strings");
	ret += run_tests(test_null_string, "null pointed strings");
	ret += run_tests(test_non_printable_string, "non printable string");
	if (ret)
		return (1);
	return (0);
}
