#include <bits/stdc++.h>
using namespace std;
long long int longPower(long long int a,long long int b)
{
    long long int res=1;
    for(int i=1;i<=b;i++)
    {
        res*=a;
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    int ar[n+2];
    for(int i=0;i<=n;i++)
        cin>>ar[i];

    int d,k;
    cin>>d>>k;
    int totalD=0,tempD=0;
    long long int res=0;
    for(int i=1;;i++)
    {
        res=0;
        for(int j=0;j<=n;j++)res+=ar[j]*(longPower(i,j));
        tempD+=d;
        totalD+=tempD;
        if(totalD>=k)
        {
            cout<<res<<endl;
            return;
        }
    }
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
