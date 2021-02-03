#include <bits/stdc++.h>
using namespace std;
long long int fib[15005];
void makeFib(){
  fib[0]=0;
  fib[1]=1;
  for(int i=2;i<=15005;i++)
  {
      fib[i]=fib[i-1]+fib[i-2];
      fib[i]=fib[i]%10000;
  }
}

void solve()
{
    int a,b,n,m;
    cin>>a>>b>>n>>m;
    if(m==1)n%=60;
    if(m==2)n%=300;
    if(m==3)n%=1500;
        if(m==4)n%=15000;


    int mod=1;
    for(int i=0;i<m;i++)
    {
        mod*=10;
    }

    if(n==0){
        cout<<a%mod<<endl;
        return;
    }
    if(n==1){
        cout<<b%mod<<endl;
        return;
    }

    long long int res;
    res=fib[n-1]*a+fib[n]*b;

    res=res%mod;
    cout<<res<<endl;
}

int main()
{
    makeFib();
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
}
