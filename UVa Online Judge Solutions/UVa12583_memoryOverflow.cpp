#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    string st;
    cin>>st;
    int ct[30];
    memset(ct,0,sizeof(ct));
    int res=0;
    int left=0;
    for(int r=0;r<n;r++)
    {
        if(r-left>k){
            ct[st[left]-'A']--;
            left++;
        }
        if(ct[st[r]-'A']>0)res++;
        ct[st[r]-'A']++;
    }
    cout<<res<<endl;
}
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        printf("Case %d: ",i);
        solve();
    }
    return 0;
}
