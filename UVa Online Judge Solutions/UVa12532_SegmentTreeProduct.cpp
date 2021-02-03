/*
Name : Ashikur Rahman Bhuyain
Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh

Problem id : UVa 12532
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 100005
int tree[MX*4];
int ar[MX];

void buildTree(int node,int b,int e)
{
    if(b==e)
    {
        if(ar[b]>0)tree[node]=1;
        else if(ar[b]<0)tree[node]=-1;
        else tree[node]=0;
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    buildTree(left,b,mid);
    buildTree(right,mid+1,e);
    tree[node]=tree[left]*tree[right];
}

void Update(int node,int b,int e,int point,int value)
{
    if(point>e || b>point)return;
    if(point<=b and point>=e)
    {
         if(value>0)tree[node]=1;
         else if(value<0)tree[node]=-1;
         else tree[node]=0;
         return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    Update(left,b,mid,point,value);
    Update(right,mid+1,e,point,value);
    tree[node]=tree[left]*tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(b>=i and e<=j)return tree[node];
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    bool upd1,upd2;
    upd1=upd2=false;
    int r1,r2;
    if(mid>=i)
    {
        r1=query(left,b,mid,i,j);
        upd1=true;
    }
    if(mid+1<=j)
    {
        r2=query(right,mid+1,e,i,j);
        upd2=true;
    }
    if(upd1==false)return r2;
    if(upd2==false)return r1;

    return r1*r2;
}

void solve(int n,int q)
{
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
    }
    buildTree(1,1,n);
    char op;
    int a,b,res;
    for(int i=0;i<q;i++)
    {
         scanf("%*c");
         scanf("%c",&op);
         //cin>>op;
         scanf("%d%d",&a,&b);

         if(op=='C')
         {
             Update(1,1,n,a,b);
         }
         else {
            res=query(1,1,n,a,b);
           // cout<<"res is : "<<res<<endl;
            if(res>0){
                printf("+");
            }
            else if(res<0)
                printf("-");
            else printf("0");
         }
    }
    printf("\n");
}

int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        solve(n,q);
    }
    return 0;
}


/*
Input :

4 6 -2 6 0 -1 C 1 10 P 1 4 C 3 7 P 2 2 C 4 -5 P 1 4

5 9 1 5 -2 4 3 P 1 2 P 1 5 C 4 -5 P 1 5 P 4 5 C 3 0 P 1 5 C 4 -5 C 4 -5

*/
