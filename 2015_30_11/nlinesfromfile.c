#include<stdio.h>
#include<iostream>
#include<string.h>
void main()
{
	ifstrem *f1;
	ofstrem *f2;
	int i, j,count=0, n,curr_position,end_position;
	char ch;
	printf("\,READ the n");
	scanf("%d", &n);
	f1 = fopen("a.txt");
	f2 = fopen("b.txt");
	fseek(f1, 0, SEEK_END);
	end_position = ftell(f1);
	while (count < n)
	{
		position = ftell(f1);
		if (ch == '\n') count++;
		printf("%c", ch);
		fputc(ch, f2);
		fseek(f1, position - 1, end_position);
	}
}