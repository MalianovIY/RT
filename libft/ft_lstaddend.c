/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:44:49 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstaddend(t_list *lst, t_list *new)
{
	struct s_list	*s;

	s = lst;
	if (new == NULL)
		return (NULL);
	if (lst == NULL)
	{
		s = new;
		s->next = NULL;
		return (s);
	}
	while (s->next != NULL)
		s = s->next;
	s->next = new;
	return (s->next);
}
