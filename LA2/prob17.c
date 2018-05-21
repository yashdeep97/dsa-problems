#include <stdio.h>
void main()
{
    int sum=0,ans=0;
    int i,j,k,l;
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                for(l=0;l<n;l++)
                {
                    if(k!=i&&l!=j)
                        sum=sum+arr[k][l];
                }
            }
            if(sum>ans)
                ans=sum;
            sum=0;

        }
    }
    printf("%d \n",ans);
}