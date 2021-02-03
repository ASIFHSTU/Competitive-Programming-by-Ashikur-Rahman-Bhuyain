#include <bits/stdc++.h>
using namespace std;
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
int adj[200][200];
int visited[200][200];

bool isValid(int i,int j,int n)
{
    if(i<0 || i>=n || i<0 || j>=n)return false;
    if(visited[i][j] || adj[i][j]==0)return false;
    return true;
}

void dfs(int i,int j,int n)
{
    visited[i][j]=1;
    for(int k=0;k<8;k++)
    {
        if(isValid(i+fx[k],j+fy[k],n))
        {
            dfs(i+fx[k],j+fy[k],n);
        }
    }
}

void solve(int n,int tc)
{
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='0')adj[i][j]=0;
            else adj[i][j]=1;
        }
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!visited[i][j] and adj[i][j]==1)
            {
                res++;
                dfs(i,j,n);
            }

        }
    }

    printf("Image number %d contains %d war eagles.\n",tc,res);

}

int main()
{
    int n;
    int tc=0;
    while(cin>>n)solve(n,++tc);

    return 0;
}
