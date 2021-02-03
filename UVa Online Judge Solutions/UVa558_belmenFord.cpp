#include <bits/stdc++.h>
using namespace std;
void belmenford(int n,vector<int>g[],vector<int>cost[],int source)
{
    int distance[n];
    for(int i=0;i<n;i++)
    {
        distance[i]=INT_MAX;
    }
    distance[source]=0;
    bool has_neg_cycle=false;
    for(int k=1;k<=n;k++)
    {
        bool updated=false;
        for(int u=0;u<n;u++)
        {
            for(int i=0;i<(int)g[u].size();i++)
            {
                int v=g[u][i];
                if(distance[u]+cost[u][i]<distance[v])
                {
                    distance[v]=distance[u]+cost[u][i];
                    updated=true;
                }
            }
        }
        if(k==n and updated==true)
        {
            has_neg_cycle=true;
        }
    }
    if(has_neg_cycle)
    {
        cout<<"possible\n";
    }
    else {
        cout<<"not possible\n";
    }

}
void solve()
{
    int node,edge;
    cin>>node>>edge;
    vector<int>graph[node],cost[node];
    for(int i=0;i<edge;i++){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(y);
        cost[x].push_back(w);
    }
    belmenford(node,graph,cost,0);
}
int main()
{
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        solve();
    }
}
