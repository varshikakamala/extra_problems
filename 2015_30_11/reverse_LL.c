//sort2
#include <stdio.h>
#include<stdlib.h>
struct test
{
	int input[10];
	int length;
	int output[10];
}testcase[10] = { { { 1, 2, 7, 20, 15, 10 }, 6, { 10, 15, 20, 7, 2, 1 } },
{ { -9, -6, -2, 0, 5, 4, 3, 2, 1 }, 9, { 1, 2, 3, 4, 5, 0, -2, -6, -9 } },
{ { 0, 1, 2, 4, 3 }, 5, { 3, 4, 2, 1, 0 } },
{ { 1, 2, 3, 7, 6, 5 }, 6, { 5, 6, 7, 3, 2, 1 } },
{ { 0, 0, 0, 1, 0 }, 5, { 0, 1, 0, 0, 0 } },
{ { 2, 0, 4, 5, 7, 8, 9, 4, 5 }, 9, { 5, 4, 9, 8, 7, 5, 4, 0, 2 } },
{ { -6, -5, -4, -2, -1, -7, 0, -6 }, 8, { -6, 0, -7, -1, -2, -4, -5, -6 } },
{ { 0, 0, 0, 0, 0, 0, 0 }, 7, { 0, 0, 0, 0, 0, 0, 0 } },
{ { 1, 2, 5, 4, 3 }, 5, { 3, 4, 5, 2, 1 } },
{ { 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1 }, 12, { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0 } } };
struct node
{
	int data;
	struct node *next;
};
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
int compare(int *nums, int len, struct node *head)
{
	int index = 0;
	struct node *temp = head;
	for (index = 0; index < len; index++)
	{
		if (temp->data != nums[index])
			return  0;
		temp = temp->next;
	}
	return 1;
}
struct node *reverse_LL(struct node *head)
{
	struct node *ptr = NULL;
	if (head == NULL || head->next == NULL)  return head;
	else
	{
		ptr = reverse_LL(head->next);
		head->next->next = head;
		head->next = NULL;
		return ptr;
	}
}


int main()
{
	int *input_array, *output_array, i, j, d;
	for (i = 0; i < 10; i++)
	{
		struct node *head = NULL;
		input_array = allocate(testcase[i].input, testcase[i].length);
		output_array = allocate(testcase[i].output, testcase[i].length);
		for (j = 0; j < testcase[i].length; j++)
		{
			create_ll(&head, input_array[i]);
		}
		head = reverse_LL(head);
		d = compare(testcase[i].output, testcase[i].length, head);
		if (d == 1) printf("\nPASSED");
		else printf("\nFAILED");
	}
	return 0;
}

