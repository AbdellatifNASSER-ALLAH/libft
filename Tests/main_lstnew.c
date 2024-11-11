#include "head.h"

int main()
{
	t_list *node;
	t_list *node1; t_list *head;
	node  = ft_lstnew("B");
	node1  = ft_lstnew("C");
	head  = NULL;

	ft_lstadd_front(&head,node1);
	ft_lstadd_front(&head,node);

	t_list *p;
	p = head;
	while(p)
	{
		printf("%s -> ",p->content);
		p=p->next;
	}
	printf("(NULL)");
}
