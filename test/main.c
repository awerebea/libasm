/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:19:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/09/05 13:00:52 by awerebea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "libasm.h"

int			f_test_strlen(void)
{
	size_t	res;
	size_t	res_ft;
	int		k = 0;
	char	*s[6] = {"", "1", "21", "foo", "foo bar", "foo bar baz 0123456789"};
	printf("\n------------ ft_strlen ------------\n");
	for (int i = 0; i < 6; i++)
	{
		res = strlen(s[i]);
		res_ft = ft_strlen(s[i]);
		printf("string: `%s`\nresult std (f): %2lu\nresult ft_ (f): \
%2lu\n", s[i], res, res_ft);
		if (res == res_ft)
		{
			printf("OK\n\n");
			k++;
		}
		else
			printf("FAIL\n\n");
	}
	return ((k == 6) ? 0 : 1);
}

int			f_test_strcpy(void)
{
	char	res[50];
	char	res_ft[50];
	int		k = 0;

	char	*s[6] = {"", "1", "21", "foo", "foo bar", "foo bar baz 0123456789"};
	printf("\n------------ ft_strcpy ------------\n");
	for (int i = 0; i < 6; i++)
	{
		strcpy(res, s[i]);
		ft_strcpy(res_ft, s[i]);
		printf("source string: `%s`\nresult std (f): `%s`\nresult ft_ (f): \
`%s`\n", s[i], res, res_ft);
		if (!(strcmp(res_ft, res)))
		{
			printf("OK\n\n");
			k++;
		}
		else
			printf("FAIL\n\n");
	}
	return ((k == 6) ? 0 : 1);
}

int			f_test_strcmp(void)
{
	int		res;
	int		res_ft;
	char	*s1[6] = {"", "1", "21", "foo", "foo bar", "foo bar baz 0123456789"};
	char	*s2[6] = {"", "1", "21", "foo", "foo bar", "foo bar baz 0123456789"};
	int		k = 0;

	printf("\n------------ ft_strcmp ------------\n");
	int	j;
	for (int i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			res = strcmp(s1[i], s2[j]);
			res_ft = ft_strcmp(s1[i], s2[j]);
			printf("string 1:\t`%s`\nstring 2:\t`%s`\nresult std (f): %d\n\
result ft_ (f): %d\n", s1[i], s2[j], res, res_ft);
		if (res_ft == res)
		{
			printf("OK\n\n");
			k++;
		}
		else
			printf("FAIL\n\n");
		}
	}
	return ((k == 36) ? 0 : 1);
}

int			main(void)
{
	int result_strlen = f_test_strlen();
	int result_strcpy = f_test_strcpy();
	int result_strcmp = f_test_strcmp();

	if (!result_strlen)
		printf("ft_strlen test passed!\n");
	else
		printf("ft_strlen test passed!\n");
	if (!result_strcpy)
		printf("ft_strcpy test passed!\n");
	else
		printf("ft_strcpy test passed!\n");
	if (!result_strcmp)
		printf("ft_strcmp test passed!\n");
	else
		printf("ft_strcmp test passed!\n");
	return (0);
}
