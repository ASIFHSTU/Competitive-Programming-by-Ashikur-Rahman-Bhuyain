#include <bits/stdc++.h>
using namespace std;

bool isSubsetPossible(int n,int ar[],int sum)
{
    bool dp[n+2][sum+2];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
            if(i==0 || j==0)continue;

           if(j>=ar[i-1])
                dp[i][j]=(dp[i-1][j])||(dp[i-1][j-ar[i-1]]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}

void solve()
{
    string st;
    getline(cin,st);
    stringstream s;
    s<<st;
    int n=0;
    int ar[100];
    int total=0;
    while(s>>ar[n]){
            total+=ar[n];
            n++;
    }
    if(total&1){
        cout<<"NO\n";
        return;
    }
    if(isSubsetPossible(n,ar,total/2))
    {
        cout<<"YES\n";
    }
    else {
    cout<<"NO\n";
    }
}

int main()
{
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--)solve();
    return 0;
}

/*
Input :
3
1 2 1 2 1
2 3 4 1 2 5 10 50 3 50
3 5 2 7 1 7 5 2 8 9 1 25 15 8 3 1 38 45 8 1

*/
