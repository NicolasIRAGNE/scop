/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:17:25 by iburel            #+#    #+#             */
/*   Updated: 2017/12/17 20:03:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <unistd.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*new_list;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		ft_lstaddlast(&new_list, f(lst));
		lst = lst->next;
	}
	return (new_list);
}
