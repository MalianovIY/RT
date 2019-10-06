/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 04:13:54 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(const char *c)
{
	char	*o;
	char	*o1;
	int		l;

	if (c == NULL)
		return (NULL);
	l = 0;
	while (*c == '\n' || *c == '\t' || *c == ' ')
		c++;
	while (c[l])
		l++;
	if (l)
		while (c[l - 1] == '\n' || c[l - 1] == '\t' || c[l - 1] == ' ')
			l--;
	o = (char *)malloc((l + 1) * sizeof(char));
	o1 = o;
	if (o == NULL)
		return (NULL);
	while (*c)
		*o++ = *c++;
	o1[l] = '\0';
	return (o1);
}
