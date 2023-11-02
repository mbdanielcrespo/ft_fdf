/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:13:48 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/23 18:23:57 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_nw(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_ele;

	new_ele = ft_lstnew((f)(lst->content));
	if (!new_ele)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	return (new_ele);
}

t_list	*ft_lstmap(t_list *lst, void*(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_ele;

	if (!lst || !f)
		return (NULL);
	new_ele = ft_nw(lst, f, del);
	if (!new_ele)
		return (NULL);
	new_lst = new_ele;
	lst = lst->next;
	while (lst != NULL)
	{
		new_ele = ft_lstnew((f)(lst->content));
		if (!new_ele)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_lst, del);
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_ele);
	}
	return (new_lst);
}
