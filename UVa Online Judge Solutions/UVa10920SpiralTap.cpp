#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,p;
    long long int x,y;
    while(cin>>n>>p)
    {
        if(n==0)return 0;
        if(p==1)
        {
            cout<<"Line = "<<(n/2)+1<<", column = "<<(n/2)+1<<".\n";
            continue;
        }
        long long int i=1;
        while(i*i<p)i+=2;

        long long int lb=(i-2)*(i-2);
        long long int pad=(n-i)/2;
        if(p<=lb+(i-1))
        {
            x=lb+i-p+pad;
            y=n-pad;
        }
        else if(p>lb+(i-1) and p<=lb+2*(i-1))
        {
             x=pad+1;
             y=lb+2*(i-1)-p+pad+1;
        }
        else if(p>lb+2*(i-1) and p<=lb+3*(i-1))
        {
            y=pad+1;
            x=p-(lb+2*(i-1))+pad+1;
        }
        else {
            x=n-pad;
            y=p-(lb+3*(i-1))+pad+1;
        }

        cout<<"Line = "<<y<<", column = "<<x<<".\n";
    }
}
