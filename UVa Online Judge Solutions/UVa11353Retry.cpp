#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 2000006
struct data
{
    ll value=0,cnt=0;
}A[mx];


bool primes[mx+1];
ll pd[mx+1];
int totalPrimes=1;
void sieve()
{
    pd[0]=2;
    for(int i=3;i<=20003;i+=2)
    {
        if(!primes[i])
        {
            pd[totalPrimes++]=i;
            for(int j=i*i;j<=2000002;j+=(i<<1))
            {
                primes[j]=1;
            }
        }
    }
}

void fact(int n)
{
    int number=n;
    int sqn=sqrt(n);
    int i=0;
    int ct=0;
    while(n>1)
    {
        if(pd[i]>sqn || i==totalPrimes-1)break;
        while(n%pd[i]==0)
        {
            n/=pd[i];
            ct++;
        }
        i++;
    }
    if(n>1)ct++;
    A[number].value=number;
    A[number].cnt=ct;
}
bool cmp(data a,data b)
{
    if(a.cnt==b.cnt)return a.value<b.value;
    return a.cnt<b.cnt;
}
int main()
{
    sieve();
    A[1].value=1;
    A[1].cnt=1;
    for(int i=2;i<=2000000;i++)
    {
        fact(i);
    }
    sort(A+1,A+2000001,cmp);
    int n,kase=1;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)return 0;
        printf("Case %d: %lld\n",kase,A[n].value);
        kase++;
    }

}
