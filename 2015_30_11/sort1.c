//sort1
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
struct test
{
	int input[10];
	int length;
	int output[10];
}testcase[10] = { { {1,2,7,25,20,10}, 6, { 1, 2, 7, 10, 20, 25 } },
{ {-9,-6,-2,0,2,1,3,4,5}, 9, { -9, -6, -2, 0, 1, 2, 3, 4, 5 } },
{ {4,1,2,3,0}, 5, { 0, 1, 2, 3, 4 } },
{ {1,7,3,5,6,2}, 6, { 1, 2, 3, 5, 6, 7 } },
{ {-9,-6,0,-5,1}, 5, { -9,-6,-5,0, 1 } },
{ {-9,-8,-7,-4,-5,-6},6 , {-9,-8,-7,-6,-5,-4} },
{{-5,-8,-7,-6,-9},5,{-9,-8,-7,-6,-5} },
{ {9,4,7,6,5,8,3,2},8 , {9,8,7,6,5,4,3,2} },
{ {1,8,4,5,6,7,3}, 7, {1,3,4,5,6,7,8} },
{ {2,3,5,4,6}, 5, {2,3,4,5,6} } };
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
struct node *sort1(struct node *head)
{
	struct node *ptr1 = head, *ptr2 = head,*ptr3=NULL;
	int count = 0,temp=0;
	while (ptr1 != NULL)
	{
		if (ptr1->data < ptr1->next->data)
			ptr1 = ptr1->next;
		else
		{
			count++;
			if (count == 1)
				ptr2 = ptr1;
			else if (count == 2)
				ptr3 = ptr1->next;
			ptr1 = ptr1->next;
		}
	}
	if (ptr3 == NULL) 
		ptr3 = ptr2->next;
	temp = ptr2->data;
	ptr2->data = ptr3->data;
	ptr3->data = temp;
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
		head = sort1(head);
		d = compare(testcase[i].output, testcase[i].length, head);
		if (d == 1) printf("\nPASSED");
		else printf("\nFAILED");
	}
	return 0;
}

