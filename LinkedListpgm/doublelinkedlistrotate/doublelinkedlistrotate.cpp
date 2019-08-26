// doublelinkedlistrotate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "malloc.h"
using namespace std;
typedef struct node
{
	int data;
	struct node* previous;
	struct node* next;
} Node;
int Addition(Node** head)
{
	Node* traverseNode;
	Node* newNode = (Node*)malloc(sizeof(Node));
	cout <<endl << "Enter the new node";
	cin >> newNode->data;
	if (*head == NULL)
	{
		*head = newNode;
		(*head)->previous = NULL;
		(*head)->next = NULL;
		return 0;
	}
	traverseNode = *head;
	while (traverseNode->next != NULL)
	{
		traverseNode = traverseNode->next;
	}
	newNode->previous = traverseNode;
	newNode->next = NULL;
	traverseNode->next = newNode;
	return 0;
}
int traverse_list(Node* head)
{
	if (head == NULL)
	{
		cout << "list is emplty" << endl;
		return 0;
	}
	while (head !=NULL)
	{
		cout << head->data << " -> ";
		head = head->next;
	}
	return 0;
}
int rotate_list(Node** head, int rotate)
{
	Node* temp1 = *head, * temp2;
	for (int i = 1; i < rotate; i++)
	{
		(*head) = (*head)->next;
	}
	temp2 = (*head)->next;
	(*head)->next = NULL;
	(*head) = temp2;
	(*head)->previous = NULL;

	temp2 = (*head);
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp1;
	temp1->previous = temp2;
	return 0;
}
int main()
{
	int items;
	Node* head = NULL, * temp1 = NULL, * temp2 = NULL;
	cout << "Enter elements of linked list:";
	cin >> items;
	for(int i=0;i<items;i++)
	{
		Addition(&head);
	}
	traverse_list(head);
	int rotate = 0;
	cout << endl << "Enter position to rotate:";
	cin >> rotate;
	while(rotate >= items)
	{
		cout << "List can only be rotate " << items-1 << "times.Please enter less than that";
		cin >> rotate;
	}
	if (rotate != 0)
	{
		rotate_list(&head, rotate);
	}
	traverse_list(head);

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
