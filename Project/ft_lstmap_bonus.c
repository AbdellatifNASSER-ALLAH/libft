/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:59:12 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/06 15:34:08 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list	*dup;
	t_list	*temp;

	dup = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&dup, del);
			return (NULL);
		}
		ft_lstadd_back(&dup, temp);
		lst = lst->next;
	}
	return (dup);
}
