/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:44:49 by ahorker           #+#    #+#             */
/*   Updated: 2019/01/13 22:08:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *con, size_t sc)
{
	t_list			*lst;
	unsigned char	*data;

	lst = (t_list *)ft_memalloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	if (con == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
		return (lst);
	}
	data = NULL;
	if (sc != 0)
	{
		data = (unsigned char *)ft_memalloc(sc);
		if (data == NULL)
			return (NULL);
		ft_memcpy((void *)data, con, sc);
	}
	lst->content = (void *)data;
	lst->content_size = sc;
	lst->next = NULL;
	return (lst);
}
