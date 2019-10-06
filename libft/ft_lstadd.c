/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:44:49 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/19 19:30:21 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstadd(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
