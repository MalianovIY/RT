/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:44:49 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstpst(t_list **lst, t_list *new, unsigned int p)
{
	struct s_list	*s;

	s = *lst;
	if (lst == NULL || *lst == NULL || new == NULL)
		return ;
	if (p != 0)
		while (--p && s != NULL)
			s = s->next;
	new->next = s->next;
	s->next = new;
}
