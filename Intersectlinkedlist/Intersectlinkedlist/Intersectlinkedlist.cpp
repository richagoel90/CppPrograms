// Intersectlinkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"malloc.h"
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}Node;
int Addition_Node(Node** head)
{
	Node* addNode = (Node*)malloc(sizeof(Node));
	addNode->next = NULL;
	cout << "Enter the node:";
	cin >> addNode->data;
	if ((*head) == NULL)
	{
		(*head) = addNode;
	}
	else
	{
		Node* tempNode=*head;
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
		tempNode->next = addNode;
	}
	return 0;
}
int Traverse_List(Node* head)
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
	int size1, size2;
	Node* head1 = NULL,*head2=NULL;
	cout << "Enter size of 1st Linked List:";
	cin >> size1 ;
	while (size1 < 1)
	{
		cout << "Enter valid size";
		cin >> size1;
	}
	for (int i = 0; i < size1; i++)
	{
		Addition_Node(&head1);
	}
	Traverse_List(head1);
	cout << endl << "Enter size of 2nd Linked List:";
	cin >> size2;
	while (size2 < 1)
	{
		cout << "Enter valid size:";
		cin >> size2;
	}

	for (int i = 0; i < size2; i++)
	{
		Addition_Node(&head2);
	}
	Traverse_List(head2);
	if (size1 > size2)
	{
		for (int i = 0; i < (size1 - size2); i++)
		{
			head1 = head1->next;
		}
	}
	else if (size2 > size1)
	{
		for (int i = 0; i < (size2 - size1); i++)
		{
			head2 = head2->next;
		}
	}
	while (head1 != NULL && head1->data != head2->data )
	{
		head1=head1->next;
		head2=head2->next;
	}
	if (head1 == NULL)
	{
		cout << endl << "There is no intersection in these Lists";
		return 0;
	}
	cout << endl << head1->data << "is the intersecting point of List1 and List2";
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
