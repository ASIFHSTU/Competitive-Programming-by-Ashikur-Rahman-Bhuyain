/*
Name : Ashikur Rahman Bhuyain
Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh

Problem id : UVa 12086
*/

#include <bits/stdc++.h>
using namespace std;
#define MX 200005
int n;
int bit[MX];
void Update(int ind,int value)
{
    while(ind<=n)
    {
        bit[ind]+=value;
        ind+=(ind&(-ind));
    }
}
long long int query(int ind)
{
    long long int sum=0;
    while(ind>0)
    {
        sum+=bit[ind];
        ind-=(ind&(-ind));
    }
    return sum;
}

void solve()
{
    memset(bit,0,sizeof(bit));

    int ar[n+1];

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ar[i]);
        Update(i,ar[i]);
    }
    char st[10];

    int a,b;

    while(true)
    {
        scanf("%*c");
         scanf("%s",st);
   //cout<<"st is : "<<st<<endl;

      if(st[0]=='E')
        {

            return;
        }

     scanf("%d%d",&a,&b);
        if(st[0]=='S')
        {

            ar[a]=b-ar[a];
            Update(a,ar[a]);
            ar[a]=b;
        }
        else if(st[0]=='M')
        {
            printf("%lld\n",query(b)-query(a-1));
        }


    }



}

int main()
{
    int tc=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)return 0;
        if(tc!=1)printf("\n");

        printf("Case %d:\n",tc);
        tc++;
        solve();
    }
}

/*
Input :

   3
   100 100 100

   M 1 1
   M 1 3
   S 2 200
   M 1 2
   S 3 0
   M 2 3
   END

10
1 2 3 4 5 6 7 8 9 10
M 1 10
END

0
*/
