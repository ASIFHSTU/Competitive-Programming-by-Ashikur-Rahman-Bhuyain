#include <bits/stdc++.h>
using namespace std;
long long int dp[7][30005];
void coinChange(int coins[],int n,int money)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=money;j++)
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
    int coin;
    int coins[]={1,5,10,25,50};
    coinChange(coins,5,30000);
    while(cin>>coin)
    {
         if(dp[5][coin]==1)
         {
             printf("There is only 1 way to produce %d cents change.\n",coin);
         }
         else {
            printf("There are %lld ways to produce %d cents change.\n",dp[5][coin],coin);
         }
    }
    return 0;
}
