#include <bits/stdc++.h>
using namespace std;

void printlis(int lis_end,int pre[],vector<int>ar)
{
    vector<int>res;
    int i=lis_end;
    for(;pre[i]>=0;i=pre[i])res.push_back(ar[i]);
    res.push_back(ar[i]);

    int len=res.size();
    for(int i=len-1;i>=0;i--)
    {
        cout<<res[i]<<endl;
    }

}
void LIS(vector<int>ar)
{
    int len=ar.size();
    int L[len+10];
    int L_ind[len+10];
    int pre[len+10];

    int lis=0,l_end=0;

    for(int i=0;i<len;i++)
    {
        int pos=lower_bound(L,L+lis,ar[i])-L;
        L[pos]=ar[i];
        L_ind[pos]=i;
        pre[i]=pos?L_ind[pos-1]:-1;
        if(pos+1>lis)
        {
            lis=pos+1;
            l_end=i;
        }
    }

    cout<<"Max hits: "<<lis<<endl;
    printlis(l_end,pre,ar);


}

void solve()
{
    string st1;
    vector<int>vec;
    while(true)
    {
        getline(cin,st1);
        if(st1.size()==0)break;

        int value=stoi(st1);
        vec.push_back(value);

    }
    LIS(vec);
}

int main()
{
    int n=1;
    cin>>n;
    cin.ignore();
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        if(i)cout<<endl;
        solve();
    }
}
