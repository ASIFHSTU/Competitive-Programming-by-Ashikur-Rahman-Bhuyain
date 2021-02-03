#include<bits/stdc++.h>
using namespace std;
int parent[50005];

void makeSet(int n)
{
    for(int i=0;i<=n;i++)parent[i]=i;
}

int findParent(int node)
{
    if(node==parent[node])return node;

    return parent[node]=findParent(parent[node]);
}

void solve(int n,int m)
{

    int ct[n+2];
    memset(ct,0,sizeof(ct));
    makeSet(n);
    for(int i=0;i<m;i++)
    {
        int f1,f2;
        cin>>f1>>f2;
        int p1=findParent(f1);
        int p2=findParent(f2);
        if(p1!=p2)parent[p1]=p2;
    }

    int res=0;
    for(int i=1;i<=n;i++)
    {
        int par=findParent(i);
        ct[par]++;
        if(ct[par]==1)res++;
    }
   // cout<<"largest group : ";
    cout<<res<<endl;
}

int main()
{
    int tc=1;
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0 and m==0)return 0;
        printf("Case %d: ",tc);
        tc++;
        solve(n,m);
    }
    return 0;

}

