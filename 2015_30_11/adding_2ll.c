//adding2ll
#include <stdio.h>
#include<stdlib.h>
struct test
{
	int input1[10];
	int length1;
	int input2[10];
	int length2;
	int output[20];
}testcase[10] = { { { 0, 1, 2, 3, 4 }, 5, { 1, 2, 3, 4, 5 }, 5, {1,3,5,7,9} },
{ { 0, 1 }, 2, { 1, 2, 3 }, 3, {1,3,4} },
{ { 1, 2, 3 }, 3, { 1, 2 }, 2, {2,4,3} },
{ {1}, 1, {1}, 1, {1} },
{ {0}, 1, { 1, 2, 3 }, 3, {1,2,3} },
{ { 1, 2, 3 }, 3, { 0 }, 0, { 1, 2, 3 } },
{ {1,2,3,4,5,6,7}, 7, {0,0,0,0,0,0,0}, 7, {1,2,3,4,5,6,7} },
{ {0,0,0,0,0,0,0}, 7, {1,2,3,4,5,6,7}, 7, {1,2,3,4,5,6,7} },
{ {0,1,1,1,1}, 5, {0,2,2,2,2}, 5,{0,3,3,3,3}},
{ { 2, 2, 2 }, 3, { 1, 1, 1 }, 3, { 3, 3, 3, } } };
struct node
{
	int data;
	struct node *next;
}*newnode = NULL, *temp = NULL, *head1 = NULL, *head2 = NULL;
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

struct node * add_2LL(struct node *head1, struct node *head2)
{
	struct node *ptr1 = head1, *ptr2 = head2;
	if (head1 == NULL && head2 != NULL) return head2;
	else if (head2 == NULL && head1 != NULL) return head1;
	else if (head1 == NULL && head2 == NULL) return NULL;
	while (ptr1 != NULL)
	{
		if (ptr2 == NULL) break;
		else
		{
			ptr1->data = ptr1->data + ptr2->data;
			ptr2 = ptr2->next;
			if (ptr1->next == NULL)  break;
			ptr1 = ptr1->next;
		}
	}
	if (ptr2 != NULL)
	{
		while (ptr2 != NULL)
		{
			ptr1->next = ptr2;
			ptr2 = ptr2->next;
			ptr1 = ptr1->next;
		}
	}
	ptr1 = head1;
	return ptr1;
}

int main()
{
	int *input_array1, *input_array2, *output_array,i = 0, j = 0, d = 0;
	for (i = 0; i < 10; i++)
	{
		head1 = NULL, head2 = NULL;
		input_array1 = allocate(testcase[i].input1, testcase[i].length1);
		input_array2 = allocate(testcase[i].input2, testcase[i].length2);
		if (testcase[i].length1>testcase[i].length2)
		output_array = allocate(testcase[i].output, testcase[i].length1);
		else
			output_array = allocate(testcase[i].output, testcase[i].length2);

		for (j = 0; j < testcase[i].length1; j++)
		{

			create_ll(&head1, input_array1[j]);
		}
		for (j = 0; j<testcase[i].length2; j++)
		{

			create_ll(&head2, input_array2[j]);
		}
		head1 = add_2LL(head1, head2);
		if (testcase[i].length1>testcase[i].length2)
    	d = compare(output_array, testcase[i].length1, head1);
		else
			d = compare(output_array, testcase[i].length2, head1);
		if (d == 1) printf("\nPASSED");
		else printf("\nFAILED");
	}
	return 0;
}

