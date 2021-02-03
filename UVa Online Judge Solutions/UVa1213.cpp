#include <bits/stdc++.h>
using namespace std;

vector<int>primes;
int chk[1125];
void sieve()
{
    int sq=sqrt(1120)+1;
    for(int i=3;i<=sq;i+=2)
    {
        if(chk[i]==0)
        {
            for(int j=i*i;j<=1120;j+=i+i)
                chk[j]=1;
        }
    }
    primes.push_back(2);
    for(int i=3;i<=1120;i+=2)if(chk[i]==0)primes.push_back(i);
}

int dp[1130][20];
void numberOfWay()
{
    int len=primes.size();
   // cout<<"Total primes : "<<len<<endl;
    dp[0][0]=1;
    for(int i=0;i<len;i++)
    {
        for(int j=1120;j>=primes[i];j--)
        {
            for(int k=1;k<15;k++)
            {
                dp[j][k]+=dp[j-primes[i]][k-1];
            }
        }
    }
}

int main()
{
    sieve();
    numberOfWay();
    int a,b;
    while(cin>>a>>b)
    {
        if(a==0 and b==0)return 0;
        cout<<dp[a][b]<<endl;

    }


}
