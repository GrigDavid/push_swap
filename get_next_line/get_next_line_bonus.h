/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:01:02 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/02/14 17:30:41 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
void	ft_free(char **str);
int		ft_strlen(const char *s);
int		ft_first(char *buff);
int		ft_next(char *buff);
char	*ft_cut(char *buff, int first);
char	*ft_join(char *str, char *buff);
void	ft_bzero(void *s, int n);

char	*ft_join_f(char *str, char *buff);

#endif
