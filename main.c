/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:19:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/09/03 17:28:31 by awerebea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*
** Function prototypes
*/
size_t		ft_strlen(char const *str);

void		f_test_strlen(void)
{
	char	*s;

	printf("\n------------ ft_strlen ------------\n");
	s = strdup("");
	printf("%2lu (%2lu) : `%s`\n", ft_strlen(s), strlen(s), s);
	s = strdup("1");
	printf("%2lu (%2lu) : `%s`\n", ft_strlen(s), strlen(s), s);
	s = strdup("21");
	printf("%2lu (%2lu) : `%s`\n", ft_strlen(s), strlen(s), s);
	s = strdup("foo");
	printf("%2lu (%2lu) : `%s`\n", ft_strlen(s), strlen(s), s);
	s = strdup("foo bar");
	printf("%2lu (%2lu) : `%s`\n", ft_strlen(s), strlen(s), s);
	s = strdup("foo bar baz 0123456789");
	printf("%2lu (%2lu) : `%s`\n", ft_strlen(s), strlen(s), s);
}

int			main(void)
{
	f_test_strlen();
	return (0);
}
