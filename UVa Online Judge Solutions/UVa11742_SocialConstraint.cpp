#include <bits/stdc++.h>
using namespace std;

int findIndex(int value,int ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(ar[i]==value)return i;
    }
}

void solve(int n,int m)
{
    int ar[n+1];
    for(int i=0;i<n;i++)
    {
        ar[i]=i;
    }
    int l[m+1],r[m+1],c[m+1];
    for(int i=0;i<m;i++)
    {
        cin>>l[i]>>r[i]>>c[i];

    }

    int res=0;
    do
    {
        bool yes=true;
        for(int i=0;i<m;i++)
        {
           int pos1=findIndex(l[i],ar,n);
           int pos2=findIndex(r[i],ar,n);
           if(c[i]>0 and abs(pos1-pos2)>c[i]){
            yes=false;
            break;
           }
           if(c[i]<0 and abs(pos1-pos2)<(-c[i]))
           {
               yes=false;
               break;
           }

        }
        if(yes)res++;
    }while(next_permutation(ar,ar+n));
    cout<<res<<endl;

}

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0 and m==0)return 0;
        solve(n,m);
    }
}
