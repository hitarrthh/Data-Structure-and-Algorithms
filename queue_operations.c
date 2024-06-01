#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *rear = NULL;
struct node *front = NULL;
void insert();
void delete();
void display();
void peek();
void main()
{
	int choice;
	do
	{
		printf("\t MENU\n");
		printf("1. TO INSERT ELEMENT\n");
		printf("2. TO DELETE ELEMENT\n");
		printf("3. TO DISPLAY\n");
		printf("4. TO PEEK\n");
		printf("5. TO EXIT\n");
		printf("ENTER CHOICE\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			 insert();
			break;
			case 2:
			 delete();
			break;
			case 3:
			 display();
			break;
			case 4:
			 peek();
			break;
			default:
			printf("INVALID CHOICE\n");
			break;
		}
	}while(choice != 5);
}
void insert()
{
	int val;
	struct node *nn;
	do
	{
		printf("ENTER -1 TO EXIT\n");
		printf("ENTER VALUE TO INSERT\n");
		scanf("%d",&val);
		nn = (struct node*)malloc(sizeof(struct node));
		nn->data = val;
		nn->next = NULL;
		if((front == NULL) && (rear == NULL))
		{
			front = rear = nn;
		}
		else
		{
			rear->next = nn;
			rear = nn;
		}
	}while(val != -1);
	
}
void delete()
{
	struct node *temp;
	if(front == rear)
	{
		printf("UNDERFLOW\n");
	}
	else
	{
		temp = front;
		front = front->next;
		if(front == NULL)
		{
			rear == NULL;
		}
		printf("ELEMENT TO BE DELETED IS %d\n",temp->data);
		free(temp);
	}
}
void display()
{
	struct node *ptr;
	if(front == rear)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		ptr = front;
		printf("QUEUE:\n");
		while(ptr != rear)
		{
			printf("%d \t",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
void peek()
{
	if(front == rear)
	{
		printf("QUEUE EMPTY\n");
	}
	else
	{
		printf("PEEK ELEMENT IS: %d\n",front->data);
	}
}
