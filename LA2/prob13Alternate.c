#include<stdio.h>
int maximum(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int minimum(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
void main()
{
    int i=0,j=0,k=0,iv,jv,kv;
    int max,min;
    int diff=65535;
    int p,q,r;
    int z;
    scanf("%d%d%d",&p,&q,&r);
    int a[p],b[q],c[r];
    for(z=0;z<p;z++)
        scanf("%d",&a[z]);
    for(z=0;z<q;z++)
        scanf("%d",&b[z]);
    for(z=0;z<r;z++)
        scanf("%d",&c[z]);
    while(i<p&&j<q&&k<r)
    {
        max=maximum(a[i],maximum(b[j],c[k]));
        min=minimum(a[i],minimum(b[j],c[k]));
        if(diff>max-min)
        {
            iv=a[i];
            jv=b[j];
            kv=c[k];
            diff=max-min;
        }
        if(a[i]==min)
            i++;
        else if(b[j]==min)
            j++;
        else
            k++;
    }
    printf("%d %d %d \n",iv,jv,kv);
}