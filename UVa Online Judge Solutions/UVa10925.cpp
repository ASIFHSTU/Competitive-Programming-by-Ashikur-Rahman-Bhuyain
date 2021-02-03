#include <bits/stdc++.h>
using namespace std;
#define Reverse(x) reverse(x.begin(),x.end())

string strsum(string st1,string st2)
{
    int len1=st1.size();
    int len2=st2.size();
    Reverse(st1);
    Reverse(st2);
    if(len1<len2)
    {
        swap(len1,len2);
        swap(st1,st2);
    }
    int sum=0,carry=0,r;
    string res;
    for(int i=0;i<len1;i++)
    {
        if(i>=len2)
        {
            sum=(st1[i]-'0')+carry;
        }
        else
        {
            sum=(st1[i]-'0')+(st2[i]-'0')+carry;
        }
        r=sum%10;
        res.push_back((r+'0'));
        carry=sum/10;

    }
    while(carry)
    {
        r=carry%10;
        res.push_back(r+'0');
        carry/=10;
    }
    Reverse(res);
    return res;

}

string strdiv(string st,int div)
{
    int changeVersion=0;
    int len=st.size();
    string resultString;
    bool ok=false;
    int res;
    for(int i=0;i<len;i++)
    {
        changeVersion*=10;
        changeVersion+=(st[i]-'0');
        res=changeVersion/div;
        changeVersion=changeVersion%div;
        if(res==0 and !ok)
        {
            continue;
        }
        resultString.push_back(res+'0');
        ok=true;
    }
    if(resultString.size()==0)resultString.push_back('0');

    return resultString;
}

void solve(int n,int f)
{
    string st1,st2;
    string total;
    for(int i=0;i<n;i++)
    {
        cin>>st1;
        total=strsum(total,st1);
    }
   // cout<<"total is : "<<total<<endl;

    string Result=strdiv(total,f);

    //cout<<"Dividation result is : "<<Result<<endl;
    cout<<" costs "<<total<<": each friend should pay "<<Result<<endl;
}

int main()
{
    int n,f;
    int tc=1;
    while(cin>>n>>f)
    {
        if(n==0 and f==0)return 0;

        cout<<"Bill #"<<tc;
        solve(n,f);
        cout<<endl;
        tc++;

    }
}
