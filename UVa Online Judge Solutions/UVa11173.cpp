/*
Name : Ashikur Rahman Bhuyain
Date : 23-5-2020

Problem Id : UVa11173(Reflected gray code)

*/
#include <bits/stdc++.h>
using namespace std;
#define BinaryToGray(k) (k^(k>>1))

int main()
{
    int tc;
    int n,k;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>k;
        cout<<BinaryToGray(k)<<endl;
    }
}
