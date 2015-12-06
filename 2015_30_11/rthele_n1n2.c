#include<stdio.h>
struct test
{
	int n1;
	int n2;
	int r;
	int output;
}testCase[10] = { { 3,2, 0, -1 }, { 1,2 , -1, -1 }, { 2, 4, 2, 4 }, { 6,12 , 2,12  }, { 3, 2, 3, 4 },
{ 2, 5, 4,6  }, { 3, 5, 2, 5 }, { 5, 6, 6, 18 }, { 2,3,5,5,6 }, {25,50,2,50} };


	int gcd(int n1, int n2)
	{
		if (n2 <= n1 && n1%n2 == 0)
			return n2;
		if (n1 < n2)
			return gcd(n2, n1);
		else
			return gcd(n2, n1%n2);
	}
	int mergeTables(int n1, int n2, int r)
	{
		int r,count=0,lcm, low, high, mid;
		if (r <= 0) 
			return -1;
		lcm = (n1*n2) / gcd(n1, n2);
		low = 0;
		high = (n1*r) + 1;
		while ((high - low)!=0)
		{
			mid = (high + low) / 2;
			count = (mid / n1) + (mid / n2) - (mid / lcm);
			if (count >= r)
				high = mid;
			else low = mid;
		}
		return high;
	}
	int compare(int a, int b)
	{
		if (a == b)return 1;
		return 0;
	}
	void testMethods()
	{
		int n1, n2, r, d, i, answer;
		for (i = 0; i < 10; i++)
		{
			answer = mergeTables(testCase[i].n1, testCase[i].n2, testCase[i].r);
			d = compare(answer, testCase[i].output);
			if (d==1) printf("\nPASSED");
			else printf("\nFAILED");
		}
	}
	int main()
	{
		testMethods();
		getch();
		return 0;
	}