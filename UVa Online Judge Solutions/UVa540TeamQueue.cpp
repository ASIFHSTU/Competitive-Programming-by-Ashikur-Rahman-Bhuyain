#include <bits/stdc++.h>
using namespace std;
map<int,int>id;

bool inQueue[1005];
queue<int>teamQueue;
queue<int>teams[1005];
void init()
{
    teamQueue=queue<int>();
    id.clear();
    for(int i=0;i<=1000;i++){
        inQueue[i]=false;
        teams[i]=queue<int>();
    }
}
void solve(int t)
{
    init();
    int s,tid,v;
    for(int i=0;i<t;i++)
    {
        cin>>s;
        for(int j=0;j<s;j++)
        {
            scanf("%d",&v);
            id[v]=i;
        }
    }

    string cmd;
    while(true)
    {
        cin>>cmd;
        if(cmd=="STOP")
        {
            cout<<endl;
            return;
        }

        if(cmd=="ENQUEUE")
        {
            cin>>v;
            int id_is=id[v];
            if(inQueue[id_is]==false)
            {
                inQueue[id_is]=true;
                teamQueue.push(id_is);
            }
            teams[id_is].push(v);
        }
        else {
            int tmId=teamQueue.front();
            cout<<teams[tmId].front()<<endl;
            teams[tmId].pop();
            if(teams[tmId].empty())
            {
                teamQueue.pop();
                inQueue[tmId]=false;
            }
        }
    }

}
int main()
{
    int t,tc=1;
    while(cin>>t)
    {
        if(t==0)return 0;
        printf("Scenario #%d\n",tc);
        solve(t);
        tc++;
    }
}
