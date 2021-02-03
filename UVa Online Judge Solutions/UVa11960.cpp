/*
Name : Ashikur Rahman Bhuyain
Date : 17-5-2020
Problem Id : UVa 11960
*/
#include <bits/stdc++.h>
using namespace std;
#define mx 1000006
int divisor[mx+10];
int res[mx+10];
void NumberOfDivisorRange()
{
    for(int i=1;i<=mx;i++)divisor[i]=2;
    divisor[1]=1;

    for(int i=2;i<=mx;i++)
    {
        for(int j=i*2;j<=mx;j+=i)
        {
            divisor[j]++;
        }
    }

    res[1]=1;
    for(int i=2;i<=mx;i++)
    {
        if(divisor[i]>=divisor[res[i-1]])
        {
            res[i]=i;
        }
        else {
            res[i]=res[i-1];
        }
    }

}

int main()
{
    NumberOfDivisorRange();
    int tc;
    int x;
    cin>>tc;
    while(tc--)
    {
        cin>>x;
        cout<<res[x]<<endl;
    }
    return 0;
}
