#include <bits/stdc++.h>
using namespace std;
#define FasterIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int ar[40];
int dp[25][62400];
int knapsackIte(int n,int w)
{

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)dp[i][j]=0;
            else if(ar[i-1]>j)dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],ar[i-1]+dp[i-1][j-ar[i-1]]);
        }
    }

    return dp[n][w];
}

void knapsackPrint(int n,int w)
{
    int res=knapsackIte(n,w);
    int r=res;
    vector<int>resAr;
    for(int i=n;i>0 and w>0;i--)
    {
        if(res==dp[i-1][w])continue;
        else {
                resAr.push_back(ar[i-1]);
            //cout<<ar[i-1]<<" ";
            res-=ar[i-1];
            w-=ar[i-1];
        }
    }
    int len=resAr.size();
    for(int i=len-1;i>=0;i--)
    {
        cout<<resAr[i]<<" ";
    }
    cout<<"sum:"<<r<<endl;
}

void solve(int w)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>ar[i];

    knapsackPrint(n,w);
}

int main()
{
    FasterIO;
    int w;
    while(cin>>w)solve(w);

    return 0;
}

/**
Input :
3 2 1 1
4 3 2 2 3
7 3 5 1 2
87 4 87 1 2 3
23 5 5 5 5 5 2
3 3 2 2 1
6 3 4 3 2
11 2 9 10
17 6 1 2 3 4 5 6
6 4 2 3 1 4
10 2 5 5
11 10 1 2 3 4 5 6 7 8 9 10
11 6 2 2 2 2 2 11

*/
