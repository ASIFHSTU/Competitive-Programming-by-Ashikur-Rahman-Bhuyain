#include <bits/stdc++.h>
using namespace std;
int ar[25];
int ans,near,n,w;

void choose(int total,int mask,int ind)
{
    if(total>w)return;
    if(total>near)
    {
        near=total;ans=mask;
    }
    if(ind>=n)return;
    choose(total,mask,ind+1);
    choose(total+ar[ind],mask|(1<<ind),ind+1);

}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>ar[i];
    ans=near=-1;
    choose(0,0,0);
    for(int i=0;i<n;i++)
    {
        if((ans>>i)%2)cout<<ar[i]<<" ";
    }
    cout<<"sum:"<<near<<endl;

}

int main()
{
    while(cin>>w)solve();
    return 0;
}
