#include<stdio.h>
void main()
{
    int n;
    scanf("%d",&n);
    int heights[n];
    int i,j;
    int l,b=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&heights[i]);
    }
    int area[n];
    for(i=0;i<n;i++)
        area[i]=heights[i];
    for(i=0;i<n;i++)
    {
        l=heights[i];
        b=1;
        for(j=i+1;j<n;j++)
        {
            if(l>heights[j])
            {
                l=heights[j];
            }
            b++;
            int tmp = l*b;
            if(tmp>area[i])
                area[i]=tmp;
            
        }
    }
    int ans=0;
    for(i=0;i<n;i++)
    {
        if(area[i]>ans)
        ans=area[i];
    }
    printf("%d\n",ans);
}