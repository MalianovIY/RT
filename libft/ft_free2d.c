/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:05:31 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_free2d(void ***x)
{
	unsigned char **i;
	unsigned char **c;

	c = *((unsigned char ***)x);
	i = c - 1;
	if (x != NULL)
	{
		while (*(++i))
			free(*i);
		free(c);
	}
	return (NULL);
}
