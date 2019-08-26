#include<iostream>
using namespace std;
int calculateXOR(int number)
{
	if (number % 4 == 0)
		return number;
	if (number % 4 == 1)
		return 1;
	if (number % 4 == 2)
		return number + 1;
	else
		return 0;
}

int main()
{
	int number = 0,numberXOR=0;
	cout << "Enter the number" << endl;
	cin >> number;
	numberXOR = calculateXOR(number);
	cout << "XOR of the number :" << numberXOR;
	return 0;
}