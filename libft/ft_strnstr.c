/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:39:38 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char		*i;
	char		*s0;
	size_t		n0;

	if ((s0 = (char *)s2) && s2 == NULL)
		return ((char *)s1);
	if (s1 == NULL)
		return (NULL);
	while (*s1 && n--)
	{
		if (*s1 == *s2)
		{
			i = (char *)s1;
			n0 = n;
			while (*(++s1) == *(++s2) && *s1 && n)
				n--;
			if (!(*s2))
				return (i);
			s2 = s0;
			s1 = i;
			n = n0;
		}
		s1++;
	}
	return (NULL);
}
