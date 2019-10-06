/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:39:38 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char		*i;
	const char	*s0;

	s0 = s2;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(*s2))
		return ((char *)s1);
	while (*s1)
	{
		if (*s1 == *s2)
		{
			i = (char *)s1;
			while (*(++s1) == *(++s2) && *s1)
				;
			if (!(*s2))
				return (i);
			s2 = s0;
			s1 = i;
		}
		s1++;
	}
	return (NULL);
}
