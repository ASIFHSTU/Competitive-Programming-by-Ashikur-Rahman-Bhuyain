#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
  int ar[n+2];
  long long int res=0,product=1;
   for(int i=0;i<n;i++)
   {
       cin>>ar[i];
   }
    for(int i=0;i<n;i++)
    {
        product=ar[i];
        res=max(res,product);
        for(int j=i+1;j<n;j++)
        {
            product*=ar[j];
            res=max(res,product);
        }
    }

    res=max(res,(long long int)0);
   cout<<"The maximum product is "<<res<<".\n\n";
}
int main()
{
    int n;
    int tc=1;
    while(cin>>n)
    {
        cout<<"Case #"<<tc<<": ";
        tc++;
        solve(n);
    }
}
