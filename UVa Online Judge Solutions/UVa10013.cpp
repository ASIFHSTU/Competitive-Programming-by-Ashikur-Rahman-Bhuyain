#include <bits/stdc++.h>
using namespace std;
#define Reverse(x) reverse(x.begin(),x.end())

string strSum(string st1,string st2)
{
    int len=st1.size();
    Reverse(st1);
    Reverse(st2);
    string res;
    int sum=0,carry=0,dig;
    for(int i=0;i<len;i++)
    {
        sum=(st1[i]-'0')+(st2[i]-'0')+carry;
        dig=sum%10;
        carry=sum/10;
        res.push_back(dig+'0');

    }
    Reverse(res);
    return res;
}

void solve()
{
    int m;
    string st1,st2;
    char d1,d2;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>d1>>d2;
        st1.push_back(d1);
        st2.push_back(d2);
    }

    string res=strSum(st1,st2);
    cout<<res<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        if(i)cout<<endl;
        solve();
    }
}
