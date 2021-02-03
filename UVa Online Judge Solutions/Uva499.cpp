#include <bits/stdc++.h>
using namespace std;

void solve(string st)
{
    int len=st.size();
    int ar[100];
    memset(ar,0,sizeof(ar));
    int mxf=0;
    for(int i=0;i<len;i++)
    {
        if(st[i]>='A' and st[i]<='Z')
        {
            ar[st[i]-'A']++;
            mxf=max(mxf,ar[st[i]-'A']);
        }
        else if(st[i]>='a' and st[i]<='z')
        {
            ar[st[i]-'a'+26]++;
            mxf=max(mxf,ar[st[i]-'a'+26]);
        }
    }

    string res;
    for(int i=0;i<26;i++)
    {
        if(ar[i]==mxf)
        {
            res.push_back(i+'A');
        }
    }
    for(int i=26;i<52;i++)
    {
        if(ar[i]==mxf)
        {
            res.push_back(i-26+'a');
        }
    }
    cout<<res<<" "<<mxf<<endl;

}

int main()
{
    string st;
    while(getline(cin,st))
    {
        solve(st);
    }
    return 0;
}
/*
Input :
When riding your bicycle backwards down a one-way street, if the
wheel falls of a canoe, how many ball bearings does it take to fill
up a water buffalo?
Hello Howard.

Output :


*/
