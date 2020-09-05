/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:19:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/09/05 18:56:55 by awerebea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "libasm.h"

void		f_test_strlen(char **s)
{
	char	*f_name = "ft_strlen";
	size_t	res;
	size_t	res_ft;
	printf("\e[1;33m------------ %s ------------\e[0m\n", f_name);
	for (int i = 0; i < 4; i++)
	{
		res = strlen(s[i]);
		res_ft = ft_strlen(s[i]);
		printf("\e[1;33mstring\e[0m: `%s`\n\n\e[1;34mresult std(f)\e[0m: \
%2lu\n\e[1;35mresult ft_(f)\e[0m: %2lu\n", s[i], res, res_ft);
		if (res == res_ft)
			printf("test result: \e[1;32mOK\e[0m\n\n");
		else
			printf("test result: \e[1;31mFAIL\e[0m\n\n");
	}
}

void		f_test_strcpy(char **s)
{
	char	*f_name = "ft_strcpy";
	char	res[1024];
	char	res_ft[1024];

	printf("\e[1;33m------------ %s ------------\e[0m\n", f_name);
	for (int i = 0; i < 4; i++)
	{
		strcpy(res, s[i]);
		ft_strcpy(res_ft, s[i]);
		printf("\e[1;33msource string\e[0m: `%s`\n\n\e[1;34mresult std(f)\e[0m: \
`%s`\n\n\e[1;35mresult ft_(f)\e[0m: `%s`\n", s[i], res, res_ft);
		if (!strcmp(res, res_ft))
			printf("test result: \e[1;32mOK\e[0m\n\n");
		else
			printf("test result: \e[1;31mFAIL\e[0m\n\n");
	}
}

void		f_test_strcmp(char **s)
{
	char	*f_name = "ft_strcmp";
	int		res;
	int		res_ft;

	printf("\e[1;33m------------ %s ------------\e[0m\n", f_name);
	int	j;
	for (int i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			res = strcmp(s[i], s[j]);
			res_ft = ft_strcmp(s[i], s[j]);
			printf("\e[1;33mstring 1\e[0m: `%s`\n\n\e[1;33mstring 2\e[0m: `%s`\n\n\e[1;34mresult \
std(f)\e[0m: %d\n\e[1;35mresult ft_(f)\e[0m: %d\n", s[i], s[j], res, res_ft);
		if (res == res_ft)
			printf("test result: \e[1;32mOK\e[0m\n\n");
		else
			printf("test result: \e[1;31mFAIL\e[0m\n\n");
		}
	}
}

int			main(void)
{
	char	*s[4] = {\
					"", \
					"foo", \
					"foo bar baz 0123456789", \
					"Lorem ipsum dolor sit amet, consectetur adipiscing elit. \
Quisque maximus eros eget nunc blandit commodo. Quisque diam lectus, feugiat \
et nunc sit amet, suscipit imperdiet est. Morbi non felis ut lacus faucibus \
molestie. Duis quis ipsum feugiat ex convallis tempor non nec risus. Aenean \
laoreet lorem at egestas aliquam. Curabitur fermentum, ex ut cursus lacinia, \
nisi diam commodo felis, dignissim sodales turpis augue a lectus. Aliquam erat \
volutpat. Proin pulvinar scelerisque augue, ut feugiat ex volutpat id."\
					};

	f_test_strlen(s);
	/* f_test_strcpy(s); */
	/* f_test_strcmp(s); */

	return (0);
}
