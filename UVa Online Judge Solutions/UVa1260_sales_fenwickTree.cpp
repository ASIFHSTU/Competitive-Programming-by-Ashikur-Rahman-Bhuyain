#include <bits/stdc++.h>
using namespace std;
int ftree[5005];
int N=5005;
void update(int ind,int value)
{
    while(ind<=N)
    {
        ftree[ind]+=value;
        ind+=(ind&(-ind));
    }
}
int query(int ind)
{
    int sum=0;
    while(ind>0)
    {
        sum+=ftree[ind];
        ind-=(ind&(-ind));
    }
    return sum;
}
void solve()
{
    memset(ftree,0,sizeof(ftree));
    int n;
    cin>>n;
    int res=0;
    int v;
    for(int i=0;i<n;i++)
    {
        cin>>v;
        if(i)
        {
            res+=query(v);
        }
        update(v,1);
    }
    cout<<res<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)solve();
    return 0;
}
