// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
} Node;

int Traverse(Node* head)
{
	if (head == NULL)
	{
		printf("List is empty\n");
		return 0;
	}
	while (head != NULL)
	{
		printf("%d,", head->data);
		head = head->next;
	}
	printf("\n");
	return 0;
}

int Addition(Node** head)
{
	Node* tempNode;
	Node* newNode = (Node*)malloc(sizeof(Node*));
	printf("Enter the new node to add:");
	scanf_s("%d", &newNode->data);
	if (*head == NULL)
	{
		*head = newNode;
		newNode->next = NULL;
	}
	else
	{
		tempNode = *head;
		while (tempNode->next != NULL)
			tempNode = tempNode->next;
		tempNode->next = newNode;
		newNode->next = NULL;
	}
	printf("Element is added\n");
	return 0;
}

int Search(Node* head)
{
	int number = 0, count = 0;
	printf("Enter element to be searched:");
	scanf_s("%d", &number);
	if (head == NULL)
	{
		printf("List is empty\n");
		return 0;
	}
	else
	{
		while (head != NULL)
		{
			count++;
			if (head->data == number)
			{
				printf("Element is present in teh list at %d position", count);
				return 0;
			}
			head = head->next;
		}
		printf("Element is not present in the list\n");
	}
	return 0;
}
int Deletion(Node** head)
{
	int number_del = 0;
	printf("Enter numbe rto be deleted:");
	scanf_s("%d", &number_del);
	if ((*head) == NULL)
	{
		printf("List is empty\n");
		return 0;
	}
	else
	{
		Node* tempCurrent = *head;
		Node* tempPrevious = NULL;
		while (tempCurrent != NULL && tempCurrent->data != number_del)
		{
			tempPrevious = tempCurrent;
			tempCurrent = tempCurrent->next;
		}
		if (tempCurrent == NULL)
		{
			printf("Element is not present in the list\n");
			return 0;
		}
		else
		{
			if (tempPrevious == NULL)
			{
				tempCurrent = (*head)->next;
				//				free(*head);
				*head = tempCurrent;
			}
			else
			{
				tempPrevious->next = tempCurrent->next;
				//				free(tempCurrent);
			}
		}
	}
}
int Reverse(Node** head)
{
	if (*head == NULL || (*head)->next == NULL)
		return 0;

	Node* previousNode = NULL, * currentNode, * nextNode;
	currentNode = *head;
	nextNode = currentNode->next;
	currentNode->next = previousNode;
	while (nextNode != NULL)
	{
		previousNode = currentNode;
		currentNode = nextNode;
		nextNode = nextNode->next;
		currentNode->next = previousNode;
	}
	*head = currentNode;
	return 0;
}
int main()
{
	int option = 0;
	Node* head = NULL;
	while (option != 6)
	{
		printf("Enter your choice:\n");
		printf("Node add press 1: \n");
		printf("Node Delete press 2: \n");
		printf("Node Search press 3: \n");
		printf("List print press 4: \n");
		printf("Reverse press 5: \n");
		printf("Quit press 6: \n");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1: Addition(&head);
			Traverse(head);
			break;
		case 2: Deletion(&head);
			Traverse(head);
			break;
		case 3: Search(head);
			break;
		case 4: Traverse(head);
			break;
		case 5: Reverse(&head);
			Traverse(head);
			break;
		case 6: exit(0);
		default: printf("please select option 1-6");
			break;
		}
	}
	return 0;
}