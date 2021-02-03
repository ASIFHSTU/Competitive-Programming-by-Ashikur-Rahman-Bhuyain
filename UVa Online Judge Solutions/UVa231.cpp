#include <bits/stdc++.h>
using namespace std;
void MISSAIL(vector<int>ar,int n)
{
    int m[n];
    for(int i=0;i<n;i++)
    {
        m[i]=1;
    }
    int mx=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(ar[i]<ar[j] and m[j]+1>m[i])
            {
                m[i]=m[j]+1;
                if(m[i]>mx)mx=m[i];
            }
        }
    }
    cout<<mx<<endl;
}
void solve(int v)
{
    vector<int>ar;
    ar.push_back(v);
    while(true)
    {
        cin>>v;
        if(v==-1)break;
        ar.push_back(v);
    }
    int len=ar.size();
    MISSAIL(ar,len);
}
int main()
{
    int v;
    int tc=1;
    while(true)
    {
        cin>>v;
        if(v==-1)
            return 0;

            if(tc!=1)
            {
                cout<<endl;
            }
        cout<<"Test #"<<tc<<":\n";
        cout<<"  maximum possible interceptions: ";
        solve(v);
        tc++;
    }
}
