#include <bits/stdc++.h>
using namespace std;
long long int res[65];
void makeResult()
{
     res[0]=1;
     res[1]=2;
    for(int i=2;i<=60;i++)
    {
        res[i]=res[i-1]+res[i-2]+1;
    }
}
int main()
{
    makeResult();
    int n;
    while(true)
    {
        cin>>n;
        if(n==-1)return 0;
        cout<<res[n-1]<<" "<<res[n]<<endl;
    }
}
