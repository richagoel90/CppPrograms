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
void swap(int* num1, int* num2)
{
	*num1 ^= *num2;
	*num2 ^= *num1;
	*num1 ^= *num2;
}

int main()
{
	int number = 0, numberXOR = 0;
	cout << "Enter the number" << endl;
	cin >> number;
	numberXOR = calculateXOR(number);
	cout << "XOR of the number :" << numberXOR << endl;

	auto binarynum = 0b011;
	cout <<"binary number into int" << binarynum << endl;
	
	int num1 = 0, num2 = 0;
	cout << "ENter 2 numbers to swap" << endl;
	cin >> num1 >> num2;
	swap(&num1,&num2);
	cout << "Now Num 1:" << num1 << endl;
	cout << "Num2 :" << num2 << endl;
	return 0;

}
