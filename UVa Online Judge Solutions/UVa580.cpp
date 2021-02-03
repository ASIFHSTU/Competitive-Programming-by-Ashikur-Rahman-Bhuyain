#include <bits/stdc++.h>
using namespace std;
long long int res[40];
long long int fib[40];
void makeRes()
{
    res[0]=res[1]=res[2]=0;
    res[3]=1;
    fib[0]=fib[1]=0;
    fib[2]=0;
    fib[3]=1;
    for(int i=4;i<=30;i++)
    {
        fib[i]=fib[i-3]+fib[i-2]+fib[i-1];
        res[i]=(2*res[i-1])+fib[i];
    }

}
int main()
{
    makeRes();
    while(true)
    {
        int n;
        cin>>n;
        if(n==0)return 0;
        cout<<res[n]<<endl;
    }
}
