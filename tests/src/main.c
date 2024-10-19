/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:47:08 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/18 14:47:15 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/coverage_tester.h"

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

/// @brief Fonction du testeur
/// @return
int	coverage_test(void)
{
	int	ret;
	int	last_ret;

	ret = 0;
	last_ret = 0;
	ret += test_ft_strlen();
	if (last_ret != ret)
		printf("ft_strlen(): \e[0;31mKO\e[0;0m\n");
	else
		printf("ft_strlen(): \e[0;32mOK\e[0;0m\n");
	ret += test_ft_isalnum();
	if (last_ret != ret)
		printf("ft_isalnum(): \e[0;31mKO\e[0;0m\n");
	else
		printf("ft_isalnum(): \e[0;32mOK\e[0;0m\n");
	return (ret);
}

int	main(void)
{
	int	failed_tests;

	printf("Running coverage_tester on Toolbox\n\n");
	failed_tests = coverage_test();
	if (!failed_tests)
	{
		printf("\nToolbox: \e[0;32mOK\e[0;0m\n");
		return (0);
	}
	printf("\nToolbox: \e[0;31mKO\e[0;0m\n");
	return (failed_tests);
}
