#include <bits/stdc++.h>
using namespace std;
struct data
{
    string name;
    int l,r;

};
void solve()
{
    int d;
    cin>>d;
    data info[d+1];
    string name;
    int l,h;
    for(int i=0;i<d;i++)
    {
        cin>>info[i].name>>info[i].l>>info[i].r;
    }


    int rind,ct=0;
    int questions,q;
    cin>>questions;
    for(int i=0;i<questions;i++)
    {
        ct=0;
        cin>>q;
        for(int j=0;j<d;j++)
        {
            if(info[j].l<=q and info[j].r>=q)
            {
                rind=j;
                ct++;
            }
        }
        if(ct!=1)
        {
            cout<<"UNDETERMINED\n";
        }
        else {
            cout<<info[rind].name<<endl;
        }
    }

}
int main()
{
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        if(i)cout<<endl;
        solve();
    }
}
