#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
    int ar[n];
    for(int i=0;i<n;i++)cin>>ar[i];

    for(int i=0;i<n-5;i++)
    {
        for(int j=i+1;j<n-4;j++)
        {
            for(int k=j+1;k<n-3;k++)
            {
                for(int l=k+1;l<n-2;l++)
                {
                    for(int m=l+1;m<n-1;m++)
                    {
                        for(int nn=m+1;nn<n;nn++)
                        {
                            printf("%d %d %d %d %d %d\n",ar[i],ar[j],ar[k],ar[l],ar[m],ar[nn]);
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    int f;
    int kase=0;
    while(cin>>f)
    {
        if(f==0)return 0;
        if(kase)cout<<endl;
        kase++;
        solve(f);
    }
}
