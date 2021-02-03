/*
Name : Ashikur Rahman Bhuyain
Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh

Problem id : UVa 12462
*/

#include <bits/stdc++.h>
using namespace std;
#define MX 100005
int tree[MX*4];
int ar[MX];
int colorCheck[MX][35];
int n,c;

void init()
{
    memset(tree,0,sizeof(tree));
    memset(colorCheck,0,sizeof(colorCheck));

}

void buildTree(int node,int b,int e)
{

    if(b==e){
        tree[node]=b;
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    buildTree(left,b,mid);
    buildTree(right,mid+1,e);
    if(ar[tree[left]]<ar[tree[right]])
        tree[node]=tree[left];
    else
        tree[node]=tree[right];

}

int findMin(int node,int b,int e,int i,int j)
{
    if(b>j || e<i)
        return -1;
    if(b>=i and e<=j)
        return tree[node];
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left+1;
    int res1=findMin(left,b,mid,i,j);
    int res2=findMin(right,mid+1,e,i,j);
    if(res1==-1)return res2;
    if(res2==-1)return res1;
    if(ar[res1]<ar[res2])return res1;
    return res2;

}

long long int findArea(int b,int e)
{
    if(b>e)return 0;
    for(int i=0;i<c;i++)
    {
        if(colorCheck[b-1][i]>=colorCheck[e][i])return 0;
    }

    int midIndex=findMin(1,1,n,b,e);
    //cout<<"MIN founded successfully : "<<midIndex<<endl;
    long long int res1=max(findArea(b,midIndex-1),findArea(midIndex+1,e));
    return max(res1,(long long int)ar[midIndex]*(e-b+1));


}

void solve()
{
    init();
   // cout<<"value of n at solve : "<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ar[i]);
    }
    buildTree(1,1,n);
    //cout<<"tree build successfully. "<<endl;
    int color;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&color);
        for(int j=0;j<c;j++)
        {
            colorCheck[i][j]=colorCheck[i-1][j];
        }
        colorCheck[i][color]++;

    }
    long long int Area=findArea(1,n);
  //  cout<<"result is : ";
    printf("%lld\n",Area);
}

int main()
{
    while(true)
    {
        scanf("%d%d",&n,&c);
        if(n==0 and c==0)return 0;
        solve();
    }
}

