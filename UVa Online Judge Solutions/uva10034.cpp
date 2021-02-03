/*
      Institution : Hajee Mohammad Danesh Science and Technology University
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : asifurr087@gmail.com
*/

/// Uva 10034
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
map<pair<double,double>,pair<double,double>>parent;

struct data
{
    double dis;
    pair<double,double>point1,point2;
    bool operator< (const data &p) const
    {
        return dis<=p.dis;
    }
};
pair<double,double> Find(pair<double,double> p)
{
    if(parent[p]==p)return p;
    else return parent[p]=Find(parent[p]);
}
void solve()
{
    parent.clear();

    int n;
    cin>>n;
    vector<data>all;
    pair<double,double>p1,p2;
    double  x[n+1],y[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        p1=make_pair(x[i],y[i]);
         parent[p1]=p1;

    }
    double dis;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            dis=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
            p1=make_pair(x[i],y[i]);
            p2=make_pair(x[j],y[j]);
            data d;
            d.point1=p1;
            d.point2=p2;
            d.dis=dis;
            all.push_back(d);



        }
    }
    sort(all.begin(),all.end());
    int ct=0;
    double sum=0;
    for(int i=0;i<(int)all.size();i++)
    {
        p1=all[i].point1;
        p2=all[i].point2;
        dis=all[i].dis;
        if(ct==n-1){
            printf("%.2f\n",sum);
            return;
        }
        pair<double,double>pp1,pp2;
        pp1=Find(p1);
        pp2=Find(p2);
        if(pp1!=pp2)
        {
            parent[pp1]=pp2;
            sum+=dis;
            ct++;
        }
    }
    printf("%.2f\n",sum);
}
int main()
{
    //READ("input.txt");
   // WRITE("output.txt");
    // cout<<"program started."<<endl;
    int tc;
    cin>>tc;
    for(int i=0; i<tc; i++)
    {
        if(i)cout<<"\n";
        solve();

    }
    return 0;
}





