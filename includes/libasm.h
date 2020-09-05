/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awerebea <awerebea@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 10:52:55 by awerebea          #+#    #+#             */
/*   Updated: 2020/09/05 20:48:31 by awerebea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

size_t		ft_strlen(char const *str) asm("_ft_strlen");
char		*ft_strcpy(char * dst, const char * src) asm("_ft_strcpy");
int			ft_strcmp(const char *s1, const char *s2) asm("_ft_strcmp");

#endif
