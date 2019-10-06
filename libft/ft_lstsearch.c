/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 20:33:05 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/16 02:08:46 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstsearch(t_list *list, int (*f)(void *data, t_list elem), void *d)
{
	t_list	*l;

	if (f == NULL || list == NULL || d == NULL)
		return (NULL);
	l = list;
	while (l != NULL)
	{
		if (f(d, *l) == 1)
			return (l);
		l = l->next;
	}
	return (NULL);
}
