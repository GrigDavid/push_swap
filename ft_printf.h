/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:40:37 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/02/07 17:19:07 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_printchar(int c);
int		ft_printstr(char *s);
int		ft_printnbr(long n);
int		ft_print_x(unsigned long n, int up);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif
