#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    int ar[n];
    for(int i=0;i<n;i++)cin>>ar[i];

    int m;
    cin>>m;
    sort(ar,ar+n);
    int j=n-1;
    int i=0;
    int r1,r2;
    while(i<j)
    {
        if(ar[i]+ar[j]==m)
        {
            r1=ar[i];
            r2=ar[j];
            i++;
            j--;
        }
        else if(ar[i]+ar[j]>m)j--;
        else i++;

    }
    printf("Peter should buy books whose prices are %d and %d.\n\n",r1,r2);
}

int main()
{
    int n;
    while(cin>>n)solve(n);

    return 0;
}
