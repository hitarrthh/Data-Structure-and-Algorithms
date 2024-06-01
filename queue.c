#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int rear = -1;
int front = -1;
int QUEUE[MAX];
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
	if(rear == MAX-1)
	{
		printf("QUEUE OVERFLOW\n");
	}
	else
	{
		if(front == -1)
		
		front = 0;
		printf("ENTER VALUE TO INSERT\n");
		scanf("%d",&val);
		rear = rear + 1;
		QUEUE[rear] = val;
	}
}
void delete()
{
	if((front == -1) && rear==-1)
	{
		printf("QUEUE UNDERFLOW\n");
	}
	else if (front==rear)
	{
		front=rear=-1;
	}
	
	else
	{
		printf("ELEMENT TO DELETE IS: %d\n",QUEUE[front]);
		front = front+1;
	}
}
void display()
{
	if((front == -1) || (rear == -1))
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		printf("QUEUE:\n");
		for(int i=front;i<=rear;i++)
		{
			printf("\t %d \t\n",QUEUE[i]);
		}
	}
}
void peek()
{
	if((front == -1) || (front>rear))
	{
		printf("QUEUE EMPTY\n");
	}
	else
	{
		printf("PEEK ELEMENT: %d\n",QUEUE[front]);
	}
}
