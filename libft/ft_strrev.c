/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:19:38 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrev(char *s)
{
	char	*a;
	char	*b;

	a = s;
	if (s == NULL)
		return (NULL);
	b = s + ft_strlen(s) - 1;
	while (a < b)
		ft_memswap(a++, b--, 1 * sizeof(char));
	return (s);
}
