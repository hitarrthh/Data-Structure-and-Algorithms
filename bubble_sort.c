#include <stdio.h>
void main()
{
    int a[5]={5,4,3,10,1},i,j;
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(a[j] > a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
}