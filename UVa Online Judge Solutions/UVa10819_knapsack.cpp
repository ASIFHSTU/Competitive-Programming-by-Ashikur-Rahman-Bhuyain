#include <bits/stdc++.h>
using namespace std;
int wt[105],val[105];
int dp[105][10300];
int knapsack(int n,int m,int idx,int w)
{
    if(w>m and w-m>200)return -1000000;
    if(w>m and m<1800) return -1000000;
    if(idx==n)
    {
        if(w<=2000 and w>m)return -10000;
        return 0;
    }

    if(dp[idx][w]!=-1)return dp[idx][w];
    return dp[idx][w]=max(val[idx]+knapsack(n,m,idx+1,w+wt[idx]),knapsack(n,m,idx+1,w));

}

void solve(int n,int m)
{
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    int r=knapsack(n,m,0,0);

    cout<<r<<endl;
}
int main()
{
    int n,m;
    while(cin>>m>>n)
    {
        solve(n,m);
    }
}
