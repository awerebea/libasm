/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:19:07 by ncolomer          #+#    #+#             */
/*   Updated: 2020/09/06 15:55:04 by awerebea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "libasm.h"

void		f_test_strlen(char **s)
{
	size_t	res;
	size_t	res_ft;
	printf("\e[1;33m------------ ft_strlen ------------\e[0m\n");
	for (int i = 0; i < 4; i++)
	{
		res = strlen(s[i]);
		res_ft = ft_strlen(s[i]);
		printf("\e[1;33mstring\e[0m: `%s`\n\n\e[1;34mresult std(f)\e[0m: \
%2lu\n\e[1;35mresult ft_(f)\e[0m: %2lu\n\n", s[i], res, res_ft);
	}
}

void		f_test_strcpy(char **s)
{
	char	res[1024];
	char	res_ft[1024];

	printf("\e[1;33m------------ ft_strcpy ------------\e[0m\n");
	for (int i = 0; i < 4; i++)
	{
		strcpy(res, s[i]);
		ft_strcpy(res_ft, s[i]);
		printf("\e[1;33msource string\e[0m: `%s`\n\n\e[1;34mresult std(f)\e[0m: \
`%s`\n\n\e[1;35mresult ft_(f)\e[0m: `%s`\n\n", s[i], res, res_ft);
	}
}

void		f_test_strcmp(char **s)
{
	int		res;
	int		res_ft;

	printf("\e[1;33m------------ ft_strcmp ------------\e[0m\n");
	int	j;
	for (int i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			res = strcmp(s[i], s[j]);
			res_ft = ft_strcmp(s[i], s[j]);
			printf("\e[1;33mstring 1\e[0m: `%s`\n\n\e[1;33mstring 2\e[0m: \
`%s`\n\n\e[1;34mresult std(f)\e[0m: %d\n\e[1;35mresult ft_(f)\e[0m: %d\n\n", \
s[i], s[j], res, res_ft);
		}
	}
}

int			f_test_write(char **s)
{
	int		fd_file_1;
	int		fd_file_2;
	int		ret_val;
	printf("\e[1;33m------------ ft_write ------------\e[0m\n");

	if ((fd_file_1 = open("test_std.txt", O_RDWR | O_CREAT | O_TRUNC, 0664)) < 0)
		return (fd_file_1);
	if ((fd_file_2 = open("test_ft.txt", O_RDWR | O_CREAT | O_TRUNC, 0664)) < 0)
		return (fd_file_2);

	printf("\n\e[1;33mbuffer\e[0m: `%s`\n", "");
	printf("\e[1;33mfd\e[0m: %d\t\e[1;33mbytes to write\e[0m: %d\n\n", -1, 10);
	printf("\e[1;34mresult std(f)\e[0m:\n");
	errno = 0;
	ret_val = write(-1, "", 10);
	printf("\n\e[1;34mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;34merrno\e[0m: %d\e[1;34m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\n\e[1;35mresult ft_(f)\e[0m:\n");
	errno = 0;
	ret_val = ft_write(-1, "", 10);
	printf("\n\e[1;35mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;35merrno\e[0m: %d\e[1;35m error string\e[0m: %s\n", \
			errno, strerror(errno));

	printf("\n\e[1;33mbuffer\e[0m: `%s`\n", "");
	printf("\e[1;33mfd\e[0m: %d\t\e[1;33mbytes to write\e[0m: %d\n\n", 1, 5);
	printf("\e[1;34mresult std(f)\e[0m:\n");
	errno = 0;
	ret_val = write(1, "", 5);
	printf("\n\e[1;34mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;34merrno\e[0m: %d\e[1;34m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\n\e[1;35mresult ft_(f)\e[0m:\n");
	errno = 0;
	ret_val = ft_write(1, "", 5);
	printf("\n\e[1;35mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;35merrno\e[0m: %d\e[1;35m error string\e[0m: %s\n", \
			errno, strerror(errno));

	printf("\n\e[1;33mbuffer\e[0m: `%s`\n", "foo bar baz 0123456789");
	printf("\e[1;33mfd\e[0m: %d\t\e[1;33mbytes to write\e[0m: %d\n\n", 1, 22);
	printf("\e[1;34mresult std(f)\e[0m:\n");
	errno = 0;
	ret_val = write(1, "foo bar baz 0123456789", 22);
	printf("\n\e[1;34mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;34merrno\e[0m: %d\e[1;34m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\n\e[1;35mresult ft_(f)\e[0m:\n");
	errno = 0;
	ret_val = ft_write(1, "foo bar baz 0123456789", 22);
	printf("\n\e[1;35mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;35merrno\e[0m: %d\e[1;35m error string\e[0m: %s\n", \
			errno, strerror(errno));

	printf("\n\e[1;33mbuffer\e[0m: `%s`\n", "foo bar baz 0123456789");
	printf("\e[1;33mfd\e[0m: %d\t\e[1;33mbytes to write\e[0m: %d\n\n", 1, -15);
	printf("\e[1;34mresult std(f)\e[0m:\n");
	errno = 0;
	ret_val = write(1, "foo bar baz 0123456789", -15);
	printf("\n\e[1;34mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;34merrno\e[0m: %d\e[1;34m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\n\e[1;35mresult ft_(f)\e[0m:\n");
	errno = 0;
	ret_val = ft_write(1, "foo bar baz 0123456789", -15);
	printf("\n\e[1;35mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;35merrno\e[0m: %d\e[1;35m error string\e[0m: %s\n", \
			errno, strerror(errno));

	printf("\n\e[1;33mbuffer\e[0m: `%s`\n", "foo bar baz 0123456789");
	printf("\e[1;33mfd\e[0m: %d\t\e[1;33mbytes to write\e[0m: %d\n\n", 543, 15);
	printf("\e[1;34mresult std(f)\e[0m:\n");
	errno = 0;
	ret_val = write(543, "foo bar baz 0123456789", 15);
	printf("\n\e[1;34mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;34merrno\e[0m: %d\e[1;34m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\n\e[1;35mresult ft_(f)\e[0m:\n");
	errno = 0;
	ret_val = ft_write(543, "foo bar baz 0123456789", 15);
	printf("\n\e[1;35mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;35merrno\e[0m: %d\e[1;35m error string\e[0m: %s\n", \
			errno, strerror(errno));

	printf("\n\e[1;33mwrite to file test:\nbuffer\e[0m: `%s`\n", s[3]);
	printf("\e[1;33mfd\e[0m: %d\t\e[1;33mbytes to write\e[0m: %d\n", fd_file_1, 512);
	errno = 0;
	ret_val = write(fd_file_1, s[3], 512);
	printf("\e[1;34mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;34merrno\e[0m: %d\e[1;34m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\e[1;33mfd\e[0m: %d\t\e[1;33mbytes to write\e[0m: %d\n", fd_file_2, 512);
	errno = 0;
	ret_val = ft_write(fd_file_2, s[3], 512);
	printf("\e[1;35mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;35merrno\e[0m: %d\e[1;35m error string\e[0m: %s\n", \
			errno, strerror(errno));

	close(fd_file_1);
	close(fd_file_2);
	return (0);
}

int			f_test_read(char **s)
{
	int		fd_file;
	int		ret_val;
	char	buffer[512];

	printf("\n\e[1;33m------------ ft_read ------------\e[0m\n");

	bzero(buffer, 512);
	printf("\n\e[1;33mread from stdin into buffer\e[0m:\n");
	printf("\e[1;33mfd\e[0m: %d\t\e[1;33mbytes to read\e[0m: %d\n\n", 0, 512);
	errno = 0;
	ret_val = read(0, buffer, 512);
	printf("\e[1;34mresult std(f)\e[0m:\n");
	printf("\e[1;34mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;34merrno\e[0m: %d\e[1;34m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\e[1;34mreaded text\e[0m: %s\n", buffer);
	bzero(buffer, 512);
	errno = 0;
	ret_val = ft_read(0, buffer, 512);
	printf("\e[1;35mresult ft_(f)\e[0m:\n");
	printf("\e[1;35mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;35merrno\e[0m: %d\e[1;35m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\e[1;35mreaded text\e[0m: %s\n", buffer);

	bzero(buffer, 512);
	printf("\n\e[1;33mread from negative fd into buffer\e[0m:\n");
	printf("\e[1;33mfd\e[0m: %d\t\e[1;33mbytes to read\e[0m: %d\n\n", -1, 512);
	errno = 0;
	ret_val = read(-1, buffer, 512);
	printf("\e[1;34mresult std(f)\e[0m:\n");
	printf("\e[1;34mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;34merrno\e[0m: %d\e[1;34m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\e[1;34mreaded text\e[0m: %s\n", buffer);
	bzero(buffer, 512);
	errno = 0;
	ret_val = ft_read(-1, buffer, 512);
	printf("\e[1;35mresult ft_(f)\e[0m:\n");
	printf("\e[1;35mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;35merrno\e[0m: %d\e[1;35m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\e[1;35mreaded text\e[0m: %s\n", buffer);

	bzero(buffer, 512);
	printf("\n\e[1;33mread from stdin into buffer negative number of bytes\e[0m:\n");
	printf("\e[1;33mfd\e[0m: %d\t\e[1;33mbytes to read\e[0m: %d\n\n", 0, -512);
	errno = 0;
	ret_val = read(0, buffer, -512);
	printf("\e[1;34mresult std(f)\e[0m:\n");
	printf("\e[1;34mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;34merrno\e[0m: %d\e[1;34m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\e[1;34mreaded text\e[0m: %s\n", buffer);
	bzero(buffer, 512);
	errno = 0;
	ret_val = ft_read(0, buffer, -512);
	printf("\e[1;35mresult ft_(f)\e[0m:\n");
	printf("\e[1;35mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;35merrno\e[0m: %d\e[1;35m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\e[1;35mreaded text\e[0m: %s\n", buffer);

	if ((fd_file = open("test_read.txt", O_RDWR | O_CREAT | O_TRUNC, 0664)) < 0)
		return (fd_file);
	if ((ret_val = write(fd_file, s[3], 512)) < 0)
		return (ret_val);
	close(fd_file);

	if ((fd_file = open("test_read.txt", O_RDONLY)) < 0)
		return (fd_file);
	bzero(buffer, 512);
	printf("\n\e[1;33mread from file 'test_std.txt' into buffer\e[0m:\n");
	printf("\e[1;33mfd\e[0m: %d\t\e[1;33mbytes to read\e[0m: %d\n\n", fd_file, 512);
	errno = 0;
	ret_val = read(fd_file, buffer, 512);
	printf("\e[1;34mresult std(f)\e[0m:\n");
	printf("\e[1;34mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;34merrno\e[0m: %d\e[1;34m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\e[1;34mreaded text\e[0m: %s\n", buffer);
	close(fd_file);
	if ((fd_file = open("test_read.txt", O_RDONLY)) < 0)
		return (fd_file);
	printf("\n\e[1;33mfd\e[0m: %d\t\e[1;33mbytes to read\e[0m: %d\n\n", fd_file, 512);
	bzero(buffer, 512);
	errno = 0;
	ret_val = ft_read(fd_file, buffer, 512);
	printf("\e[1;35mresult ft_(f)\e[0m:\n");
	printf("\e[1;35mreturned value\e[0m: %d", ret_val);
	printf(" \e[1;35merrno\e[0m: %d\e[1;35m error string\e[0m: %s\n", \
			errno, strerror(errno));
	printf("\e[1;35mreaded text\e[0m: %s\n", buffer);
	bzero(buffer, 512);

	close(fd_file);
	return (0);
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

	if(s[0])
	{
		;
	}
	/* f_test_strlen(s); */
	/* f_test_strcpy(s); */
	/* f_test_strcmp(s); */
	/* f_test_write(s); */
	f_test_read(s);

	return (0);
}
