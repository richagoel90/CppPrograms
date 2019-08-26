// linkedlistcountpair.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"malloc.h"
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
} Node ;
int Addition_node(Node** head)
{
	Node* tempNode;
	Node* newNode = (Node*)malloc(sizeof(Node));
	cout << endl << "Enter the new node:";
	cin >> newNode->data;
	if (*head == NULL)
	{
		*head = newNode;
		(*head)->next = NULL;
		return 0;
	}	
	tempNode = *head;
	while (tempNode->next != NULL)
	{
		tempNode = tempNode->next;
	}
	tempNode->next = newNode;
	newNode->next = NULL;

	return 0;
}
int main()
{
	int item1 = 0, item2 = 0;
	Node* head1 = NULL;
	Node* head2 = NULL;
	cout << "Enter number of elements in the list till 1000:";
	cin >> item1;
	if (1 > item1 || item1 > 1000)
	{
		cout << endl << "Numebr of elements is beyond limit. Please enter Number of elements within limit!!";
		cin >> item1;
	}
	for (int i = 0; i < item1; i++)
	{
		Addition_node(&head1);
	}

	cout << "Enter number of elements in the list 2 till 1000: ";
	cin >> item2;
	if (1 > item2 || item2 > 1000)
	{
		cout << endl << "Numebr of elements is beyond limit. Please enter Number of elements within limit!!";
		cin >> item2;
	}
	for (int i = 0; i < item2; i++)
	{
		Addition_node(&head2);
	}

	int sum = 0,count=0;
	cout << endl << "Enter the sum required of 2 nodes:";
	cin >> sum;
	if (1 > sum || sum > 10000)
	{
		cout << endl << "Sum of elements is beyond limit. Please enter Sum of elements within limit!!";
		cin >> sum;
	}
	int array[20000] = { 0 };
	while (head1 != NULL)
	{
		array[10000+ sum - (head1->data)] = 1;
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		if (array[10000+head2->data] == 1)
			count++;
		head2 = head2->next;

	}
	cout << endl << "Count is" << count;

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
