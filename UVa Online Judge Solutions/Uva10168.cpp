#include <bits/stdc++.h>
using namespace std;
#define N 10000002
bool check[N+2];

void sieve()
{
    check[0]=check[1]=true;
    for(int i=4;i<N;i+=2)
    {
        check[i]=true;
    }
    int sqn=sqrt(N)+1;
    for(int i=3;i<=sqn;i+=2)
    {
        if(!check[i])
        {
            for(int j=i*i;j<N;j+=(i+i))
            {
                check[j]=true;
            }
        }
    }
}

void solve(int n)
{
    if(n<8){
        cout<<"Impossible."<<endl;
        return;
    }
    int a,b,c,d;

    if(n%2==0)
    {
        a=2;
        b=2;
        n-=4;
    }
    else{
        a=2;
        b=3;
        n-=5;
    }
    for(int i=2;i<n;i++)
    {
        if(check[i]==false and check[n-i]==false)
        {
            cout<<a<<" "<<b<<" "<<i<<" "<<n-i<<endl;
            return;
        }
    }


}

int main()
{
    sieve();
    int n;
    while(cin>>n)solve(n);


}
