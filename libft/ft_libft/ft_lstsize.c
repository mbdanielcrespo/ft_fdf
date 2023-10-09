/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:13:48 by danalmei          #+#    #+#             */
/*   Updated: 2023/04/18 14:05:46 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_i32	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	t_size	c;

	c = 0;
	aux = lst;
	if (!aux)
	{
		return (0);
	}
	while (aux != NULL)
	{
		aux = aux->next;
		c++;
	}
	return (c);
}
