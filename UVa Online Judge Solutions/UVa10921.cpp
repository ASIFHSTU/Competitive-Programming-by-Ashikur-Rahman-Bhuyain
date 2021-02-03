/*
Name : Ashikur Rahman Bhuyain
Date : 18-5-2020
Problem id : UVa10921
*/
#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
void maping()
{
    int value=2;
    int index=1;
    for(int i=2;i<=9;i++)
    {
        int inc=3;
        if(i==7 || i==9)
        {
            inc=4;
        }
        for(int j=0;j<inc;j++)
        {
            mp[index]=i;
            index++;
        }
    }
}
int main()
{
   maping();

   string st;
   while(cin>>st)
   {
       int len=st.size();
       for(int i=0;i<len;i++)
       {
           if(st[i]>='A' and st[i]<='Z')
           {
               int value=st[i]-'A'+1;
               value=mp[value];
               cout<<value;
           }
           else {
            cout<<st[i];
           }
       }
       cout<<endl;
   }
}
