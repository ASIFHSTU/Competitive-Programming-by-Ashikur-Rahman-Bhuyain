#include <bits/stdc++.h>
using namespace std;
void solve(int f)
{
    int r;
    cin>>r;
    double a[f],b[r];
    for(int i=0;i<f;i++)cin>>a[i];
    for(int j=0;j<r;j++)cin>>b[j];
    int ms=f*r;
    int ct=0;
    double res[ms+5];
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<r;j++)
        {
            res[ct++]=a[i]/b[j];
        }
    }
    sort(res,res+ct);
    double Result=-1;
    for(int i=0;i<ct-1;i++)
    {
        Result=max(Result,res[i+1]/res[i]);
    }

    printf("%.2lf\n",Result);
}
int main()
{
    int f;
    while(cin>>f)
    {
        if(f==0)return 0;
        solve(f);
    }
}
