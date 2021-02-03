#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll bigMod(ll a,ll b,ll m)
{
    a%=m;
    ll res=1;
    while(b>0)
    {
        if(b&1)res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}

void solve()
{
    ll a,b;
    scanf("%lld%lld",&a,&b);

    ll lastThree=bigMod(a,b,1000);
    double t=b*log10(a);
    double ex=t-(ll)t;
    ll firstThree=pow(10,ex)*100;
    printf("%lld...%03lld\n",firstThree,lastThree);

}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)solve();

    return 0;
}
