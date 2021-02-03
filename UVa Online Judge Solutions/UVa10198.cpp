#include <bits/stdc++.h>
using namespace std;
int dp[4][1001];
int ar[4]={1,1,2,3};
int ways(int type,int value)
{
    if(value==0)return 1;
    if(value<0 || type==4)return 0;
    if(dp[type][value]!=-1)return dp[type][value];
    return dp[type][value]=ways(type+1,value)+ways(type,value-ar[type]);
}

void solve(int n)
{
    int w=ways(0,n);
    cout<<"Result is : ";
    cout<<w<<endl;
}
int main()
{
    int n;
    memset(dp,-1,sizeof(dp));
    while(cin>>n)solve(n);
    return 0;
}
