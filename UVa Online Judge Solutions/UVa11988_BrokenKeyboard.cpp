/*
Name : Ashikur Rahman Bhuyain
Date : 21-5-2020

Problem Id : UVa 11988
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string st;
    while(cin>>st)
    {
        list<char>List;
        list<char>::iterator it=List.begin();
        int len=st.size();
        for(int i=0; i<len; i++)
        {
            if(st[i]=='[')
                it=List.begin();
            else if(st[i]==']')
                it=List.end();
            else
                List.insert(it,st[i]);
        }
        for(it=List.begin();it!=List.end();it++)
        {
            cout<<*it;
        }cout<<endl;
    }
}
