#include<stdio.h>
void ss(int n,int a[]);
void main()
{
    int n,a[10],k;
    printf("Enter length\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(k=0;k<n;k++)
    {
        scanf("%d",&a[k]);
    }
    
    printf("Before sorting\n");
    for(k=0;k<n;k++)
    {
        printf("%d ",a[k]);
    }
    printf("\n"); 
    ss(n,a);
}
void ss(int n,int a[])
{
    int i,min,t,j;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
    printf("After sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}