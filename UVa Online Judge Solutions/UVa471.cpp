#include <bits/stdc++.h>
using namespace std;
#define MX 9876543210

bool check(long long int n)
{
    bool dig[20]={false};
    while(n)
    {
        if(dig[n%10])return false;
        dig[n%10]=true;
        n/=10;
    }
    return true;

}

void solve()
{
    long long int n;
    cin>>n;
    for(long long int i=1;i*n<=MX;i++)
    {
        if(check(i) and check(n*i))
        {
            printf("%lld / %lld = %lld\n",n*i,i,n);
        }
    }

}
int main()
{
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        if(i)cout<<endl;
        solve();
    }
}
