/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:59:12 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/08 14:19:37 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		if (lst->content)
		{
			new_content = f(lst->content);
			node = ft_lstnew(new_content);
			if (!node)
			{
				del(new_content);
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, node);
		}
		lst = lst->next;
	}
	return (head);
}
