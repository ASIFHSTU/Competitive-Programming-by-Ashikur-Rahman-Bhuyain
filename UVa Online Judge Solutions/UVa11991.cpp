/*
Name : Ashikur Rahman Bhuyain
Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh

Problem id : UVa 11991
*/
#include <bits/stdc++.h>
using namespace std;
vector<int>help[1000001];
void makeReady()
{
    for(int i=0;i<=1000000;i++)
        help[i].clear();
}
void solve(int n,int q)
{
    makeReady();
    int v;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v);
        help[v].push_back(i);
    }

    int k,m;
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&k,&m);
        if(help[m].size()<k)
        {
            printf("0\n");
        }
        else {
            printf("%d\n",help[m][k-1]);
        }
    }

}

int main()
{
   int n,q;
   while(scanf("%d%d",&n,&q)!=EOF)
   {
       solve(n,q);
   }
   return 0;
}
