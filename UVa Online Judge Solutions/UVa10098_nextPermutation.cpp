#include <bits/stdc++.h>
using namespace std;



void solve()
{
    map<string,int>res;
    map<string,int>::iterator it;
    string st;
    cin>>st;
    sort(st.begin(),st.end());
    res[st]=1;
    cout<<st<<endl;
    int len=st.size();
    while(next_permutation(st.begin(),st.end()))
    {
        if(res[st]==0)
        {
            cout<<st<<endl;
            res[st]=1;
        }
    }

    cout<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
        solve();

    return 0;
}

