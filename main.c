/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:19:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/09/04 15:38:50 by awerebea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

size_t		ft_strlen(char const *str);
char		*ft_strcpy(char * dst, const char * src);
int			ft_strcmp(const char *s1, const char *s2);

void		f_test_strlen(void)
{
	char	*s[6] = {"", "1", "21", "foo", "foo bar", \
									"foo bar baz 0123456789"};
	printf("\n------------ ft_strlen ------------\n");
	for (int i = 0; i < 6; i++)
		printf("%2lu (%2lu) : `%s`\n", ft_strlen(s[i]), strlen(s[i]), s[i]);
}

void		f_test_strcpy(void)
{
	char	d[50];
	char	d_ft[50];
	int		k = 0;

	char	*s[6] = {"", "1", "21", "foo", "foo bar", \
									"foo bar baz 0123456789"};
	printf("\n------------ ft_strcpy ------------\n");
	for (int i = 0; i < 6; i++)
	{
		printf("source string\t: `%s`\n", s[i]);
		ft_strcpy(d_ft, s[i]);
		printf("result ft_strcpy: `%s`\n", d_ft);
		strcpy(d, s[i]);
		printf("result strcpy\t: `%s`\n", d);
		if (!(strcmp(d_ft, d)))
		{
			printf("OK\n\n");
			k++;
		}
		else
			printf("FAIL\n\n");
	}
	if (k == 6)
		printf("ft_strcpy test passed!\n\n");
	else
		printf("ft_strcpy test passed!\n\n");
}

void		f_test_strcmp(void)
{
	int		res;
	int		res_ft;
	char	*s1[6] = {"", "1", "21", "foo", "foo bar", \
									"foo bar baz 0123456789"};
	char	*s2[6] = {"", "1", "21", "foo", "foo bar", \
									"foo bar baz 0123456789"};
	printf("\n------------ ft_strcmp ------------\n");
	int	j;
	for (int i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			printf("string 1:\t`%s`\nstring 2:\t`%s`\n", s1[i], s2[j]);
			res = strcmp(s1[i], s2[j]);
			res_ft = ft_strcmp(s1[i], s2[j]);
			printf("result ft_strcmp: %d\n", res_ft);
			printf("result strcmp\t: %d\n\n", res);
		}
	}
}

int			main(void)
{
	f_test_strlen();
	f_test_strcpy();
	f_test_strcmp();
	return (0);
}
