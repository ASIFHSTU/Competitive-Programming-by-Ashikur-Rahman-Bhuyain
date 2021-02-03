#include <bits/stdc++.h>
using namespace std;
#define S 1005
struct data
{
    int w,iq,index;
    data(int _w,int _iq,int i)
    {
        w=_w;
        iq=_iq;
        index=i;
    }
    bool operator <(const data &p)const
    {
        return iq>p.iq;
    }
};
int main()
{
    int index=1;
    int a,b;
    vector<data>vec;

    while(cin>>a>>b)
    {
        vec.push_back(data(a,b,index));
        index++;
    }
    sort(vec.begin(),vec.end());
    int L[index+5];
    int pre[index+5];
    for(int i=0;i<=index;i++)
    {
        L[i]=1;
        pre[i]=i;
    }
    int res=1;
    int lind=1;
    for(int i=1;i<index;i++)
    {
        for(int j=0;j<i;j++)
        {
           if(vec[j].w<vec[i].w and L[j]+1>L[i])
           {
               L[i]=L[j]+1;
               pre[i]=j;
           }
           if(L[i]>res)
           {
               res=L[i];
               lind=i;
           }
        }
    }
   // cout<<"Result is : ";
    cout<<res<<endl;
    vector<int>ind;
    int ii=lind;
    for(;pre[ii]!=ii;ii=pre[ii])ind.push_back(vec[ii].index);
    ind.push_back(vec[ii].index);

    int ressize=ind.size();
    for(int i=ressize-1;i>=0;i--)cout<<ind[i]<<endl;

    return 0;

}
