#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int res=((((a*2)-b)*c)/(double)(a+b))+0.4;
        cout<<res<<endl;
    }
    return 0;
}
