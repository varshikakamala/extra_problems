//sort2
#include <stdio.h>
#include<stdlib.h>
struct test
{
	int input[10];
	int length;
	int output[10];
}testcase[10] = { { { 1, 2, 7, 20, 15, 10 }, 6, { 1, 2, 7, 10, 15, 20 } },
{ { -9, -6, -2, 0, 5, 4, 3, 2, 1 }, 9, { -9, -6, -2, 0, 1, 2, 3, 4, 5 } },
{ { 0, 1, 2, 4, 3 }, 5, { 0, 1, 2, 3, 4 } },
{ { 1, 2, 3, 7, 6, 5 }, 6, { 1, 2, 3, 5, 6, 7 } },
{ { 0, 0, 0, 1, 0 }, 5, { 0, 0, 0, 0, 0, 1 } },
{ {-2,-1,0,5,4,3}, 6, {-2,-1,0,3,4,5} },
{ {-9,-8,-7,-6,-5,-2,-3,-4}, 8, {-9,-8,-7,-6,-5,-4,-3,-2} },
{ {-7,-5,-2,5,3,2}, 6, {-7,-5,-2,2,3,5} },
{ {-3,-2,-1,3,2,1}, 6, {-3,-2,-1,1,2,3} },
{ {2,3,5,4}, 4, {2,3,4,5} } };
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
struct node *sort2(struct node *head)
{
	struct node *ptr1=head, *ptr2 =NULL,*prev=NULL;
	while (ptr1 != NULL)
	{
		if (ptr1->data < ptr1->next->data)
		{
			prev = ptr1;
			ptr1 = ptr1->next;
		}
		else
		{
			ptr2 = prev->next;
			ptr1 = ptr1 ->next;
		
		}
	}
	prev->next = reverse_LL(ptr2);
	prev = head;
	return head;
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
		head = sort2(head);
		d = compare(testcase[i].output, testcase[i].length, head);
		if (d == 1) printf("\nPASSED");
		else printf("\nFAILED");
	}
	return 0;
}

