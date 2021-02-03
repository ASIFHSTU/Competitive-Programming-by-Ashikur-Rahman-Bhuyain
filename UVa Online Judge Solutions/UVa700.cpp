#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    int y[n],a[n],b[n],dif[n];
    int mainYear=0;
    for(int i=0;i<n;i++)
    {
        cin>>y[i]>>a[i]>>b[i];
        dif[i]=b[i]-a[i];
        mainYear=max(mainYear,y[i]);
    }
    int i;
    while(mainYear<10000)
    {
        for(i=0;i<n;i++)
        {
            if((mainYear-y[i])%dif[i]!=0)break;
        }
        if(i==n)break;
        mainYear++;
    }
    if(mainYear>=10000)
    {
        cout<<"Unknown bugs detected.\n";
    }
    else {
        cout<<"The actual year is "<<mainYear<<".\n";
    }
}

int main()
{
    int n;
    int cse=1;
    while(cin>>n)
    {
        if(n==0)return 0;
        cout<<"Case #"<<cse<<":\n";
        cse++;
        solve(n);
        cout<<endl;
    }
}
