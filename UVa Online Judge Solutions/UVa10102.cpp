#include <bits/stdc++.h>
using namespace std;
#define SZE 1000

int m;
int xm[4]={1,-1,0,0};
int ym[4]={0,0,1,-1};
bool isValid(int i,int j)
{
    if(i<0 || i>=m)return false;
    if(j<0 || j>=m)return false;
    return true;
}
void solve()
{
    vector<pair<int,int>>start;
    string st[m+1];

    int ar[m+1][m+1];

    for(int i=0;i<m;i++)
    {    cin>>st[i];
        for(int j=0;j<m;j++)
        {
            ar[i][j]=st[i][j]-'0';
           if(ar[i][j]==1)
           {
               start.push_back(make_pair(i,j));
           }

        }
    }

    int len=start.size();
    int dis=0;
    for(int ss=0;ss<len;ss++){
         bool brk=false;
        int color[m+1][m+1];
        int level[m+1][m+1];
        memset(color,0,sizeof(color));
        memset(level,0,sizeof(level));

        queue<pair<int,int>>q;
        q.push(start[ss]);
        int x=start[ss].first;
        int y=start[ss].second;
        color[x][y]=1;
        level[x][y]=0;
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
             x=p.first;
             y=p.second;
             for(int i=0;i<4;i++)
             {
                 if(isValid(x+xm[i],y+ym[i]) and color[x+xm[i]][y+ym[i]]==0)
                 {
                     color[x+xm[i]][y+ym[i]]=1;
                     level[x+xm[i]][y+ym[i]]=level[x][y]+1;
                     q.push(make_pair(x+xm[i],y+ym[i]));
                     if(ar[x+xm[i]][y+ym[i]]==3)
                     {
                         dis=max(dis,level[x][y]+1);
                         brk=true;
                         break;


                     }
                 }
                 if(brk)break;
             }
             if(brk)break;
        }
    }

     cout<<dis<<endl;

}
int main()
{
    while(cin>>m)
    {
        solve();
    }
    return 0;
}
