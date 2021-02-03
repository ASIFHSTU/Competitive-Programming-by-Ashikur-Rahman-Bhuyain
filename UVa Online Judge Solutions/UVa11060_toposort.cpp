/*
      Institution : Hajee Mohammad Danesh Science and Technology University
      Name        : Ashikur Rahman Bhuyain (Asif)
      Email       : asifurr087@gmail.com
*/

/// UVa 11060
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
    string node;
    int value;
    data(string _node,int _value)
    {
        node=_node;
        value=_value;
    }
    bool operator < (const data &p) const
    {
        return value>p.value;
    }
};

void solve(int n)
{
    vector<string>allnode;
    map<string,int>indegree;
    map<string,int>ind;
    int indd=1;

    map<string,vector<string>>adj;

    string node;
    for(int i=0; i<n; i++)
    {
        cin>>node;

        indegree[node]=0;
        ind[node]=indd;
        indd++;
        allnode.push_back(node);
    }
    int m;
    cin>>m;
    string n1,n2;
    for(int i=0; i<m; i++)
    {
        cin>>n1>>n2;
        indegree[n2]++;
        adj[n1].push_back(n2);
    }
    priority_queue<data>pq;
    for(int i=0; i<n; i++)
    {
        if(indegree[allnode[i]]==0)
        {
            pq.push(data(allnode[i],ind[allnode[i]]));
        }
    }
        string rrr;
        while(!pq.empty())
        {
            data T=pq.top();
            pq.pop();
            rrr=T.node;
            for(int i=0;i<(int)adj[rrr].size();i++)
            {
                string nst=adj[rrr][i];
                indegree[nst]--;
                if(indegree[nst]==0)pq.push(data(nst,ind[nst]));
            }
            cout<<" "<<T.node;
        }

    puts(".\n");

}
int main()
{
    //READ("input.txt");
     //WRITE("output.txt");
    // cout<<"program started."<<endl;
    int tc=1;
    int n;
    while(cin>>n)
    {
        cout<<"Case #"<<tc<<": Dilbert should drink beverages in this order:";
        tc++;
        solve(n);


    }
    return 0;
}





