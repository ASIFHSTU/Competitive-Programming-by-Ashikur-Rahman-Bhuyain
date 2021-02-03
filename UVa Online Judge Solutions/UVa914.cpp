#include <bits/stdc++.h>
using namespace std;
//UVa914
#define N 1000009
vector<int>primes;
bool check[N];

void sieve()
{
    primes.push_back(2);
    int sqn=sqrt(1000005)+1;
    for(int i=3;i<=sqn;i+=2)
    {
        if(check[i]==false)
        {
            for(int j=i*i;j<N;j+=(i+i))
            {
                check[j]=true;
            }
        }
    }

    for(int i=3;i<N;i+=2)
    {
        if(check[i]==false)
        {
            primes.push_back(i);
        }
    }



}

void solve()
{
    int l,r;
    cin>>l>>r;
    if(r<3)
    {
        cout<<"No jumping champion\n";
        return;
    }
    int primeSize=primes.size();

    int Lind=lower_bound(primes.begin(),primes.end(),l)-primes.begin();
    int Uind=lower_bound(primes.begin(),primes.end(),r)-primes.begin();
    if(primes[Uind]!=r)Uind--;

    map<int,int>Dvalue;
    int champion=0;
    int championValue=0;
    bool ok=false;
    for(int i=Lind;i<Uind;i++)
    {
        int d=primes[i+1]-primes[i];
        Dvalue[d]++;
        int forC=Dvalue[d];
        if(forC>championValue)
        {
            championValue=forC;
            champion=d;
            ok=true;
        }
        else if(forC==championValue)
        {
            ok=false;
        }
    }
    if(ok)
    {
        cout<<"The jumping champion is "<<champion<<endl;
        return;
    }
    cout<<"No jumping champion\n";
}


int main()
{
    sieve();
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }

}
