#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create(struct node*);
struct node *display(struct node*);
struct node *insert_beg(struct node*);
struct node *insert_end(struct node*);
struct node *delete_end(struct node*);
struct node *delete_beg(struct node*);
struct node *delete_after(struct node *);
struct node *delete_node(struct node *);
struct node *delete_list(struct node *);
struct node *insert_before(struct node*);
struct node *insert_after(struct node*);
struct node *sort(struct node*);
void main()
{
    int ch;
    do
    {
         printf("ENTER CHOICE\n");
    printf("1.CREATE LINKED LIST\n");
    printf("2.DISPLAY LINKED LIST\n");
    printf("3.INSERT BEGINING\n");
    printf("4.INSERT END\n");
    printf("5.INSERT BEFORE\n");
    printf("6.INSERT AFTER\n");
    printf("7.DELETE BEGINING\n");
    printf("8.DELETE END\n");
    printf("9.DELETE NODE\n");
    printf("10.DELETE AFTER\n");
    printf("11.DELETE LIST\n");
    printf("12.SORT LIST\n");
    printf("-1.TO EXIT \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            start = create(start);
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = insert_before(start);
            break;
        case 6:
            start = insert_after(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = delete_node(start);
            break;
        case 10:
            start = delete_after(start);
            break;
        case 11:
            start = delete_list(start);
            break;
         case 12:
            start = sort(start);
            break;
    }
    }while(ch != -1);
}
struct node *create(struct node *start)
{
    struct node *nn,*ptr;
     int val;
      printf("enter -1 to exit\n");
    printf("enter value\n");
    scanf("%d",&val);
    while(val != -1){
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = NULL;
    if(start == NULL)
    {
        start = nn;
    }
    else
    {
        ptr = start;
        while(ptr->next != NULL)
        {
            ptr=ptr->next;
        }
        ptr->next = nn;
    }
    printf("enter value\n");
    scanf("%d",&val);
    }
    return start;
}
struct node *display(struct node*start)
{
    struct node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return start;
}
struct node *insert_beg(struct node*start)
{
    struct node *nn;
    int val;
    printf("ENTER VALUE TO INSERT IN BEG\n");
    scanf("%d",&val);
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    nn->next = start;
    start = nn;
    return start;
}
struct node *insert_end(struct node*start)
{
    struct node *nn,*ptr;
    nn = (struct node *)malloc(sizeof(struct node));
    printf("ENTER VAL TO ENTER AT END\n");
    int val;
    scanf("%d",&val);
    ptr = start;
    nn->data = val;
    nn->next =NULL;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = nn;
    return start;
}
struct node *delete_beg(struct node*start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node*start)
{
    struct node *ptr,*pp;
    ptr = start;
    pp = start;
    while(ptr->next != NULL)
    {
        pp = ptr;
        ptr = ptr->next;
    }
    pp->next = NULL;
    free(ptr);
    return start;
}
struct node *delete_node(struct node *start)
{
    int val;
    struct node *ptr,*pp;
    printf("ENTER NODE TO DELETE\n");
    scanf("%d",&val);
    ptr=pp=start;
    while(ptr->data != val)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=ptr->next;
    free(ptr);
    return start;
}
struct node *delete_after(struct node *start)
{
    int val;
    struct node *ptr,*pp;
    printf("ENTER NODE TO DELETE\n");
    scanf("%d",&val);
    while(pp->data != val)
    {
        pp=ptr;
        ptr=ptr->next;
    }
    pp->next=ptr->next;
    free(ptr);
    return start;
}
struct node *delete_list(struct node *start)
{
    struct node *ptr;
    if(start != NULL)
    {
        ptr = start;
        while(ptr != NULL)
        {
            printf("ELEMENT TO BE DELETED IS%d\n",ptr->data);
            start = delete_beg(ptr);
            ptr = start;
        }
    }
    return start;
}
struct node *insert_before(struct node*start)
{
    struct node *nn,*ptr;
    int num,val;
    printf("ENTER DATA\n");
    scanf("%d",&num);
    printf("ENTER VALUE TO INSERT BEFORE\n");
    scanf("%d",&val);
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = num;
    if(start == val)
    {
        nn->next = start;
        start = nn;
    }
    ptr=start;
    while(ptr->next->data != val && ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if(ptr->next == NULL)
    {
        ptr->next = nn;
        nn->next=NULL;
    }
    else{
    nn->next = ptr->next;
    ptr->next = nn;}
    return start;
}
struct node *insert_after(struct node*start)
{
    int num,val;
    struct node *nn,*ptr;
    printf("ENTER VALUE\n");
    scanf("%d",&num);
    printf("ENTER VALUE TO INSERT AFTER\n");
    scanf("%d",&val);
    nn = (struct node *)malloc(sizeof(struct node));
    nn->data = num;
    ptr = start;
    if(start == NULL)
    {
        nn->next = NULL;
        start = nn;
    }
    while(ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        ptr->next = nn;
        nn->next = NULL;
    }
    else
    {
        nn->next = ptr->next;
        ptr->next = nn;
    }
    return start;
}
struct node *sort(struct node*start)
{
    struct node *ptr1,*ptr2;
    int temp;
    ptr1=start;
    if(ptr1->next != NULL)
    {
        ptr2=ptr1->next;
        while(ptr2 != NULL)
        {
            if(ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    printf("data sorted\n");
    return start;
}