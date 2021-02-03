#include <bits/stdc++.h>
using namespace std;

bool comp(char a,char b)
{
    if(tolower(a)==tolower(b))
        return a<b;
    return tolower(a)<tolower(b);
}

void solve()
{
    map<string,int>res;
    map<string,int>::iterator it;
    string st;
    cin>>st;
    sort(st.begin(),st.end(),comp);
    res[st]=1;
    cout<<st<<endl;
    int len=st.size();
    while(next_permutation(st.begin(),st.end(),comp))
    {
        if(res[st]==0)
        {
            cout<<st<<endl;
            res[st]=1;
        }
    }


}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
        solve();

    return 0;
}
