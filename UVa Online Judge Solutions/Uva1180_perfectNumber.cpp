#include <bits/stdc++.h>
using namespace std;

#define limit 1000001
int prime_chek[limit+1],primes[5000000],total_primes;
void sieve_and_store_primes()
{
    int sqn=sqrt(limit)+1;
    prime_chek[0]=prime_chek[1]=1;
    primes[total_primes]=2;
    total_primes++;
    for(int i=3;i<=sqn;i+=2)
    {
        if(prime_chek[i]==0)
        {
            primes[total_primes]=i;
            total_primes++;
            for(int j=i*i;j<=limit;j+=i+i)
            {
                prime_chek[j]=1;
            }
        }
    }
    if(sqn%2==0)
    {
        sqn++;
    }
    for(int i=sqn;i<limit;i+=2)
    {
        if(prime_chek[i]==0)
        {
            primes[total_primes]=i;
            total_primes++;
        }
    }
}


long long int sod(int n)
{
    long long int ans=1;
    int power;
    int sq=sqrt(n)+1;
    for(int i=0;primes[i]<=sq;i++)
    {
        power=0;
        while(n%primes[i]==0)
        {
            power++;
            n/=primes[i];
        }
        ans*=(int)((((double)pow((double)primes[i],power+1)-1)/(primes[i]-1))+0.5);
    }
    if(n>1)
    {
        ans*=(int)((((double)pow((double)n,2.0)-1)/(n-1))+0.5);
    }
    return ans;
}



int checking[20];

long long int twopow[20];

void makeTwopow()
{
    twopow[0]=1;
    for(int i=1;i<20;i++)
    {
        twopow[i]=twopow[i-1]*2;
    }
}

bool isPerfectNumber(int p)
{
    if(p>17)return false;
    else if(p==17)return true;
    if(checking[p]!=-1)return checking[p];
    long long int num=twopow[p-1]*(twopow[p]-1);


    if(sod(num)-num==num){
        return checking[p]=1;
    }
    else {
        return checking[p]=0;
    }


}

int main()
{
    makeTwopow();
    sieve_and_store_primes();
    memset(checking,-1,sizeof(checking));
    int tc;
    cin>>tc;
    while(tc--)
    {
        int p;
        char ch;
        cin>>p;
        if(tc)
        cin>>ch;
        if(isPerfectNumber(p))
            cout<<"Yes"<<endl;
        else cout<<"No\n";
    }
    return 0;
}
