#include<iostream>
using namespace std;
int main()
{
	int number = 0,mask=1,multiple,count_of_set_bits = 0;
	cout << "Enter the number:";
	cin >> number;
	for (int i = 0; i < 32; i++)
	{
		multiple = (number & mask);
		if (multiple)
		{
			count_of_set_bits++;
		}		 
		mask <<= 1;
	}
	if (count_of_set_bits == 1)
	{
		printf("Number is the power of 2");
	}		
	else printf("Number is not the power of 2");
	return 0;
}