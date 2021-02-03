#include <bits/stdc++.h>
using namespace std;
long long int fib[80];
void makeFib()
{
    fib[0]=1;
    fib[1]=2;
    for(int i=2;i<=55;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
}


int main()
{
    makeFib();

    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int n;
        cin>>n;
        cout<<"Scenario #"<<i<<":\n";
        cout<<fib[n]<<endl<<endl;
    }
    return 0;
}

