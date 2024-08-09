/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:06:57 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/25 14:24:23 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*head;

	head = NULL;
	if (lst)
	{
		while (lst)
		{
			lst2 = ft_lstnew(f(lst -> content));
			if (!lst2)
			{
				ft_lstclear(&lst2, del);
				lst = NULL;
				return (NULL);
			}
			ft_lstadd_back(&head, lst2);
			lst = lst -> next;
		}
	}
	return (head);
}
