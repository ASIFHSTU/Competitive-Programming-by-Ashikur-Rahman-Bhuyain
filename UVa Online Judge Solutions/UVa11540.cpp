/*
      Institution : Hajee Mohammad Danesh Science and Technology University
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : asifurr087@gmail.com
*/


#include <bits/stdc++.h>
using namespace std;
#define FasterIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pi acos(-1.0)
#define mod 1000000007
#define TIME clock()*1.0/CLOCKS_PER_SEC
///Library
#define mem(a,b) memset(a,b,sizeof(a))
#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define SortA(ar,s) sort(ar,ar+s)
#define SortD(ar,s) sort(ar,ar+s,greater<int>())
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sq(x) (x)*(x)
#define CEIL(a,b) ((a/b)+((a%b)!=0))
#define oh cout<<"Problem ta ki?  "<<endl;
#define nl printf("\n")

///vector
#define Lower_bound(vec,value) lower_bound(vec.begin(),vec.end(),value)
#define Upper_bound(vec,value) upper_bound(vec.begin(),vec.end(),value)

/// File In
#define READ(f)              freopen(f,  "r" ,stdin)
#define WRITE(f)             freopen(f,  "w" ,stdout)


///data type
#define ll long long int;
#define SIZ 1000005

void solve(int route)
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n-1;i++)
    {
        cin>>ar[i];
    }
    int maxSoFar,curMax,sInd,eInd,s;
    maxSoFar=curMax=ar[0];
    sInd=eInd=s=0;

    for(int i=1;i<n-1;i++)
    {
        curMax+=ar[i];
        if(ar[i]>curMax)
        {
            s=i;
            curMax=ar[i];
        }
        if(curMax>=maxSoFar)
        {
            if(curMax==maxSoFar)
            {
                if(eInd-sInd<i-s)
                {
                    sInd=s;
                    eInd=i;

                }
            }
            else {
                sInd=s;
                eInd=i;
                maxSoFar=curMax;
            }
        }
    }
    if(maxSoFar<0)
    {
        cout<<"Route "<<route<<" has no nice parts\n";
        return;
    }
    cout<<"The nicest part of route "<<route<<" is between stops "<<sInd+1<<" and "<<eInd+2<<endl;


}

int main()
{
     int tc;
     cin>>tc;
     for(int i=1;i<=tc;i++)
     {
         solve(i);
     }
    return 0;
}





