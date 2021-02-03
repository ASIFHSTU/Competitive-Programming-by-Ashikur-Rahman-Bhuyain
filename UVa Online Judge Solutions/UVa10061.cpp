#include <bits/stdc++.h>
using namespace std;

int NODigit(int n,int b)  /// number of digit of n! after converted to base b
{
    double numberOfDigit=0.0;
    for(int i=2;i<=n;i++)
    {
        numberOfDigit+=log10(i);
    }
    numberOfDigit/=log10(b);

    return floor(numberOfDigit+1e-9)+1;
}

int trailingZero(int n,int b)
{
    int divisor[1003];
    memset(divisor,0,sizeof(divisor));
    for(int i=2;i<=n;i++)
    {
        int temp=i;

        for(int j=2;j<=temp and j<=b;j++)
        {
            while(temp%j==0)
            {
                divisor[j]++;
                temp/=j;
            }
        }
    }

    // cout<<"Divisor array : ";
    //for(int i=1;i<=n;i++);//cout<<divisor[i]<<" ";
    //cout<<endl;

    int res=0;

    while(1)
    {
        int tempb=b;

        for(int j=2;j<=tempb;j++)
        {
            while(tempb%j==0)
            {
                if(divisor[j]>0)--divisor[j];
                else goto looperBaire;

                tempb/=j;
            }
        }

        res++;

    }
    looperBaire:
        return res;

}

int main()
{
    int n,b;
    while(cin>>n>>b)
    {
        int nod=NODigit(n,b);
        int tz=trailingZero(n,b);
        cout<<tz<<" "<<nod<<endl;
    }
}
