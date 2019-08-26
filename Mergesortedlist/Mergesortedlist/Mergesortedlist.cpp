// Mergesortedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "malloc.h"
using namespace std;
typedef struct node {
	int data;
	struct node* next;
} Node;
int Addition_Node(Node **head)
{
	Node* addNode = (Node*)malloc(sizeof(Node));
	cout << "Enter new node:";
	cin >> addNode->data;
	addNode->next = NULL;
	if ((*head) == NULL)
	{
		(*head) = addNode;
	}
	else
	{
		Node* temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = addNode;
	}
	return 0;
}
int Traverse_List(Node* head)
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		while (head != NULL)
		{
			cout << head->data << "->";
			head = head->next;
		}
		cout << endl;
	}
	return 0;
}
int Addition_List3(Node* head1, Node* head2, Node** head3)
{
	Node* tempNode = NULL;
	if (head1 == NULL)
	{
		*head3 = head2;
		return 0;
	}
	else if (head2==NULL)
	{
		*head3 = head1;
		return 0;
	}
	while (head1 != NULL && head2 != NULL)
	{
		Node* addNode = (Node*)malloc(sizeof(Node));
		if (head1->data <= head2->data)
		{
			addNode->data = head1->data;
			addNode->next = NULL;
			if (*head3 == NULL) 
			{
				(*head3) = addNode;
				tempNode = *head3;
			}
			else
			{
				tempNode->next = addNode;
				tempNode = tempNode->next;
			}
			head1 = head1->next;
		}
		else
		{
			addNode->data = head2->data;
			addNode->next = NULL;
			if (*head3 == NULL)
			{
				(*head3) = addNode;
				tempNode = *head3;
			}
			else
			{
				tempNode->next = addNode;
				tempNode = tempNode->next;
			}
			head2 = head2->next;
		}

	}
	if (head1 != NULL)
	{
		tempNode->next = head1;
	}
	if (head2 != NULL)
	{
		tempNode->next = head2;
	}

	return 0;
}
int main()
{
	int size1,size2;
	Node* head1 = NULL,*head2=NULL,*head3=NULL;
	cout << "Enter the size of Sorted List1:";
	cin >> size1;
	for (int i = 0; i < size1; i++)
	{
		Addition_Node(&head1);
	}
	Traverse_List(head1);

	cout << "Enter the size of Sorted List2:";
	cin >> size2;
	for (int i = 0; i < size2; i++)
	{
		Addition_Node(&head2);
	}
	Traverse_List(head2);
	Addition_List3(head1, head2,&head3);
	Traverse_List(head3);
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
