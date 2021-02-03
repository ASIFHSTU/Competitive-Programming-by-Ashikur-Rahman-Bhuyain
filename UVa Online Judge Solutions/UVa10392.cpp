/*
   UVa10392
   factorizing prime numbers
   */

#include <bits/stdc++.h>
using namespace std;
#define N 10000002
vector<int>primes;
bool chk[N+1];
void sieve()
{
    primes.push_back(2);
    int sqn=sqrt(N)+1;
    for(int i=3;i<=sqn;i+=2)
    {
        if(chk[i]==false)
        {
            for(int j=i*i;j<N;j+=(i+i))
            {
                chk[j]=true;
            }
        }
    }
    for(int i=3;i<N;i+=2)
    {
        primes.push_back(i);
    }
}

void solve(long long int n)
{
   int sqn=sqrt(n)+1;
   for(int i=0;i<primes.size() and primes[i]<=sqn;i++)
   {
       while(n%primes[i]==0)
       {
           cout<<"    "<<primes[i]<<endl;
           n/=primes[i];
       }
   }
   if(n>1)
    cout<<"    "<<n<<endl;
   cout<<endl;
}

int main()
{
    sieve();

    long long int n;
    while(cin>>n)
    {
        if(n<0)
        {
            return 0;
        }
        solve(n);
    }
}
