#include <bits/stdc++.h>
using namespace std;
map<string,vector<string>>mp;
map<string,vector<string>>::iterator it;
string toLower(string tst)
{
    string temp;
    int len=tst.size();
    for(int i=0;i<len;i++)
    {
        temp.push_back(tolower(tst[i]));
    }
    return temp;
}
int main()
{
    string word,temp;
    while(cin>>word)
    {
        if(word=="#")break;
        temp=toLower(word);
        sort(temp.begin(),temp.end());
        mp[temp].push_back(word);
    }
    map<string,string>res;
    map<string,string>::iterator it2;
    for(it=mp.begin();it!=mp.end();it++)
    {
        vector<string>tp;
        tp=it->second;
        if(tp.size()==1)res[tp[0]]=tp[0];
    }
    for(it2=res.begin();it2!=res.end();it2++)
    {
        cout<<it2->second<<endl;
    }
    return 0;
}
