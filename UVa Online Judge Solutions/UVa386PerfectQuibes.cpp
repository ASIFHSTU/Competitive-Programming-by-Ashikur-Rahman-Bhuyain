#include <bits/stdc++.h>
using namespace std;

struct data
{
    int a,b,c,d;
    data(int _a,int _b,int _c,int _d)
    {
        a=_a;
        b=_b;
        c=_c;
        d=_d;
    }
    bool operator <(const data &p)const
    {
        if(a==p.a){
                if(b==p.b)
                {
                    if(c==p.c)
                        return d<p.d;
                    return c<p.c;
                }
            return b<p.b;
        }


        return a<p.a;
    }
};
int chkr[8000008];
int main()
{

    vector<data>res;
    int total,v;
    for(int i=2;i<=200;i++)
    {
        v=i*i*i;
        chkr[v]=i;
    }
    //cout<<"calculation starting : "<<endl;
    for(int i=2;i<=200;i++)
    {
        for(int j=i;j<=200;j++)
        {
            for(int k=j;k<=200;k++)
            {
                total=i*i*i+j*j*j+k*k*k;
        if(total>8000000)break;
                 if(chkr[total])res.push_back(data(chkr[total],i,j,k));
            }
        }
    }
   // cout<<"Calculation done.\n";

    sort(res.begin(),res.end());
    int len=res.size();
    for(int i=0;i<len;i++)
    {
        printf("Cube = %d, Triple = (%d,%d,%d)\n",res[i].a,res[i].b,res[i].c,res[i].d);
    }

    return 0;
}
