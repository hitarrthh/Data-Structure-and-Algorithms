#include <stdio.h>
#define MAX 10
int st[MAX], top = -1;
void push (int st[],int val);
void display(int st[]);
int pop(int st[]);
int peek(int st[]);
void main()
{
    int op,val;
    do
    {
        printf("\tMENU\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");
        printf("5.EXIT\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("ENTER VALUE TO INSERT\n");
            scanf("%d",&val);
            push(st,val);
            break;
        case 2:
            val = pop(st);
            if(val != -1)
                printf("POP ELEMENT IS: %d\n",val);
            break;
        case 3:
            val = peek(st);
            if(val != -1)
                printf("PEEK ELEMENT IS: %d\n",val);
            break;
        case 4:
            display(st);
            break;
        default:
            printf("INVLID CHOICE\n");
            break;
        }
    }while(op != 5);
}
void push(int st[], int val)
{
    if(top == MAX-1)
    {
        printf("STACK OVERFLOW\n");
        
    }
    else
    {
        top++;
        st[top] = val;
    }
}
int peek(int st[])
{
    if(top == -1)
    {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
    else
    {
        return st[top];
    }
}
int pop(int st[])
{
    if(top == -1)
    {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
    else
    {
        return st[top--];
    }
}

void display(int st[])
{
    if(top == -1)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        printf("STACK: \n");
        for(int i = top; i >= 0 ;i--)
        {
             printf("\t%d",st[i]);
         }
        printf("\n");
    }
}
