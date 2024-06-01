#include<stdio.h>
void is(int n,int a[]);
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
    printf("Before sorting \n");
    for(k=0;k<n;k++)
    {
        printf("%d ",a[k]);
    }
    printf("\n"); 
        is(n,a);
}
void is(int n,int a[])
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];
        j=i-1;
        while (j>=0 && a[j]>t)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=t;
    }
    printf("After sorting \n");
     for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    
}