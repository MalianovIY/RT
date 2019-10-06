/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 04:14:35 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *d, int c)
{
	if (d == NULL)
		return (NULL);
	while ((*d != (char)c) && *d)
		d++;
	if (*d == (char)c)
		return ((char *)d);
	return (NULL);
}
