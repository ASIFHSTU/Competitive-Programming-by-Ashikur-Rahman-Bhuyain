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
#define oh cout<<"Problem ta ki?  "<<endl;

///vector
#define Lower_bound(vec,value) lower_bound(vec.begin(),vec.end(),value)
#define Upper_bound(vec,value) upper_bound(vec.begin(),vec.end(),value)

/// File In
#define READ(f)              freopen(f,  "r" ,stdin)
#define WRITE(f)             freopen(f,  "w" ,stdout)


///data type
#define ll long long int;
#define SIZ 1000005
struct data
{
    double number;
    data(double n)
    {
        number=n;
    }
    bool operator < (const data &p) const
    {
        return number>p.number;
    }
};
void solve()
{
    int num;
    vector<data>v;
    while(true)
    {
        cin>>num;
        if(num==0)break;
        v.push_back(data((double)num));

    }
    Sort(v);
    int p=1;
    int cost=0;
    for(int i=0;i<v.size();i++)
    {
        cost+=((2*pow(v[i].number,p))+0.5);
        p++;
        if(cost>5000000)
        {
            cout<<"Too expensive\n";
            return;
        }
    }
    cout<<cost<<endl;
}
int main()
{
     //READ("input.txt");
    //WRITE("output.txt");
   // cout<<"program started."<<endl;
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        solve();
    }
    return 0;
}
