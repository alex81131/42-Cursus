//#include "../../subjects/list.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int a;
	t_list *result = lst;

	while (lst->next)
	{
		if ((cmp(lst->data, lst->next->data)) == 0)
		{
			a = lst->data;
			lst->data = lst->next->data;
			lst->next->data = a;
			lst = result;
		}
		else
			lst = lst->next;
	}
	lst = result;
	return (lst);
}

/*
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*node1 = lst;
	t_list	*node2;
	int	a;

	while (node1)
	{
		node2 = node1->next;
		while (node2)
		{
			if (cmp(node1->data, node2->data) == 0)
			{
				a = node1->data;
				node1->data = node2->data;
				node2->data = a;
			}
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (lst);
}
*/
/*
int compare_ints(int a, int b) {
	return (a <= b); // Ascending order: <=, Descending order: >=
}

void test_sort_list()
{
	// Create sample linked list nodes
	t_list *node1 = malloc(sizeof(t_list));
	node1->data = 5;
	node1->next = malloc(sizeof(t_list));

	t_list *node2 = node1->next;
	node2->data = 8;
	node2->next = malloc(sizeof(t_list));

	t_list *node3 = node2->next;
	node3->data = 2;
	node3->next = NULL; // Terminate the list

	// Print the unsorted list
	printf("Unsorted list: ");
	t_list *temp = node1;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");

	// Sort the list
	t_list *sorted_list = sort_list(node1, compare_ints);

	// Print the sorted list
	printf("Sorted list: ");
	temp = sorted_list;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");

	// Free the allocated memory for the linked list nodes
	free(node3);
	free(node2);
	free(node1);
}

int main()
{
	test_sort_list();
	return 0;
}
*/