#include <bits/stdc++.h>
using namespace std;
int d,subSet,n,q;  // subset = subset size

int ar[210];
long long int dp[15][220][25];
long long int knapSack(int taken,int idx,int sum)
{
    if(taken==subSet)
    {
        if(sum==0)return 1;
        return 0;
    }
    if(idx>=n)return 0;
    if(dp[taken][idx][sum]!=-1)return dp[taken][idx][sum];
    int t=sum+ar[idx];
    t%=d;
    if(t<0)t+=d;
    long long int r1=knapSack(taken+1,idx+1,t);
    long long int r2=knapSack(taken,idx+1,sum);
    return dp[taken][idx][sum]=r1+r2;
}


void solve()
{
    int v;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    for(int i=0;i<q;i++)
    {
        cin>>d>>subSet;
        memset(dp,-1,sizeof(dp));
        printf("QUERY %d: %lld\n",i+1,knapSack(0,0,0));
    }

}

int main()
{
    int tc=1;
    while(cin>>n>>q)
    {
        if(n==0 and q==0)return 0;
        printf("SET %d:\n",tc);
        solve();
        tc++;
    }
}
