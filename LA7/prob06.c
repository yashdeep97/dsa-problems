#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void main()
{
    int n,i,j;
    scanf("%d",&n);
    int arr[n+1][2];
    for(i=0;i<=n;i++)
    {
        arr[i][0]=0;
    }
    scanf("%d",&arr[0][0]);
    arr[0][1]=0;
    for(i=1;i<=n;i++)
    {
        int parent,child;
        char lr;
        scanf("%d %d %c",&parent,&child,&lr);
        arr[i][0]=child;
        for(j=0;j<=n;j++)
        {
            if(parent==arr[j][0])
            {
                if(lr=='L')
                    arr[i][1]=arr[j][1]-1;
                else
                    arr[i][1]=arr[j][1]+1;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(arr[j][1]>arr[j+1][1])
            {
                swap(&arr[j][0],&arr[j+1][0]);
                swap(&arr[j][1],&arr[j+1][1]);
            }
        }
    }
    int curr=arr[0][1];
    printf("\n");
    for(i=0;i<=n;i++)
    {
        if(curr==arr[i][1])
        {
            printf("%d ",arr[i][0]);
        }
        else
        {
            curr=arr[i][1];
            printf("\n%d ",arr[i][0]);
        }
    }
    printf("\n");
    return;
}
