/*
Name : Ashikur Rahman Bhuyain
Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh

Problem id : UVa297
*/

#include <bits/stdc++.h>
using namespace std;

int color[32][32];

void fillColor(int x1,int y1,int x2,int y2)
{
    char ch;
    cin>>ch;
    if(ch=='p')
    {
        int nx=x1+((x2-x1)/2);
        int ny=y1+((y2-y1)/2);
        fillColor(x1,y1,nx,ny);
        fillColor(nx,ny,x2,y2);

        fillColor(nx,y1,x2,ny);
        fillColor(x1,ny,nx,y2);
    }
    else if(ch=='f')
    {
        for(int i=x1;i<x2;i++)
        {
            for(int j=y1;j<y2;j++)
                color[i][j]=1;
        }
    }
}

void solve()
{
    memset(color,0,sizeof(color));
    fillColor(0,0,32,32);
    fillColor(0,0,32,32);

    int res=0;
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<32;j++)
        {
            if(color[i][j])res++;
        }
    }

    printf("There are %d black pixels.\n",res);
}

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int i=1;i<=tc;i++)
        solve();

}
