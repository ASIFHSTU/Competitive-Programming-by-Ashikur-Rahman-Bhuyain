/*
Name : Ashikur Rahman Bhuyain
Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh

Problem id : UVa 11297
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 250005
int ar[MX];
int maxTree[MX*4];
int minTree[MX*4];

void initMinMax(int node,int b,int e)
{
    if(b==e)
    {
        maxTree[node]=ar[b];
        minTree[node]=ar[b];
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    initMinMax(left,b,mid);
    initMinMax(right,mid+1,e);
    maxTree[node]=max(maxTree[left],maxTree[right]);
    minTree[node]=min(minTree[left],minTree[right]);
}

void Update(int node,int b,int e,int ind,int value)
{
    if(ind>e || ind<b)return;
    if(b>=ind and e<=ind)
    {
        maxTree[node]=value;
        minTree[node]=value;
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    Update(left,b,mid,ind,value);
    Update(right,mid+1,e,ind,value);
    maxTree[node]=max(maxTree[left],maxTree[right]);
    minTree[node]=min(minTree[left],minTree[right]);
}

int queryMin(int node,int b,int e,int i,int j)
{
    if(b>j || e<i)return INT_MAX;
    if(b>=i and e<=j)return minTree[node];
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;

    int r1=queryMin(left,b,mid,i,j);
    int r2=queryMin(right,mid+1,e,i,j);
    return min(r1,r2);

}

int queryMax(int node,int b,int e,int i,int j)
{
    if(b>j || e<i)return INT_MIN;
    if(b>=i and e<=j)return maxTree[node];
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;

    int r1=queryMax(left,b,mid,i,j);
    int r2=queryMax(right,mid+1,e,i,j);
    return max(r1,r2);

}

int main()
{
    int n;
    scanf("%d",&n);
    int mult=n;
    n=n*n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
    }

    initMinMax(1,1,n);
    int q;
    scanf("%d",&q);
    char ch;
    int a,b,x1,y1,x2,y2;

    for(int i=0;i<q;i++)
    {
        cin>>ch;
        if(ch=='q')
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            //a=((x1-1)*mult)+y1;
            b=y2-y1;

            int res1=INT_MIN;
            int res2=INT_MAX;
            for(int j=x1;j<=x2;j++)
            {
                a=((j-1)*mult)+y1;

            res1=max(res1,queryMax(1,1,n,a,a+b));
             res2=min(res2,queryMin(1,1,n,a,a+b));
            }

            printf("%d %d\n",res1,res2);
        }
        else {
            scanf("%d%d%d",&x1,&y1,&b);
            a=((x1-1)*mult)+y1;
            Update(1,1,n,a,b);
        }
    }

    return 0;
}

