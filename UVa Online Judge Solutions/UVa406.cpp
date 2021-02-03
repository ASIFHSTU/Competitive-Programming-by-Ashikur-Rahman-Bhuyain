#include <bits/stdc++.h>
using namespace std;
vector<int>primes;
bool check[1005];
void findPrimes()
{
    memset(check,false,sizeof(check));
    primes.push_back(1);
    primes.push_back(2);
    for(int i=3;i<100;i+=2)
    {
        if(check[i]==false)
        {
             for(int j=i*i;j<=1000;j+=(i+i))
             {
                 check[j]=true;
             }
        }
    }
    for(int i=3;i<=1000;i+=2)
        {
            if(check[i]==false)
            {
                primes.push_back(i);
            }
        }

}

int LowerBound(int n)
{
    int sze=primes.size();
    int l=0,r;
    r=sze-1;
    int mid;
    int ind=l;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(primes[mid]==n)
        {
            return mid;
        }
        else if(primes[mid]<n){
            ind=mid;
            l=mid+1;

        }
        else {
            r=mid-1;
        }
    }
    return ind;
}

void solve(int n,int c)
{
    int lb=LowerBound(n);

   // cout<<"lower bound index : "<<lb<<endl;
    //cout<<"Lower bound value is : "<<primes[lb]<<endl;

    int numberOfPrimes=lb+1;

    if(numberOfPrimes<=c*2)
    {
        for(int i=0;i<numberOfPrimes;i++)
        {
            cout<<" "<<primes[i];
        }
        cout<<endl;
        return;
    }
    int mid=numberOfPrimes/2;
    int printable=c;
    if(numberOfPrimes&1)
    {

       printable--;

    }

     for(int i=mid-printable;i<=mid;i++)
        {
            cout<<" "<<primes[i];
        }
        for(int i=mid+1;i<mid+c;i++)
        {
            cout<<" "<<primes[i];
        }
    cout<<endl;
    return;
}


int main()
{
    findPrimes();
   // printPrimes();

    int n,c;
    while(cin>>n>>c)
    {
        cout<<n<<" "<<c<<":";
        solve(n,c);
        cout<<endl;
    }
    return 0;
}

