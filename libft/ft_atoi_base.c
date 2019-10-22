/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 01:36:55 by ahorker           #+#    #+#             */
/*   Updated: 2019/10/10 01:36:55 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_iswhitespace(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
			|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

static int	base(int c, int base)
{
	char	str[17];
	char	str2[17];
	int		i;

	ft_strcpy(str, "0123456789abcdef");
	ft_strcpy(str2, "0123456789ABCDEF");
	i = -1;
	while (++i < base)
		if (c == str[i] || c == str2[i])
			return (i);
	return (-1);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int	nb;
	int	p;
	int	i;

	i = 0;
	nb = 0;
	p = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			p = 1;
		i++;
	}
	while (base(str[i], str_base) != -1)
	{
		nb = nb * str_base;
		nb = nb + base(str[i], str_base);
		i++;
	}
	if (p)
		return (-nb);
	return (nb);
}
