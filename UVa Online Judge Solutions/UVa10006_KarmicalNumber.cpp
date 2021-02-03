/*
Name : Ashikur Rahman Bhuyain
Date : 18-5-2020
Problem Id : UVa 10006

*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
bool isPrime(int number)
{
    if(number==1)return false;
    if(number==2)return true;
    int sqn=sqrt(number)+1;
    for(int i=3;i<=sqn;i+=2)
    {
        if(number%i==0)return false;
    }
    return true;
}

LL powmod(LL base,LL pow,LL mod)
{
    base%=mod;
    LL result=1;
    while(pow>0)
    {
        if(pow&1) result=(result*base)%mod;
        base=(base*base)%mod;
        pow>>=1;
    }
    return result;
}


bool Cirmichel(int number)
{
    if(isPrime(number))
    {
        return false;
    }
    for(int i=2;i<number;i++)
    {
        int r=powmod(i,number,number);
        if(r!=i)return false;
    }
    return true;
}
int main()
{
    int number;
    while(cin>>number)
    {
        if(number==0)return 0;
        if(Cirmichel(number))
        {
           cout<<"The number "<<number<<" is a Carmichael number.\n";
        }
        else {
            cout<<number<<" is normal.\n";
        }
    }
}
