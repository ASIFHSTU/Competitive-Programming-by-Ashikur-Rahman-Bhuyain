#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    sort(ar,ar+n);
    int left=0,right=n-1;

    int m,q;
    cin>>m;
    int res;
    for(int i=0;i<m;i++)
    {
        cin>>q;
        left=0;
        right=n-1;
        res=ar[left]+ar[right];
        while(left<right)
        {
            int s=ar[left]+ar[right];
            int d1,d2;
            d1=abs(q-res);
            d2=abs(q-s);
            if(d2<d1)res=s;
            if(ar[left]+ar[right]>q)
                right--;
            else left++;

        }
        printf("Closest sum to %d is %d.\n",q,res);
    }
}

int main()
{
    int n;
    int kase=1;
    while(cin>>n)
    {
        if(n==0)return 0;
        printf("Case %d:\n",kase);
        kase++;
        solve(n);
    }
}
