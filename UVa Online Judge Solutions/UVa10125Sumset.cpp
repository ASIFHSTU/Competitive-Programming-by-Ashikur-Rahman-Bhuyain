#include <bits/stdc++.h>
using namespace std;

int findIndex(int ar[],int n)
{
    int a,b;
    for(int d=n-1;d>=0;d--)
    {
        for(int c=0;c<n;c++)
        {
            if(c==d)continue;
            a=0;
            b=n-1;
            while(a==c || a==d)a++;
            while(b==c || b==d)b--;

            while(a<b)
            {
                int dif=ar[d]-(ar[a]+ar[b]+ar[c]);

                if(dif==0)return d;
                if(dif>0){
                    a++;
                    while(a==c || a==d)a++;
                }
                else {
                    b--;
                    while(b==c || b==d)b--;
                }
            }

        }
    }
    return -1;
}

void solve(int n)
{
    int ar[n+1];
    for(int i=0;i<n;i++)cin>>ar[i];

    sort(ar,ar+n);
    int ind=findIndex(ar,n);
    if(ind==-1)
        cout<<"no solution\n";
    else cout<<ar[ind]<<endl;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)return 0;
        solve(n);
    }
}
