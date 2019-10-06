/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelemp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 22:17:23 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_lstdelemp(t_list **l, t_list *e)
{
	int		p;
	t_list	*f;

	p = 0;
	if (e == NULL || l == NULL)
		return (-1);
	if (e->content != NULL)
	{
		free(e->content);
		e->content = NULL;
		p = -1;
	}
	f = *l;
	if (f == e)
		*l = (*l)->next;
	else
	{
		while (f && f->next != e)
			if ((f = f->next) == NULL)
				p = -1;
	}
	if (f != NULL)
		f->next = e->next;
	free(e);
	return (p);
}
