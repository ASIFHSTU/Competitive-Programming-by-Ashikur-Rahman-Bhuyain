/*
Name : Ashikur Rahman Bhuyain
Date : 17-5-2020
Problem id :UVa 11466

*/

#include <bits/stdc++.h>
using namespace std;
#define mx 10000006
bool check[mx+10];
vector<long long int>primes;
void sieve()
{
    primes.push_back(2);
    int sqn=sqrt(mx)+1;
    for(int i=3;i<=sqn;i+=2)
    {
        if(check[i]==false)
        {
            for(int j=i*i;j<mx;j+=(i+i))
                check[j]=true;
        }
    }
    for(int i=3;i<mx;i+=2)
    {
        if(check[i]==false)
        {
            primes.push_back(i);
        }
    }

}

void solve(long long int n)
{
    if(n<=3){cout<<"-1\n";
    return;
    }
    int np=0;
    long long int res=0;
    for(int i=0;i<primes.size() and primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i]==0)
        {
            np++;
            res=primes[i];
            while(n%primes[i]==0)n/=primes[i];
        }
    }
    if(n!=1 and np>=1){
        cout<<n<<endl;
        return;
    }
    else if(np>1)
    {
        cout<<res<<endl;
        return;
    }
    cout<<"-1\n";
    return;
}

int main()
{
    sieve();
    long long int n;
    while(cin>>n)
    {
        if(n==0)return 0;
        if(n<0)n*=(-1);
        solve(n);
    }

}
