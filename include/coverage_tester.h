/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coverage_tester.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:57:37 by apetitco          #+#    #+#             */
/*   Updated: 2024/10/18 14:57:41 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COVERAGE_TESTER_H
# define COVERAGE_TESTER_H

// == == == INCLUDES == == ==
#include <stdio.h>
# include <stdlib.h>
# include <string.h>

// == == == UTILITARIES == == ==
int	run_tests(int (*f)(void), char *test);

// == == == MODULES TESTERS == == ==
int	test_ft_isalnum(void);
int	test_ft_strdup(void);
int	test_ft_strlen(void);

#endif
