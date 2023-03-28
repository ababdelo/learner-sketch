#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int	data;
	struct s_node *next;
}	t_node;

int countlst(t_node *lst)
{
	t_node *head = lst;
	int count = 0;
	while(head != NULL)
	{
		head = head->next;
		count++;
	}
	return(count);
}
t_node *ft_getend(t_node *lst)
{
	t_node *head = lst;

	while(head->next != NULL)
		head = head->next;
	return(head);
}

t_node *get_lst_targ(t_node *lst, int targ)
{
	t_node *head = lst;
	int	cntr = countlst(lst);
	while(targ < cntr && head != NULL)
	{
		cntr--;
		head = head->next;
	}
	return(head);
}

void lst_add_back(t_node *lst,int data)
{
	t_node *lst1 = malloc(sizeof(struct s_node) * 1);
	t_node *ptr;
	lst1->data = data;
	lst1->next = NULL;
	ptr = ft_getend(lst);
	// printf("%p here\n",ptr);
	ptr->next = lst1;
	// printf("here1\n");
}

void	lst_add_front(t_node **lst, int data)
{
	t_node *lst1= malloc(sizeof(t_node));
	lst1->data = data;
	lst1->next = *lst;
	*lst = lst1;
}

void	delete_lst(t_node **lst, t_node *target)
{
	t_node *ptr = *lst;
	t_node *backup;
	while (ptr != NULL && target != NULL)
	{
		if (ptr->next == target)
		{
			backup = ptr->next->next;
			free(target);
			ptr->next = backup;
			break;
		}
		else if (ptr == target)
		{
			*lst = ptr->next;
			free(target);
			break;
		}
		ptr = ptr->next;
	}
}

int main (void)
{
	t_node *lst = malloc(sizeof(struct s_node) * 1);
	lst->data = 0;
	lst->next = NULL;
	int a=1;
	while(a < 10)
		lst_add_back(lst,a++);
	lst_add_front(&lst,-1);
	delete_lst(&lst, get_lst_targ(lst, 11)); 
	t_node *ptr = lst;
	while(ptr != NULL)
	{
		printf("%d\n",ptr->data);
		ptr = ptr->next;
		// printf("%p\n",ptr);
	}
	printf("len : %d\n", countlst(lst));
	// system("leaks a.out");
	return(0);
}