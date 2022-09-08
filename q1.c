#include <stdio.h>
#include <stdlib.h>

void create();

void insertEnd();

void display();

struct node
{
	int data;
	struct node *next;
};

struct node *head, *new, *temp;

int main()
{
	int choice;
	while (1)
	{
		printf("\nEnter your choice :\n1-> Create a Linked List\n2->Insert a node at an end\n3->Display the linked list\n4->Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			create();
			break;
		
		case 2:
			insertEnd();
			break;
	
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Incorrect option!!!Choose from the Below options\n");
		}
	}
	return 0;
}

void create()
{
	int n;
	head = NULL;
	printf("Enter the size of Linked list :");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		new = (struct node *)malloc(sizeof(struct node));
		printf("Enter %d integer : ", i + 1);
		scanf("%d", &new->data);
		if (head == NULL)
		{
			head = temp = new;
		}
		else
		{
			temp->next = new;
			temp = new;
		}
	}
}

void display()
{
	temp = head;
	printf("Linked list is :\t");
	while (temp != NULL)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
	printf("\n");
}



void insertEnd()
{
	temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	new = (struct node *)malloc(sizeof(struct node));
	printf("Enter a integer to insert at End :");
	scanf("%d", &new->data);
	new->next = NULL;
	temp->next = new;
	printf("%d is inserted at End of Linked list\n", new->data);
}


		


