/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:44:49 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdelone(t_list **lst, void (*del) (void *, size_t))
{
	t_list	*next;

	if (*lst == NULL || lst == NULL || del == NULL)
		return ;
	del((void *)(*lst)->content, (*lst)->content_size);
	(*lst)->content_size = 0;
	next = (*lst)->next;
	free(*lst);
	*lst = next;
}
