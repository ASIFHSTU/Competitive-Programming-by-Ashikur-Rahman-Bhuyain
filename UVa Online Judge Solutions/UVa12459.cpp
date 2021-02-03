#include <bits/stdc++.h>
using namespace std;
long long int res[88];
void resfind()
{
    res[0]=0;
    res[1]=1;
    res[2]=2;
    for(int i=3;i<=80;i++)
    {
        res[i]=res[i-1]+res[i-2];
    }
}
int main()
{
    resfind();
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)return 0;
        cout<<res[n]<<endl;
    }
}
