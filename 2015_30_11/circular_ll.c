//CIRCULAR_LL
#include <stdio.h>
#include<stdlib.h>
struct test
{
	int input[10];
	int length;
	int number;
	int output[11];
}testcase[10] = { { { 1, 2, 3, 4, 6 }, 5, 5, { 1, 2, 3, 4, 5, 6 } },
{ { 1, 3, 4, 5, 6 }, 5, 2, { 1, 2, 3, 4, 5, 6 } },
{ { 2, 3, 5 }, 3, 1, { 1, 2, 3, 5 } },
{ { 1, 2, 3, 4, 5, 6, 7, 8 }, 8, 9, { 1, 2, 3, 4, 5, 6, 7, 8, 9 } },
{ { 0, 0, 0, 0 }, 4, 1, { 0, 0, 0, 0, 1 } },
{{2,3,4,5,6,9},6,7,{2,3,4,5,6,7,9} },
{ {2,3,4,5,6,7,8,9},8 ,1, {1,2,3,4,5,6,7,8,9} }, 
{ {1,2,3,4,5,6,7,8},8 ,9, {1,2,3,4,5,6,7,8,9} }, 
{ {1,2,3,4}, 4,1, {1,1,2,3,4} }, 
{ {1,2,3,4,5},5,5 , {1,2,3,4,5,5} }};
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
struct node *circular_ll(struct node *head,int num)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	struct node *ptr=NULL,*last=head,*prev=NULL;
	ptr = head;
	while (last->next!= NULL)  last = last->next;
	newnode->data = num;
	if (num<ptr->data || num>last->data)
	{
		newnode->next = ptr;
		last->next = newnode;
		head = newnode;
	}
	else
	{
		while (ptr->next != head)
		{
			if (num > ptr->data)
			{
				prev = ptr;
				ptr = ptr->next;
			}
			else if (num == ptr->data)
			{
				newnode->next = ptr->next;
				ptr->next = newnode;
			}
			else
			{

				prev->next = newnode;
				newnode->next = ptr;
			}
		}
	}
	return head;
}

int main()
{
	int *input_array,*output_array, i, j, d;
	for (i = 0; i < 10; i++)
	{
		struct node *head = NULL;
		input_array = allocate(testcase[i].input, testcase[i].length);
		output_array = allocate(testcase[i].output, testcase[i].length+1);
		for (j = 0; j < testcase[i].length; j++)
		{
			create_ll(&head, input_array[i]);
		}
		head = cicular_ll(head,testcase[i].number);
		d = compare(testcase[i].output,testcase[i].length+1,head);
		if (d == 1) printf("\nPASSED");
		else printf("\nFAILED");
	}
	return 0;
}

