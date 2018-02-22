/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:16:33 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 20:02:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <unistd.h>

void	ft_lstaddlast(t_list **lst, t_list *add)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = add;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = add;
}
