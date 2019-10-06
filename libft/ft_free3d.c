/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 00:19:42 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_free3d(void ****x)
{
	unsigned char ***i;
	unsigned char ***c;

	if (x == NULL)
		return (NULL);
	c = *((unsigned char ****)x);
	i = c - 1;
	while (*(++i))
		ft_free2d((void ***)&i);
	if (c != NULL)
		free(c);
	return (NULL);
}
