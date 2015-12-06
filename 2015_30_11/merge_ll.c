// merge.c
#include <stdio.h>
#include<stdlib.h>
struct test
{
	int input1[10];
	int length1;
	int input2[10];
	int length2;
	int output[20];
	int length3;
}testcase[10] = { { { 1, 3, 5, 7, 9 }, 5, { 2, 4, 6, 8, 10 }, 5, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10 },
{ { 5, 8, 9 }, 3, { 2, 6, 7 }, 3, {2,5,6,7,8,9}, 6 } ,
{ {-2,-1,}, 2, {-6,2},2 , {-6,-2,-1,2},4 },
{ { 9, -8, -7, -6, -5 }, 5, { 5, 6, 7, 8, 9 }, 5, { -9, -8, -7, -6, -5, 5, 6, 7, 8, 9 }, 10 },
{ {-1,3,6,9},4 , {1,2},2 , {-1,1,2,3,6,9},6 }, 
{ {1},1 , {2},1 , {1,2},2 }, 
{ {5,7,8,9},4 , {2,3,4}, 3, {2,3,4,5,7,8,9},7 }, 
{ {0,0,0,0},4 , {1,1,1,1,1},5 , {0,0,0,0,1,1,1,1,1},9 }, 
{ {0,0,0},3 , {0,0,0},3 , {0,0,0},3 }, 
{ {1,6,9},3 , {-3,-2,9},3 , {-3,-2,1,6,9},5 }, 
};
struct node
{
	int data;
	struct node *next;
}*newnode = NULL, *temp = NULL,*head1=NULL,*head2=NULL;
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

struct node * merge_LL(struct node *head1, struct node *head2)
{
	struct node *ptr1 = head1, *ptr2 = head2,*prev=ptr1,*m=ptr2;
	if (ptr1->data > ptr2->data)
	{
		head1 = m;		
		m->next = ptr1;
		ptr2->next = ptr2->next;
		m = ptr2;
	}
	prev = head1;
	while (ptr1!=NULL)
	{
		if (ptr2 == NULL) break;
		if (ptr1->data>ptr2->data)
		{
			prev->next = m;
			m->next = ptr1;
			ptr2 = ptr2->next;
			m = ptr2;
		}
		else if (ptr1->data == ptr2->data)
		{
			prev = ptr1;
			ptr1 = ptr1 ->next;
			ptr2 = ptr2->next;
			m = ptr2;
		}
		else
		{
			prev = ptr1;
			ptr1 = ptr1->next;
		}
	}
	if (ptr2 != NULL)
	{
		while (ptr2 != NULL)
		{
			prev->next = ptr2;
			ptr2 = ptr2->next;
			prev = prev->next;
		}
	}
	prev = head1;
	return prev;
}

int main()
{
	int *input_array1, *input_array2, *output_array, med = 0, i = 0, j = 0, d = 0;
	for (i = 0; i < 10; i++)
	{
		struct node *ans = NULL;
		head1 = NULL, head2 = NULL;
		input_array1 = allocate(testcase[i].input1, testcase[i].length1);
		input_array2 = allocate(testcase[i].input2, testcase[i].length2);
		output_array = allocate(testcase[i].output, testcase[i].length3);
		
		for (j = 0; j < testcase[i].length1; j++)
		{

			create_ll(&head1, input_array1[j]);
		}
		for (j = 0; j<testcase[i].length2; j++)
		{

			create_ll(&head2, input_array2[j]);
		}
		ans=merge_LL(head1, head2);
	    d = compare(output_array, testcase[i].length3, ans);
		if (d == 1) printf("\nPASSED");
		else printf("\nFAILED");
	}
	return 0;
}

