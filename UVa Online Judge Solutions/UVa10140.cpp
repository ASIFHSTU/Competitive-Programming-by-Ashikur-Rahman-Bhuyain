#include <bits/stdc++.h>
using namespace std;
//UVa914
#define N 47500
vector<int>primes;
bool check[N+5];

void sieve()
{
    primes.push_back(2);
    int sqn=sqrt(N)+1;
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

void solve(int l,int r)
{

    int limit=r-l+1;
   // cout<<"Limit is : "<<limit<<endl;
 if(limit<2)
    {
        cout<<"There are no adjacent primes.\n";
         return;
    }

    bool ck[limit+1];
    memset(ck,true,sizeof(ck));
    int sqb=sqrt(r)+1;
    vector<int>kprimes;

    for(long long int i=0;primes[i]<=sqb;i++)
    {
       long long int base=(l/primes[i])*primes[i];
        if(base<l)base+=primes[i];

        for(long long int j=base;j<=r;j+=primes[i])
        {
            ck[j-l]=false;
        }
        if(base==primes[i])ck[base-l]=true;
    }
    if(l==1)ck[0]=false;


    for(int i=0;i<limit;i++)
    {

         if( ck[i])
        {
            kprimes.push_back(i+l);
        }
    }


    int primeSize=kprimes.size();
    /// extra :
  //  cout<<"prime size : "<<primeSize<<endl;
//    for(int i=0;i<primeSize;i++)
//    {
//        cout<<kprimes[i]<<" ";
//    }cout<<endl;


    if(primeSize<2)
    {
        cout<<"There are no adjacent primes.\n";
         return;
    }

    int Uind=primeSize-1;
    int Lind=0;

     int minres[3];
     int maxres[3];
     minres[0]=INT_MAX;
     maxres[0]=INT_MIN;

    bool ok=false;
    for(int i=Lind;i<Uind;i++)
    {
          int d=kprimes[i+1]-kprimes[i];
          if(d<minres[0])
          {
              minres[0]=d;
              minres[1]=kprimes[i];
              minres[2]=kprimes[i+1];
          }
          if(maxres[0]<d)
          {
              maxres[0]=d;
              maxres[1]=kprimes[i];
              maxres[2]=kprimes[i+1];
          }
    }

    printf("%d,%d are closest, %d,%d are most distant.\n",minres[1],minres[2],maxres[1],maxres[2]);

}


int main()
{
    sieve();
    //int tc;
    //cin>>tc;
    int a,b;

    while(cin>>a>>b)
    {
        solve(a,b);
    }

}

