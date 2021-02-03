#include <bits/stdc++.h>
using namespace std;
#define FasterIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)


void solve(int n,int m)
{
   // cout<<"Value of n and m is : "<<n<<", "<<m<<endl;
    map<char,int>mp;
    map<char,int>::iterator it;
    char ch;
    int ind=0;
    int visited[30];
    memset(visited,0,sizeof(visited));


    for(int i=0;i<3;i++)
    {
        cin>>ch;
        if(mp.find(ch)==mp.end())
        {
            mp[ch]=ind;
            visited[ind]=1;
            ind++;
        }
    }
     //  cout<<"Woken part taken."<<endl;
    char ch2;
    vector<string>edges;
    string st;
    for(int i=0;i<m;i++)
    {
        cin>>st;
        edges.push_back(st);
        ch=st[0];
        ch2=st[1];
        if(mp.find(ch)==mp.end())
        {
            mp[ch]=ind;
            ind++;
        }
        if(mp.find(ch2)==mp.end())
        {
            mp[ch2]=ind;
            ind++;
        }
    }

    if(n>mp.size())
    {
       // cout<<"First never occurs.\n";
       cout<<"THIS BRAIN NEVER WAKES UP\n";
       return;
    }

    int ct=3;
    int r=0;
    while(ct<n)
    {
        vector<int>to_mark;
        for(it=mp.begin();it!=mp.end();it++)
        {
            int joker=it->second;

            if(visited[joker])continue;

            int tcount=0;
            for(int i=0;i<edges.size();i++)
            {
                if(mp[edges[i][0]]==joker and visited[mp[edges[i][1]]])tcount++;
                if(mp[edges[i][1]]==joker and visited[mp[edges[i][0]]])tcount++;
            }


            if(tcount>=3)to_mark.push_back(joker);
        }

        ct+=to_mark.size();
        if(to_mark.empty())break;
        for(int i=0;i<to_mark.size();i++)
        {
            visited[to_mark[i]]=1;
        }
     r++;
     //cout<<"per step ct : "<<ct<<endl;
    }



    if(ct<n) cout<<"THIS BRAIN NEVER WAKES UP\n";
    else
     cout<<"WAKE UP IN, "<<r<<", YEARS\n";


}
int main()
{
    //FasterIO;
    int n,m;
    int kase=0;
    while(cin>>n>>m)
    {
        //if(kase)cout<<endl;
        //kase++;
        solve(n,m);
    }

}

/*
Input :
6 11
HAB
AB
AC
AH
BD
BC
BF
CD
CF
CH
DF
FH

5 0
ABZ

5 6
ABC
AD
AE
BD
BE
CD
CE

3 0
ABZ

4 0
ATJ

*/

