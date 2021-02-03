/*
Name : Ashikur Rahman Bhuyain
Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh

Problem id : UVa11402
*/


#include <bits/stdc++.h>
using namespace std;
#define MX 1024005
#define CLEAR 0
#define ON 1
#define OFF 2
#define FLIP 3
int ar[MX];
int operation[MX*4];
int totalOn[MX*4];

void init(int node,int b,int e)
{
    if(b==e)
    {
        operation[node]=ar[b];
        totalOn[node]=ar[b];
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    init(left,b,mid);
    init(right,mid+1,e);
    totalOn[node]=totalOn[left]+totalOn[right];
}

void flipOperation(int node,int b,int e)
{
    if(operation[node]==CLEAR)
    {
        operation[node]=FLIP;
        totalOn[node]=(e-b+1)-totalOn[node];
    }
    else if(operation[node]==ON)
    {
        operation[node]=OFF;
        totalOn[node]=0;
    }
    else if(operation[node]==OFF)
    {
        operation[node]=ON;
        totalOn[node]=e-b+1;
    }
    else if(operation[node]==FLIP){
        operation[node]=CLEAR;
        totalOn[node]=(e-b+1)-totalOn[node];
    }
}

void propagate(int node,int b,int e)
{
    if(operation[node]==CLEAR)return;

    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;

    if(operation[node]==ON)
    {
       operation[left]=operation[right]=ON;
       totalOn[left]=(mid-b)+1;
       totalOn[right]=e-mid;

    }
    else if(operation[node]==OFF)
    {
        operation[left]=operation[right]=OFF;
       totalOn[left]=0;
       totalOn[right]=0;
    }
    else if(operation[node]==FLIP)
    {
        flipOperation(left,b,mid);
        flipOperation(right,mid+1,e);
    }
    operation[node]=CLEAR;
}

void updateOn(int node,int b,int e,int i,int j)
{
   if(b>j || e<i)return;
   if(b>=i and e<=j)
   {
       operation[node]=ON;
       totalOn[node]=e-b+1;
       return;
   }
   propagate(node,b,e);
   int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    updateOn(left,b,mid,i,j);
    updateOn(right,mid+1,e,i,j);
    totalOn[node]=totalOn[left]+totalOn[right];
}

void updateOff(int node,int b,int e,int i,int j)
{
   if(b>j || e<i)return;
   if(b>=i and e<=j)
   {
       operation[node]=OFF;
       totalOn[node]=0;
       return;
   }
   propagate(node,b,e);
   int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    updateOff(left,b,mid,i,j);
    updateOff(right,mid+1,e,i,j);
    totalOn[node]=totalOn[left]+totalOn[right];
}

void updateFlip(int node,int b,int e,int i,int j)
{
   if(b>j || e<i)return;
   if(b>=i and e<=j)
   {
       flipOperation(node,b,e);
       return;
   }
   propagate(node,b,e);
   int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    updateFlip(left,b,mid,i,j);
    updateFlip(right,mid+1,e,i,j);
    totalOn[node]=totalOn[left]+totalOn[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i)return 0;
   if(b>=i and e<=j)
   {
       return totalOn[node];
   }
   propagate(node,b,e);
   int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    int r1=query(left,b,mid,i,j);
    int r2=query(right,mid+1,e,i,j);
    return r1+r2;
}

void solve()
{
    memset(operation,0,sizeof(operation));
    memset(totalOn,0,sizeof(totalOn));
    int total;
    scanf("%d",&total);
    int occ,len;
    string st;
    int n=1;
    for(int i=0;i<total;i++)
    {
        cin>>occ;
        cin>>st;
        len=st.size();
        for(int j=0;j<occ;j++)
        {
            for(int k=0;k<len;k++)
            {
                ar[n]=st[k]-'0';
                n++;
            }
        }
    }
    n=n-1;
    init(1,1,n);

    int q;
    scanf("%d",&q);
    int qt=1;
    char op;
    int a,b;
    for(int i=0;i<q;i++)
    {
        cin>>op;
        scanf("%d%d",&a,&b);
        if(op=='F')
        {
            updateOn(1,1,n,a+1,b+1);
        }
        else if(op=='E')
        {
            updateOff(1,1,n,a+1,b+1);
        }
        else if(op=='I')
        {
            updateFlip(1,1,n,a+1,b+1);
        }
        else {
            printf("Q%d: %d\n",qt,query(1,1,n,a+1,b+1));
            qt++;
        }
    }

}

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int i=1;i<=tc;i++)
    {
        printf("Case %d:\n",i);
        solve();
    }
}
