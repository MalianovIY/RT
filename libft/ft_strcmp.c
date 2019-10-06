/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 21:47:22 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strcmp(const char *c1, const char *c2)
{
	int	o;

	o = *((unsigned char *)c1) - *((unsigned char *)c2);
	while (!(o) && *((unsigned char *)c1) && c1++ && c2++)
		o = *((unsigned char *)c1) - *((unsigned char *)c2);
	return (o);
}
