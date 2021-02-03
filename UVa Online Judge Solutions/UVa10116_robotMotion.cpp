#include <bits/stdc++.h>
using namespace std;

bool isFinish(int r,int c,int a,int b)
{
    if(a<0 || b<0 || a>=r || b>=c)return true;
    return false;
}

void solve(int r,int c,int start)
{
    string adj[r+1];
    for(int i=0;i<r;i++)cin>>adj[i];

    int level[r+2][c+2],color[r+2][c+2];
    memset(level,-1,sizeof(level));
    memset(color,0,sizeof(color));
    queue<pair<int,int>>q;
    q.push({0,start-1});
    level[0][start-1]=0;
    color[0][start-1]=1;
    while(!q.empty())
    {
        pair<int,int>u=q.front();
        q.pop();
        int a,b;
        int cL=level[u.first][u.second];
        if(adj[u.first][u.second]=='N')
        {
            a=u.first -1;
            b=u.second;
        }
        else if(adj[u.first][u.second]=='S')
        {
            a=u.first+1;
            b=u.second;
        }
        else if(adj[u.first][u.second]=='W')
        {
            a=u.first;
            b=u.second-1;
        }
        else if(adj[u.first][u.second]=='E')
        {
            a=u.first;
            b=u.second+1;
        }

        if(isFinish(r,c,a,b))
        {
            cout<<cL+1<<" step(s) to exit\n";
            return;
        }
        if(color[a][b]!=0)
        {
            cout<<level[a][b]<<" step(s) before a loop of "<<cL+1-level[a][b]<<" step(s)\n";
            return;
        }
        level[a][b]=cL+1;
        q.push({a,b});
        color[a][b]=1;
    }

}
int main()
{
    int r,c,s;
    while(cin>>r>>c>>s)
    {
        if(r==0)return 0;
        solve(r,c,s);
    }
}
