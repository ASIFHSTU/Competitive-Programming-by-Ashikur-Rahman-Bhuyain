#include <bits/stdc++.h>
using namespace std;
#define MxN 1001
int N,weight[MxN],value[MxN];
int k[1001][35];   // memset(k,-1,sizeof(k));
// maxweight 34, maxValue 1000,n=number of element
int knapSack(int id,int remainingCapacity)
{
    if(id==N || remainingCapacity==0)return 0;
    if(k[id][remainingCapacity]!=-1)return k[id][remainingCapacity];
    if(remainingCapacity<weight[id]) return k[id][remainingCapacity]=knapSack(id+1,remainingCapacity);
    return k[id][remainingCapacity]=max(knapSack(id+1,remainingCapacity),knapSack(id+1,remainingCapacity-weight[id])+value[id]);
}

void solve()
{
    memset(k,-1,sizeof(k));
   cin>>N;
   for(int i=0;i<N;i++)
   {
       cin>>value[i]>>weight[i];
   }
   int res=0;
   int g,capacity;
   cin>>g;
   for(int i=0;i<g;i++)
   {
       cin>>capacity;
       res+=knapSack(0,capacity);
   }

  // cout<<"result is : "<<endl;
   cout<<res<<endl;
}

int main()
{
   int tc;
   cin>>tc;
   while(tc--)
   {
       solve();
   }
}
