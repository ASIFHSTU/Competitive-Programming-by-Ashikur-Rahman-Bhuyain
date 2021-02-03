/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : asifurr087@gmail.com
      Date        : 10-6-2020

      Problem ID  : UVa 11970
*/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    vector<int>res;
    cin>>n;
    long long int inc=1;
    while(inc*inc<n)
    {
        int mult=inc*inc;
        int ln=n-mult;
        if(ln%inc==0)res.push_back(ln);
        inc++;
    }
    int ls=res.size();
    for(int i=ls-1;i>=0;i--)
    {
        if(i==0)cout<<res[i];
        else cout<<res[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        printf("Case %d: ",i+1);
        solve();
    }
    return 0;
}
