#include <bits/stdc++.h>
using namespace std;

bool isNeighbors(int i,int j)
{
    int n=i^j;
    return (n&(-n))==n;
}

void solve(int n)
{
    int potent[1<<n];
    memset(potent,0,sizeof(potent));
    int value;
    for(int i=0;i<(1<<n);i++)
    {
        cin>>value;
        for(int j=0;j<(1<<n);j++)
        {
           if(isNeighbors(i,j) and i!=j)potent[j]+=value;
        }
    }
    int mx=0;
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            if(isNeighbors(i,j) and i!=j)
            {
                mx=max(mx,potent[i]+potent[j]);
            }
        }
    }
   // cout<<"res is  : ";
    cout<<mx<<endl;
}

int main()
{
    int n;
    while(cin>>n)
    {
        solve(n);
    }
}
