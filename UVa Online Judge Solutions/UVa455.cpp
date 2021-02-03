#include <bits/stdc++.h>
using namespace std;
int z[100];
void z_function(string st)
{
    int len=st.size();
    memset(z,0,sizeof(z));
    z[0]=len;
    for(int i=1,left=0,right=0;i<len;i++)
    {
        if(i<=right)
            z[i]=min(right-i+1,z[i-left]);
        while(i+z[i]<len && st[z[i]]==st[i+z[i]])z[i]++;

        if(i+z[i]-1>right)
        {
            left=i;
            right=i+z[i]-1;
        }
    }
}

void solve()
{
    string st;
    cin>>st;
    z_function(st);


    int len=st.size();

    for(int i=len-1;i>=0;i--)
    {
        int res=z[i];
        if(res==0)continue;
        if(len%res!=0)continue;
        bool yes=true;
        for(int j=res;j<len;j+=res)
        {
            if(z[j]<res)yes=false;
        }
        if(yes){
            cout<<res<<endl;
            return;
        }
    }


}

int main()
{
    int tc;
    cin>>tc;
    bool started=false;
    while(tc--)
    {
        if(started)cout<<endl;
        started=true;
        solve();
    }
}
