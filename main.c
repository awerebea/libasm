/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:19:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/09/03 18:31:31 by awerebea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

size_t		ft_strlen(char const *str);
char		*ft_strcpy(char * dst, const char * src);

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

	char	*s[6] = {"", "1", "21", "foo", "foo bar", \
									"foo bar baz 0123456789"};
	printf("\n------------ ft_strcpy ------------\n");
	for (int i = 0; i < 6; i++)
	{
		printf("Source string:\t`%s`\n", s[i]);
		ft_strcpy(d, s[i]);
		printf("Dest ft_strcpy:\t`%s`\n", d);
		strcpy(d, s[i]);
		printf("Dest strcpy:\t`%s`\n\n", d);
	}
}

int			main(void)
{
	f_test_strlen();
	f_test_strcpy();
	return (0);
}
