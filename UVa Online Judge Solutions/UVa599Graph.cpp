#include <bits/stdc++.h>
using namespace std;

vector<int>adj[30];
int color[30];
int tr,acorn;

void printGraph()
{
    for(int i=0;i<30;i++)
    {
        if(color[i]==0)
        {
            cout<<i<<" -> ";
            for(int j=0;j<adj[i].size();j++)
            {
                cout<<adj[i][j]<<" ";
            }cout<<endl;
        }
    }
}

void dfsvisit(int nd)
{
    color[nd]=1;
    for(int i=0;i<adj[nd].size();i++)
    {
        if(color[adj[nd][i]]==0)
        {
            dfsvisit(adj[nd][i]);

        }

    }
}
void dfs()
{
    for(int i=0;i<30;i++)
    {
        if(color[i]==0)
        {
            if(adj[i].size()==0)acorn++;
            else {
                tr++;
                dfsvisit(i);
            }
        }
    }
}

void extract(string st)
{
    for(int i=0;i<st.size();i++)
    {
        if(st[i]>='A' and st[i]<='Z')
            {
                color[st[i]-'A']=0;
            }
    }
}
void init()
{
    for(int i=0;i<30;i++)adj[i].clear();
    memset(color,-1,sizeof(color));
    tr=0;
    acorn=0;
}

void solve()
{
    init();
    char brkt,coma,u,v;
    string ajaira;
    while(true)
    {
        cin>>ajaira;
        if(ajaira[0]=='*'){
            break;
        }
        u=ajaira[1];
        v=ajaira[3];
        adj[u-'A'].push_back(v-'A');
        adj[v-'A'].push_back(u-'A');
    }
    string allNode;
    cin.ignore();
    getline(cin,allNode);
   // cout<<"AllNode string is : "<<allNode<<endl;
    extract(allNode);
   // printGraph();
    dfs();
    printf("There are %d tree(s) and %d acorn(s).\n",tr,acorn);
}

int main()
{
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--)solve();

    return 0;
}

/*
Input :

2 (A,B) (B,C) (B,D) (D,E) (E,F) (B,G) (G,H) (G,I) (J,K) (K,L) (K,M) ****
A,B,C,D,E,F,G,H,I,J,K,L,M,N
(A,B) (A,C) (C,F) **
A,B,C,D,F
*/
