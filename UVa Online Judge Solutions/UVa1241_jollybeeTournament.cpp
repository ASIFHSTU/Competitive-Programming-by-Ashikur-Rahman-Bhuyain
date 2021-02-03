#include <bits/stdc++.h>
using namespace std;
#define MX 1030
int ar[MX+2];
int tree[MX*4+4];

int res;

void initAr(int sz)
{
    for(int i=0;i<=sz;i++)
    {
        ar[i]=1;
    }
}

void makeRes(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=ar[b];
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left|1;
    makeRes(left,b,mid);
    makeRes(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
    if(tree[node]==1)
    {
        res++;
    }
    else if(tree[node]==2)
    {
        tree[node]=1;
    }
}

void solve()
{
    res=0;
    int n,m,off;
    cin>>n>>m;
    int sz=1<<n;
    initAr(sz);
    for(int i=0;i<m;i++)
    {
        cin>>off;
        ar[off]=0;
    }
    makeRes(1,1,sz);
    cout<<res<<endl;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
}
