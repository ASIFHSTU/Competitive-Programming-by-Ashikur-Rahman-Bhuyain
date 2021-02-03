#include <bits/stdc++.h>
using namespace std;
//long int dp[200000];
long long int findlen(long long int a)
{
    if(a==1)return 0;
    // if(dp[a]!=-1)return dp[a];
     if(a%2==0)return 1+findlen(a/2);

    else{
        return 1+findlen(a*3+1);
    }
}
int main()
{
   // memset(dp,-1,sizeof(dp));
    int a,b;
    long long int res_len;
    while(true)
    {
        res_len=-1;
        int res_id=-1;
        cin>>a>>b;
        if(a>b)swap(a,b);
        if(a==0 and b==0)return 0;
        for(int i=a;i<=b;i++)
        {
            long long int len=0;
            if(i==1)len=3;
            else
              len=findlen(i);
              if(len>res_len)
              {
                  res_id=i;
                  res_len=len;
              }
        }
        cout<<"Between "<<a<<" and "<<b<<", "<<res_id<<" generates the longest sequence of "<<res_len<<" values."<<endl;
    }
}
