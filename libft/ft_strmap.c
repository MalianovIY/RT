/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 21:47:22 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *a, char (*f)(char))
{
	char	*b;
	char	*c;
	int		len;

	if (a == NULL || f == NULL)
		return (NULL);
	len = 0;
	while (a[len])
		len++;
	b = (char *)malloc((len + 1) * sizeof(char));
	if (b == NULL)
		return (NULL);
	c = b;
	while (*a)
		*b++ = f((char)*a++);
	*b = '\0';
	return (c);
}
