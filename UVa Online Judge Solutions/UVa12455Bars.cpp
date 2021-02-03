#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int value;
    cin>>value;
    int n;
    cin>>n;
    int ar[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }

    for(int i=0;i<(1<<n);i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))sum+=ar[j];

        }
        if(sum==value)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";

}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)solve();

    return 0;
}
