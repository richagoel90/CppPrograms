// ConsoleApplication7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>
using namespace std;

typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 } ListNode;
int Nodeadd(ListNode** Resulthead, int data)
{
	ListNode* addNode = (ListNode*)malloc(sizeof(ListNode));
	addNode->next = NULL;
	addNode->val = data;
	if (*Resulthead == NULL)
	{
		*Resulthead = addNode;
	}
	else
	{
		ListNode* tempNode;
		tempNode = *Resulthead;
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
		tempNode->next = addNode;
	}
	return 0;

}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* Resulthead = NULL;
	int data, carry = 0;
	while (l1 != NULL && l2 != NULL)
	{
		data = (carry + l1->val + l2->val) % 10;
		carry = (carry + l1->val + l2->val) / 10;
		Nodeadd(&Resulthead, data);
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1 != NULL)
	{
		data = (carry + l1->val) % 10;
		carry = (carry + l1->val) / 10;
		Nodeadd(&Resulthead, data);
		l1 = l1->next;
	}
	while (l2 != NULL)
	{
		data = (carry + l2->val) % 10;
		carry = (carry + l2->val) / 10;
		Nodeadd(&Resulthead, data);
		l2 = l2->next;
	}
	if (carry != 0)
	{
		data = carry;
		Nodeadd(&Resulthead, data);
	}
	return Resulthead;
}

int Addition(ListNode** head)
{
	ListNode* tempNode = NULL;
	ListNode* addNode = (ListNode*)malloc(sizeof(ListNode));
	addNode->next = NULL;
	cout << "add node:";
	cin >> addNode->val;
	if ((*head) == NULL)
	{
		(*head) = addNode;
	}
	else
	{
		tempNode = (*head);
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
		tempNode->next = addNode;
	}
	return 0;
}
int main()
{
	int l1_length, l2_length;
	ListNode* l1 = NULL,*l2=NULL,*l3=NULL;
	cout << "L1 list length: ";
	cin >> l1_length;
	while (l1_length)
	{
		Addition(&l1);
		l1_length--;
	}
	cout << "L2 list length: ";
	cin >> l2_length;
	while (l2_length)
	{
		Addition(&l2);
		l2_length--;
	}
	l3=addTwoNumbers(l1, l2);
	while (l3 != NULL)
	{
		cout << l3->val << "->";
		l3 = l3->next;
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
