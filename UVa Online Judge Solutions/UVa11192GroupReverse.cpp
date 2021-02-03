/*
      Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh.
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

void solve(int totalGroup)
{
    string st;
    cin>>st;
    int len=st.size();
    int start=0;
    int curPos;
    int groupSize=len/totalGroup;
    while(totalGroup--)
    {
        curPos=start+groupSize;

        for(int i=curPos-1;i>=start;i--)
        {
            cout<<st[i];
        }
        start=start+groupSize;
    }cout<<endl;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)return 0;
        solve(n);
    }
}
