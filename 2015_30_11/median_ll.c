// median.c
#include <stdio.h>
#include<stdlib.h>
struct test
{
	int input[10];
	int length;
	int output;
}testcase[10] = { { { 1, 2, 3, 4, 5 }, 5, 3 },
{ { 1, 2, 3, 4, 5, 6 }, 6, 3 },
{ { 2, 3, 5 }, 3, 3 },
{ { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 9, 5 }, { { 0, 0, 0, 0 }, 4, 0 },
{ {1,1,1,1,1,1,1,1},8,1 },
{ {2,3,4,5,1,5,7,3,4},9,1 },
{ {1,2},2,1 },
{ {3,2,1},3,2 },
{ { 5, 1, 0, 3, 9, 8, 7, 4, 1, 7 }, 10, 8 } };
struct node
{
	int data;
	struct node *next;
}*newnode = NULL, *temp = NULL;
struct node * createNode(int n1)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = n1;
	newNode->next = NULL;
	return newNode;
}

void create_ll(struct node **head, int p)
{
	struct node *temp = *head;
	if (*head == NULL)
	{
		(*head) = createNode(p);
		(*head)->next = NULL;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = createNode(p);
		temp->next->next = NULL;
	}
}
int *allocate(int *a, int n)
{
	int i;
	int *arr;
	arr = (int *)malloc(n*sizeof(int));
	for (i = 0; i<n; i++)
		arr[i] = a[i];
	return arr;
}
int compare(int a, int b)
{
	if (a == b)  return 1;
	else
		return 0;
}

int median(struct node *head)
{
	struct node *ptr1 = head, *ptr2 = head;
	while (ptr1->next != NULL && ptr1->next->next != NULL)
	{
		ptr1 = ptr1->next->next;
		ptr2 = ptr2->next;
	}
	printf("\n%d", ptr2->data);
	if (ptr1->next == NULL)  return(ptr2->data);
	else
		return((ptr2->data + ptr2->next->data) / 2);
}
int main()
{
	int *input_array,med = 0, i, j, d;
	for (i = 0; i < 10; i++)
	{
		struct node *head = NULL;
		input_array = allocate(testcase[i].input, testcase[i].length);
		for (j = 0; j < testcase[i].length; j++)
		{
			create_ll(&head, input_array[i]);
		}
		med = median(head);
		d = compare(testcase[i].output, med);
		if (d == 1) printf("\nPASSED");
		else printf("\nFAILED");
	}
	return 0;
}

