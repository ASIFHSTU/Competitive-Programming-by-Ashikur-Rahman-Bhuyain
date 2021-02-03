#include <bits/stdc++.h>
using namespace std;

int catalan[12];
void makeCatalan()
{
    catalan[0]=catalan[1]=1;
    for(int i=2;i<=10;i++)
    {
        catalan[i]=0;
        for(int j=0;j<i;j++)
        {
            catalan[i]+=(catalan[j]*catalan[i-j-1]);
        }
    }
}
int main()
{
    makeCatalan();
    int n;
    bool started=false;
    while(cin>>n){
            if(started)cout<<endl;
        cout<<catalan[n]<<endl;
        started=true;
    }
    return 0;
}
