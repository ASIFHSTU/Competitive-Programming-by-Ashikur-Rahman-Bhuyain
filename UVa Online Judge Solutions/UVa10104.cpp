#include <bits/stdc++.h>
using namespace std;

long long ext_gcd(long long a,long long b,long long &X,long long &Y)
{
    //if(b>a)swap(a,b);
    long long x,x1,x2,y,y1,y2,r,r1,r2,q;
    x1=0;x2=1;
    y1=1;y2=0;
    for(r2=a,r1=b;r1!=0;r2=r1,r1=r,x2=x1,x1=x,y2=y1,y1=y)
    {
        q=r2/r1;
        r=r2%r1;
        x=x2-(q*x1);
        y=y2-(q*y1);
    }
    X=x2;
    Y=y2;
    return r2;
}

int main()
{
    long long a,b;
    while(cin>>a>>b)
    {
        long long x,y;
        long long g=ext_gcd(a,b,x,y);
        //if(x>y)swap(x,y);
        cout<<x<<" "<<y<<" "<<g<<endl;
    }
    return 0;
}
