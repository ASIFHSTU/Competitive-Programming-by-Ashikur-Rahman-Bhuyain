#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[11+2][30000+2];
void coinChangeNumberOfWay(int coin[],int n,int money)
{

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=money;j++)
        {
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
            if(i==0 || j==0)continue;
            if(j>=coin[i-1])
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];

            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
}

int main()
{
    int ar[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
    coinChangeNumberOfWay(ar,11,30000);
    double v;

    while(cin>>v)
    {
        int money=((v*100)+0.5);

        if(money==0)return 0;
          printf("%6.2f%17lld\n",v,dp[11][money]);
    }
}
