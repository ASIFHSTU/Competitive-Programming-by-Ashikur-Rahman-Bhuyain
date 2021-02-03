#include <bits/stdc++.h>
using namespace std;

#define SZ 100005
int check[SZ+5];
vector<int>primes;
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

int euler_phi(int n)
{
    int res=n;
    int root=sqrt(n)+1;
    for(int i=0;i<primes.size() && primes[i]<root;i++)
    {
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
                n/=primes[i];
            res-=(res/primes[i]);
            root=sqrt(n)+1;
        }
    }
    if(n>1)res-=(res/n);
    return res;
}



int main()
{
    sieve();
    int n;
    while(scanf("%d",&n)!=EOF){
            if(n==0)return 0;
        printf("%d\n",euler_phi(n));
    }
}
