#include <stdio.h>
#include <stdlib.h> 

struct Node
{
	int data;
	struct Node *next;
};
//insert Stack element
void push(int value, struct Node **top)
{
	//Create dynamic node
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	if (node == NULL)
	{
		printf("Memory overflow\n");
	}
	else
	{
		node->data = value;
		node->next = *top;*top = node;
	}
}
//pop Stack element
int pop(struct Node **top)
{
	int value = 0;
	if ( *top == NULL)
	{
		printf("Empty Stack\n");
	}
	else
	{
		struct Node *temp = *top;
		value = temp->data;*top = temp->next;
		free(temp);
		temp = NULL;
	}
	return value;
}
//Get value of top element
int peek(struct Node *top)
{
	if (top != NULL)
	{
		return top->data;
	}
	else
	{
		return -1;
	}
}
//Sort array element by using stack
void sort_array(int arr[], int size)
{
	if (size <= 0)
	{
		return;
	}
	struct Node *top = NULL;
	int temp = 0, j = 0;
	for (int i = 0; i < size; ++i)
	{
		if (top == NULL || peek(top) <= arr[i])
		{
			//Add array element into stack when stack is empty, 
			//or array element is greater than equal to top of stack
			push(arr[i], & top);
		}
		else
		{
			j = i;
			temp = arr[j];
			//When array element is less than stack top element
			//Then insert new element in its proper position
			while (top != NULL && peek(top) > temp)
			{
				//use array space and assign the stack element 
				//until stack top is not null or its value 
				//is less than current array element
				arr[j] = pop( & top);
				j--;
			}
			//assign current element
			arr[j] = temp;
			//After that  array elements between given index is add to stack
			for (j; j <= i; j++)
			{
				push(arr[j], & top);
			}
		}
	}
	//Assign the sorted value in actual array
	for (int i = size - 1; i >= 0; --i)
	{
		arr[i] = pop( & top);
	}
}
//Display array elements
void display(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
int main()
{
	//Define the element of unsorted array
	int arr[] = {8,5,7,1,9,12,10};
	//Get the size of array
	int size = sizeof(arr) / sizeof(arr[0]);
	display(arr, size);
	sort_array(arr, size);
	display(arr, size);
	return 0;
}
