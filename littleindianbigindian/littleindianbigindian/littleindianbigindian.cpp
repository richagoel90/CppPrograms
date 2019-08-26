#include<stdio.h>
int main()
{
	int number = 0, mask = 1;
	printf("Enter the number to convert into bits:");
	scanf_s("%d", &number);
	for (int i = 0; i < 32; i++)
	{
		if ((number & mask) == 0)
		{
			printf("0");
		}
		else
			printf("1");
		mask <<= 1;
	}
	return 0;
}