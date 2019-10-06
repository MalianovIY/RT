/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:44:49 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *el))
{
	t_list	*nlst;
	t_list	*out;
	t_list	*i;

	if (lst == NULL || f == NULL)
		return (NULL);
	nlst = f(lst);
	out = nlst;
	lst = lst->next;
	while (lst != NULL)
	{
		i = f(lst);
		nlst->next = i;
		nlst = i;
		lst = lst->next;
	}
	return (out);
}
