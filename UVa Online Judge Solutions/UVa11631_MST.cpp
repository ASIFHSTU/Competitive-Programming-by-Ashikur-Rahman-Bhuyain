/*
      Institution : Hajee Mohammad Danesh Science and Technology University
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : asifurr087@gmail.com
*/

/// UVa 11631
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
    int u,v,w;
    data(int _u,int _v,int _w)
    {
        u=_u;
        v=_v;
        w=_w;
    }
    bool operator < (const data &p)const
    {
        return w<p.w;
    }
};
int parent[200001];
void makeset(int n)
{
    for(int i=0;i<=n;i++)parent[i]=i;
}
int Representative(int n)
{
    if(parent[n]==n)return n;
    else return parent[n]=Representative(parent[n]);
}
void solve(int node,int edge)
{
    makeset(node);
    int a,b,cost;
    vector<data>g;
    int total_cost=0;
    for(int i=0;i<edge;i++)
    {
        cin>>a>>b>>cost;
        total_cost+=cost;
        data T(a,b,cost);
        g.push_back(T);
    }
    sort(g.begin(),g.end());
    int n,sum;
    n=sum=0;
    for(int i=0;i<(int)g.size();i++)
    {
        int u=g[i].u;
        int v=g[i].v;
        int w=g[i].w;
        int ru=Representative(u);
        int rv=Representative(v);
        if(ru!=rv)
        {
            parent[ru]=rv;
             sum+=w;
             n++;
             if(n==node-1)
             {
                 //cout<<"Save is : ";
                 cout<<total_cost-sum<<"\n";
                 return;
             }
        }
    }


    return;

}
int main()
{
     //READ("input.txt");
    //WRITE("output.txt");
   // cout<<"program started."<<endl;
    int n,e;
    while(true)
    {
        cin>>n>>e;
        if(n==0)return 0;
        solve(n,e);
    }
    return 0;
}





