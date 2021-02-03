/*
Name : Ashikur Rahman Bhuyain
Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh

Problem id : UVa 10909 (Lucky Number)
*/

#include <bits/stdc++.h>
using namespace std;
#define MX 2000500
int tree[MX*4+2];
int ar[MX+2];
void init(int node,int b,int e)
{
    if(b==e){
        tree[node]=ar[b]=(b&1);
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left|1;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

int findKthValue(int node,int b,int e,int k)
{
    if(tree[node]<k)return -1;
    if(b==e)return b;

    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left|1;

    if(k<=tree[left])return findKthValue(left,b,mid,k);
    else return findKthValue(right,mid+1,e,k-tree[left]);

}

void Update(int node,int b,int e,int k)
{
    if(b==e)
    {
        tree[node]=ar[b]=0;
        return;
    }
    int mid=(b+e)>>1;
    int left=node<<1;
    int right=left|1;

    if(k<=tree[left])Update(left,b,mid,k);
    else Update(right,mid+1,e,k-tree[left]);

    tree[node]=tree[left]+tree[right];
}


void preProcess()
{
    init(1,1,MX);

    int p=2;
    while(p<=tree[1])
    {
        int k=findKthValue(1,1,MX,p);
        int needOff=tree[1]/k;
        needOff*=k;
        while(needOff>=k)
        {
            Update(1,1,MX,needOff);
            needOff-=k;
        }
        p++;
    }


}


int main()
{
    preProcess();

    int n;
    ar[0]=0;
    while(cin>>n)
    {
        int a=0;
        if(n>=1 and (n&1)==0)
        {

            for(a=n/2;a>0 and !ar[a];a--);

            for(;a>0;a-=2)if(ar[a] and ar[n-a])break;

        }

        if(a<=0){
            printf("%d is not the sum of two luckies!\n",n);
        }
        else {
            printf("%d is the sum of %d and %d.\n",n,a,n-a);
        }

    }
    return 0;
}

