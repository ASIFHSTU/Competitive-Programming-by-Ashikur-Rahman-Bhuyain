#include<bits/stdc++.h>
using namespace std;
int parent[30005];

void makeSet(int n)
{
    for(int i=0;i<=n;i++)parent[i]=i;
}

int findParent(int node)
{
    if(node==parent[node])return node;

    return parent[node]=findParent(parent[node]);
}

void solve()
{
    int n,m;
    cin>>n>>m;
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

    int largestGroup=0;
    for(int i=1;i<=n;i++)
    {
        int par=findParent(i);
        ct[par]++;
        largestGroup=max(largestGroup,ct[par]);
    }
   // cout<<"largest group : ";
    cout<<largestGroup<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)solve();

}
