/*
Name : Ashikur Rahman Bhuyain
Date : 24-5-2020

Problem ID : UVa414
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n, n)
    {
        vector<int>forAll;
        int mn=INT_MAX;
        string st;
        for(int i=0;i<n;i++)
        {
            cin.ignore();
            getline(cin,st);
            int sp=0;
            for(int i=0;i<st.size();i++)
            {
                if(st[i]!='X')
                {
                    sp++;
                }
            }
            if(sp<mn)
            mn=sp;
            forAll.push_back(sp);
        }
        int res=0;
        for(int i=0;i<forAll.size();i++)
        {
            res+=(forAll[i]-mn);
        }
        //cout<<"Result is : ";
        cout<<res<<endl;

    }
}


/**
Input :
4
XXXXBBBBBBBBBBBBBBBBXXXXX
XXXBBBBBBBBBBBBBBBXXXXXXX
XXXXXBBBBBBBBBBBBBBBBXXXX
XXBBBBBBBBBBBBBBBBBXXXXXX
2
XXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
1
XXXXXXXXXBBBBBBBBBBBBBBXX
0
*/
