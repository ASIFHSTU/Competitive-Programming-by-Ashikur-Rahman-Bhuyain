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
#define pb push_back
///vector
#define Lower_bound(vec,value) lower_bound(vec.begin(),vec.end(),value)
#define Upper_bound(vec,value) upper_bound(vec.begin(),vec.end(),value)

/// File In
#define READ(f)              freopen(f,  "r" ,stdin)
#define WRITE(f)             freopen(f,  "w" ,stdout)


///data type
#define ll long long int;
#define SIZ 100001
void printar(int ar[],int s)
{
    cout<<"_____________________________________________"<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<ar[i]<<" ";
    }cout<<endl;
    cout<<"______________________________________________"<<endl;
}
void solve(string st1,string st2)
{
    int len1=st1.size();
    int len2=st2.size();
    int L[len1+1][len2+1];

    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            if(i==0 || j==0)
                L[i][j]=0;
            else if(st1[i-1]==st2[j-1])
            {
                L[i][j]=L[i-1][j-1]+1;
            }
            else {
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }
        }
    }
    cout<<L[len1][len2]<<endl;

}
int main()
{
   string st1,st2;
   while(getline(cin,st1))
   {
       getline(cin,st2);
       solve(st1,st2);
   }
    return 0;
}

