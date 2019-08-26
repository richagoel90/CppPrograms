// substring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string mainString, subString;
	int mainlength, sublength;
	cout << "Enter main String:";
	cin >> mainString;
	cout << endl << "Enter sub String:";
	cin >> subString;
	mainlength = mainString.size();
	sublength = subString.size();
	if (sublength > mainlength)
	{
		cout << "Substring length is more than main String.Hence,Input is not correct";
		return 0;
	}
	int i = 0, j = 0,match=0;
	while ((sublength - j <= mainlength - i) && (j<sublength))
	{
		if (mainString[i+j] == subString[j])
		{
			match = i+1;
			 j++;
		}
		else
		{
			i++; j = 0;
			match = 0;
		}
	}
	if (match == 0)
	{
		cout << subString << " is not present in " << mainString;
	}
	else
	{
		cout << subString << " is present in the mainString " << mainString << " at " << match << " position";
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
