#include <bits/stdc++.h>
using namespace std;

#define SZ 1000006

int check[SZ+5];
vector<long long int>primes;
void sieve()
{
    memset(check,0,sizeof(check));
    check[0]=check[1]=1;
    for(int i=4;i<=SZ;i+=2)
        check[i]=1;

    int sq=sqrt(SZ)+1;
    for(int i=3;i<=sq;i+=2)
    {
        if(check[i]==0)
        {
            for(int j=i*i;j<=SZ;j+=i+i)
                check[j]=1;
        }
    }
    primes.push_back(2);
    for(int i=3;i<=SZ;i+=2)
    {
        if(check[i]==0)primes.push_back(i);
    }

}

long long int NOPD(long long int n,long long int p)
{
    long long int ct=n/p;
    int po=p;
    p*=p;
    while(p<=n)
    {
        ct+=(n/p);
        p*=po;
    }
    return ct;
}

void solve(long long int n,long long int m)
{
    long long int div=m;
    for(int i=0;primes[i]*primes[i]<=m and i<primes.size();i++)
    {
        long long int ct=0;

        while(m%primes[i]==0)
        {
            ct++;
            m/=primes[i];
        }
        if(ct)
        {

            long long int ct2=NOPD(n,primes[i]);

            if(ct2<ct)
            {

                 printf("%lld does not divide %lld!\n",div,n);
                 return;
            }
        }
    }
    if(m>1 and n<m)
    {
        printf("%lld does not divide %lld!\n",div,n);
        return;
   }

    printf("%lld divides %lld!\n",div,n);
}

int main()
{
    sieve();
    int n,m;
    while(cin>>n>>m)
    {
        solve(n,m);
    }
}
