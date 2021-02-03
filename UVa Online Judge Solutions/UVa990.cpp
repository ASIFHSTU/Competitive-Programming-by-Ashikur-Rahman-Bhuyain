#include <bits/stdc++.h>
using namespace std;
#define Reverse(x) reverse(x.begin(),x.end())
#define mx 35
int val[mx];
int wt[mx];
int dp[mx][1005];
int knapsack(int n,int w)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)dp[i][j]=0;
            else if(j<wt[i-1])dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
        }
    }
    return dp[n][w];
}
void printKnapsack(int n,int w,int t)
{
    int res=knapsack(n,t);
    cout<<res<<endl;
    vector<int>v1,v2;
    for(int i=n;i>0 and res>0;i--)
    {
        if(res==dp[i-1][t])continue;
        else {
                int ww=(wt[i-1])/(3*w);
            v1.push_back(ww);
            v2.push_back(val[i-1]);
            res-=val[i-1]; t-=wt[i-1];
        }
    }
    Reverse(v1);
    Reverse(v2);
    int len=v1.size();
    //cout<<"Length is : ";
    cout<<len<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<v1[i]<<" "<<v2[i]<<endl;
    }
}
void solve(int t,int w)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
        wt[i]=3*w*wt[i];
    }
    printKnapsack(n,w,t);
}

int main()
{
    int t,w;
    int tc=0;
    while(cin>>t>>w)
    {
        if(tc)cout<<endl;
        tc++;
        solve(t,w);
    }
}
