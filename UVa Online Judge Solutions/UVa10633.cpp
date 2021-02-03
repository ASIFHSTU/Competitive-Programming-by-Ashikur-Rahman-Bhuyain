#include <bits/stdc++.h>
using namespace std;
bool ok(unsigned long long n,unsigned long long v)
{
    if(n<10)return false;
    long long m=n/10;
    if(n-m==v)return true;
    return false;

}

int main()
{
    unsigned long long v;
    while(cin>>v)
    {
        if(v==0)return 0;
        bool started=false;
        unsigned long long temp=(v*10)/9;
        for(unsigned long long i=temp-10;i<=temp+10;i++)
        {
            if(ok(i,v))
            {
                if(started)cout<<" ";
                cout<<i;
                started=true;

            }
        }cout<<endl;
    }
}
