#include <bits/stdc++.h>
using namespace std;
int field[501][501];
int main()
{
    int h,w,n;
    while(cin>>h>>w>>n)
    {
        if(h==0 and w==0)return 0;
        memset(field,0,sizeof(field));
        int x1,x2,y1,y2;
        for(int i=0;i<n;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            if(x1>x2)swap(x1,x2);
            if(y1>y2)swap(y1,y2);
            for(int j=x1;j<=x2;j++)
            {
                for(int k=y1;k<=y2;k++)
                {
                    field[j][k]=1;
                }
            }
        }
        int res=0;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(field[i][j]==0)res++;
            }
        }

        if(res==0)cout<<"There is no empty spots."<<endl;
        else if(res==1)cout<<"There is one empty spot.\n";
        else {
            cout<<"There are "<<res<<" empty spots.\n";
        }
    }
}
