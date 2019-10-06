/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:19:38 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char buff[2];

	if ((unsigned char)c <= 127)
		write(fd, &c, 1);
	else
	{
		buff[0] = 128 + 64 + ((unsigned char)c / 64);
		buff[1] = ((unsigned char)c % 64) + 128;
		write(fd, buff, 2);
	}
}
