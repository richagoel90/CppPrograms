// program2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = plusOne(A);
	for (int i = 0; i < B.size(); i++)
		cout << B[i];
	return 0;
}
vector<int> plusOne(&A)
{
	vector<int> B;
	int addVal,lenA = A.size();
	for (int i = LenA - 1; i >= 0; i--)
	{
		if (A[i] == 9)
		{
			addVal = 1;
			A[i] = 0;
		}
		else
		{
			A[i]++;
			addVal = 0;
		}
	}
	for (int i = 0; i < lenA; i++)
	{
		if (addval == 1)
		{
			B.push_back(1);
			B[i + 1] = A[i];
		}
		else B[i] = A[i];
	}
	return B;
}
