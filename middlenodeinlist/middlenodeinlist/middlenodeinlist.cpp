// middlenodeinlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "malloc.h"
using namespace std;
typedef struct node {
	int data;
	struct node* next;
}Node;
int Addition_Node(Node** head)
{
	Node* addNode = (Node*)malloc(sizeof(Node));
	addNode->next = NULL;
	cout << endl << "Enter new Node:";
	cin >> addNode->data;
	if ((*head) == NULL)
	{
		(*head) = addNode;
	}
	else
	{
		Node* tempNode = (*head);
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
		tempNode->next = addNode;
	}
	return 0;
}
int traverse_list(Node* head)
{
	if (head == NULL)
	{
		cout << "List is empty";
	}
	else
	{
		while (head != NULL)
		{
			cout << head->data << "->";
			head = head->next;
		}
	}
	return 0;
}
int main()
{
	Node* head = NULL;
	int size;
	cout << "Enter size of the list :";
	cin >> size;
	while (size < 0)
	{
		cout << "Enter valid size:";
		cin >> size;
	}
	for (int i = 0; i < size; i++)
	{
		Addition_Node(&head);
	}
	traverse_list(head);
	Node* temp1 = head, * temp2 = head;
	while(temp2->next != NULL && temp2->next->next!=NULL)
	{
		temp1 = temp1->next;
		temp2 = temp2->next->next;
	}
	cout << endl <<"Middle element is" << temp1->data;
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
