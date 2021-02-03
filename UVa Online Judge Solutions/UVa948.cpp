#include <bits/stdc++.h>
using namespace std;
long long int fib[80];
void makeFib()
{
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=50;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
}
void fibBase(int n)
{
   bool ok=false;
   for(int i=50;i>=2;i--)
   {
       if(n>=fib[i])
       {
           n-=fib[i];
           cout<<"1";
           ok=true;
       }
       else if(ok){
        cout<<"0";
       }
   }
}
void solve()
{
    int n;
    cin>>n;
    cout<<n<<" = ";
    if(n==0)cout<<"0";
    else
    fibBase(n);

    cout<<" (fib)"<<endl;


}
int main()
{
    makeFib();
//    printfib();
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        solve();
    }
    return 0;
}
