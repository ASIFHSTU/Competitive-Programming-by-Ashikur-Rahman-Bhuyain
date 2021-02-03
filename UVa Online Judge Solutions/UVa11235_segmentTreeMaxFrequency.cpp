/*
Name : Ashikur Rahman Bhuyain
Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh

Problem id : UVa 11235
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 100005
int ar[MX];
struct data
{
    int leftValue,rightValue;
    int leftFrequency,rightFrequency,maxFrequency;
}tree[MX*4];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].maxFrequency=tree[node].leftFrequency=tree[node].rightFrequency=1;
        tree[node].leftValue=tree[node].rightValue=ar[b];
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].maxFrequency=max(tree[left].maxFrequency,tree[right].maxFrequency);
    tree[node].leftValue=tree[left].leftValue;
    tree[node].leftFrequency=tree[left].leftFrequency;
    tree[node].rightValue=tree[right].rightValue;
    tree[node].rightFrequency=tree[right].rightFrequency;


    if(tree[left].rightValue==tree[right].leftValue)
    {
        tree[node].maxFrequency=max(tree[node].maxFrequency,tree[left].rightFrequency+tree[right].leftFrequency);
        if(tree[left].leftValue==tree[left].rightValue)
        {
            tree[node].leftFrequency+=tree[right].leftFrequency;
        }
        if(tree[right].leftValue==tree[right].rightValue)
        {
            tree[node].rightFrequency+=tree[left].rightFrequency;
        }
    }

}

int query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i)return -1;
    if(b>=i and e<=j)return tree[node].maxFrequency;

    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;

    int r1=query(left,b,mid,i,j);
    int r2=query(right,mid+1,e,i,j);

    int res=max(r1,r2);
    if(tree[left].rightValue==tree[right].leftValue)
    {
        int lc=min(mid-i+1,tree[left].rightFrequency);
        int rc=min(j-mid,tree[right].leftFrequency);
        res=max(res,lc+rc);
    }
    return res;
}


void solve(int n)
{
    int q;
    scanf("%d",&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
    }
    init(1,1,n);
    int l,r;
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",query(1,1,n,l,r));
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)return 0;
        solve(n);
    }
}

