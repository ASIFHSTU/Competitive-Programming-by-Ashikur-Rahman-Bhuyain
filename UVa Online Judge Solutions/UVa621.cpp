#include <bits/stdc++.h>
using namespace std;
int main()
{
    string st;
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>st;
        int len=st.size();
        if(st=="1" || st=="4" || st=="78")
            cout<<"+\n";
        else if(st[len-2]=='3' and st[len-1]=='5')
            cout<<"-\n";
        else if(st[0]=='9' and st[len-1]=='4')
            cout<<"*\n";
        else
            cout<<"?\n";
    }
    return 0;
}
