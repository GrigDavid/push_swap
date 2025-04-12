/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:18:46 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/02/07 17:20:49 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			len;
	unsigned char	*p;

	len = ft_strlen(s);
	p = (unsigned char *)s;
	while ((unsigned char *)s + len >= p)
	{
		if (*p == (unsigned char)c)
			return ((char *)p);
		p++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
