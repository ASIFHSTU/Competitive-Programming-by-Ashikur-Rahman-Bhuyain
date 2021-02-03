#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
   bool seen[10005];
   for(int i=0;i<n;i++)
   {
       memset(seen,false,sizeof(seen));
       for(int j=0;j<=i;j++)seen[ar[j]]=true;

       for(int j=i+1;j<n;j++)
       {
           seen[ar[j]]=true;
           int nxt=ar[j]+(ar[j]-ar[i]);
           if(nxt>=0 and nxt<n and j<n-1 and !seen[nxt]){
            cout<<"no\n";
            return;
           }
       }
   }
   cout<<"yes\n";
   return;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)return 0;
        char ch;
        cin>>ch;
        solve(n);
    }
}
