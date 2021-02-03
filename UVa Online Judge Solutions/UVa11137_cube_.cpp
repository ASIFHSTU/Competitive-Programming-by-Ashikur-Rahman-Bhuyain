#include <bits/stdc++.h>
using namespace std;
long long int dp[25][10000];
void coinChangeWays(int coins[],int n,int sum)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=10000;j++)
        {
             if(i==0)dp[i][j]=0;
             if(j==0)dp[i][j]=1;
             if(i==0 || j==0)continue;
             if(j>=coins[i-1])
                            dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
             else dp[i][j]=dp[i-1][j];
        }
    }
}
int main()
{
    int coins[25];
    for(int i=1;i<22;i++)
    {
        coins[i-1]=i*i*i;
    }
    coinChangeWays(coins,21,10000);
    int coin;
    while(cin>>coin)
    {
        cout<<dp[21][coin]<<endl;
    }
    return 0;
}
