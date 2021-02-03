#include <bits/stdc++.h>
using namespace std;
#define elements 30005
int parent[elements];
void makeSet(int n)
{
    for(int i=0;i<=n;i++)parent[i]=i;
}

int FindParent(int element)
{
    if(parent[element]==element)return element;

    return parent[element]=FindParent(parent[element]);
}
void solve(int n,int m)
{
    makeSet(n);
    int k;
    for(int i=0;i<m;i++)
    {
        cin>>k;
        int ar[k+1];
        int localParent;
        for(int j=0;j<k;j++)
        {
            cin>>ar[j];
            if(j==0)localParent=FindParent(ar[j]);
            int tempP=FindParent(ar[j]);
            if(tempP!=localParent)parent[tempP]=localParent;
        }

    }
    int res=0;
    int zp=FindParent(0);
    for(int i=0;i<n;i++)
    {
        if(FindParent(i)==zp)res++;
    }
    //cout<<"Result is : ";
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
