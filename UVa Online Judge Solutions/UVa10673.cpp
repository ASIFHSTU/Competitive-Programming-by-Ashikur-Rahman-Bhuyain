#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;cin>>tc;
    while(tc--)
    {
        int n,k;
        cin>>n>>k;
        int q=n%k;
        if(n>=k)
            cout<<k-q<<" "<<q<<endl;
        else cout<<"0 "<<q<<endl;
    }
    return 0;
}
