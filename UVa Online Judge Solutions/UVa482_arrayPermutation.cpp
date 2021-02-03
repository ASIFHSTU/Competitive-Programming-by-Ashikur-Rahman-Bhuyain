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

struct data
{
    int index;
    string v;
    data(int _index,string _v)
    {
        index=_index;
        v=_v;
    }
    bool operator <(const data &p)const
    {
        return index<p.index;
    }
};

void solve()
{
    cin.ignore();

    string st1,st2;
    getline(cin,st1);

    getline(cin,st2);

    stringstream ss1,ss2;
    ss1<<st1;
    ss2<<st2;
    vector<data>info;
    int ind;
    int st2ind=0;
    string val;
    while(ss1>>ind)
    {   val.clear();
        while(st2[st2ind]!=' ' and st2ind<st2.size())
        {
            val.push_back(st2[st2ind]);
            st2ind++;
        }
        st2ind++;
        info.push_back(data(ind,val));
    }
     sort(info.begin(),info.end());

     int len=info.size();
     for(int i=0;i<len;i++)
     {
         cout<<info[i].v<<endl;
     }

//    cout<<"first string : "<<st1<<endl;
//    cout<<"second string : "<<st2<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    cin.ignore();
    for(int i=0;i<tc;i++)
    {
        if(i)cout<<endl;
        solve();
    }

    return 0;
}
