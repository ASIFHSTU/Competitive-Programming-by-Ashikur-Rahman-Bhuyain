#include <bits/stdc++.h>
using namespace std;

int n=5, coinValue[5]={1,5,10,25,50};
int memo[6][7500];
int ways(int index,int value)
{
    if(value==0)return 1;
    if(value<0 || index==n)return 0;
    if(memo[index][value]!=-1){
        return memo[index][value];
    }

    return memo[index][value]=ways(index+1,value)+ways(index,value-coinValue[index]);
}

int main()
{
    int value;
    memset(memo,-1,sizeof(memo));
    while(cin>>value)
    {

       // cout<<"result is :";
        cout<<ways(0,value)<<endl;
    }
}
