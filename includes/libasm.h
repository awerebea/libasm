/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awerebea <awerebea@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 10:52:55 by awerebea          #+#    #+#             */
/*   Updated: 2020/09/06 14:35:36 by awerebea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

size_t		ft_strlen(char const *str);
char		*ft_strcpy(char * dst, const char * src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);

#endif
