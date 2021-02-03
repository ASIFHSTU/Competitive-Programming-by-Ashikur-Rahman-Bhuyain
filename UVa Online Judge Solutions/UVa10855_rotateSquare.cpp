#include <bits/stdc++.h>
using namespace std;

string bigString[501];
string smallString[501];
int Find(int N,int n)
{
    int res=0;
    bool brk=false;
    for(int i=0;i<N-n+1;i++)
        {
            for(int j=0;j<N-n+1;j++)
            {
                bool brk=false;
                for(int k=0;k<n;k++)
                {
                    for(int l=0;l<n;l++)
                    {
                        if(bigString[i+k][j+l]!=smallString[k][l]){brk=true;
                        break;}

                    if(k==n-1 and l==n-1)res++;
                    }
                    if(brk)break;
                }
            }
        }
        return res;
}

void Rotate(int n)
{
    string temp[n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[i].push_back(smallString[n-j-1][i]);
        }
    }

    for(int i=0;i<n;i++)
    {
        smallString[i]=temp[i];
    }
}

int main()
{
    int N,n;
    while(cin>>N>>n)
    {
        if(N==0)return 0;

        for(int i=0;i<N;i++)
        {
            cin>>bigString[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>smallString[i];
        }

        for(int i=0;i<4;i++)
        {
            if(i)cout<<" ";
            cout<<Find(N,n);
            Rotate(n);
        }cout<<endl;
    }
}
