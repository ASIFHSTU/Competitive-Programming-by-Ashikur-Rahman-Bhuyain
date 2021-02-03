#include <bits/stdc++.h>
using namespace std;
int n;
int ar[101];
int k[101][50001];
int knapsack(int index,int w)
{
    if(w==0 || index==n)return 0;
    if(k[index][w]!=-1)return k[index][w];
    if(w<ar[index])return k[index][w]=knapsack(index+1,w);
    return k[index][w]=max(ar[index]+knapsack(index+1,w-ar[index]),knapsack(index+1,w));
}

void solve()
{
    memset(k,-1,sizeof(k));
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
    }
    int w=sum/2;

    int fp=knapsack(0,w);
   // cout<<"Result is : ";
     int dd=sum-fp;
    cout<<abs(dd-fp)<<endl;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
}
