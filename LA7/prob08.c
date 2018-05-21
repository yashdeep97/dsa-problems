#include<stdio.h>
void main()
{
    int n,i,j;
    scanf("%d",&n);
    int stack[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&stack[i]);
    }
    // bubble sort ---- use merge sor instead
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(stack[j]>stack[j+1])
            {
                int tmp=stack[j];
                stack[j]=stack[j+1];
                stack[j+1]=tmp;
            }
        }
    }
    int cost=0;
    for(i=1;i<n;i++)
    {
        int sum=stack[0]+stack[i];
        stack[0]=sum;
        cost=cost+sum;
    }
    printf("\n%d",cost);
}
