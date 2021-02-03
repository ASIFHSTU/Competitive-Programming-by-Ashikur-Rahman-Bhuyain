#include <bits/stdc++.h>
using namespace std;

void solve(int k)
{
    int a=k+1;
    int b;
    vector<pair<int,int>>res;
    pair<int,int>p;
    bool brk=false;
    while(true)
    {
        if((a*k)%(a-k)==0)
        {

            b=(a*k)/(a-k);
            if(b>=a)
            res.push_back(make_pair(a,b));
            else {
                brk=true;
            }
        }
        int brkr=(a*k)/(a-k);
        if(brkr<a)break;
        if(brk)break;
        a++;
    }

    int np=res.size();
    cout<<np<<endl;
    for(int i=0;i<np;i++)
    {
        printf("1/%d = 1/%d + 1/%d\n",k,res[i].second,res[i].first);
    }

}

int main()
{
    int n;
    while(cin>>n)
    {
        solve(n);
    }

    return 0;
}
