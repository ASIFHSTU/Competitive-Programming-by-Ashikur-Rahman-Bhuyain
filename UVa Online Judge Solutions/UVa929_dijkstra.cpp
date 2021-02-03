#include <bits/stdc++.h>
using namespace std;
#define infinity INT_MAX
int cost[1000][1000];
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
struct data
{
    pair<int,int>axis;
    int cost;
    data(pair<int,int>p,int _cost)
    {
        axis=p;
        cost=_cost;
    }
    bool operator < (const data &p)const
    {
        return cost>p.cost;
    }
};
bool isvalid(int n,int m,int x,int y)
{
    if(x<0 || x>=n)
        return false;
    if(y<0 || y>=m)
        return false;
    return true;
}
int dijkstra(int n,int m)
{
    pair<int,int>res;
    res=make_pair(n-1,m-1);
    int distance[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            distance[i][j]=infinity;
        }
    }
    distance[0][0]=cost[0][0];
    priority_queue<data>pq;
    pq.push(data(make_pair(0,0),distance[0][0]));
    while(!pq.empty())
    {
        data T=pq.top();
        pq.pop();
        if(T.axis==res)
        {
            //cout<<"axis is : ("<<T.axis.first<<" , "<<T.axis.second<<")"<<endl;
            return T.cost;

        }
        for(int i=0; i<4; i++)
        {
            int nx=T.axis.first+dx[i];
            int ny=T.axis.second+dy[i];
            if(isvalid(n,m,nx,ny))
            {
                if(distance[T.axis.first][T.axis.second]+cost[nx][ny]<distance[nx][ny])
                {
                    distance[nx][ny]=distance[T.axis.first][T.axis.second]+cost[nx][ny];
                    pq.push(data(make_pair(nx,ny),distance[nx][ny]));
                }
            }
        }

    }

    return 1;
}
void solve()
{
    int n,m;
    cin>>n>>m;
  //  int cost[n+1][m+1];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>cost[i][j];
        }
    }
    //cout<<"Result is : ";
    cout<<dijkstra(n,m)<<"\n";
}
int main()
{
    int tc;
    cin>>tc;
    for(int i=0; i<tc; i++)
    {
        solve();
    }
}
