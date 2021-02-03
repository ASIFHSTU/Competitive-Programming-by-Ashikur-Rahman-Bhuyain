/*
Name : Ashikur Rahman Bhuyain
Date : 18-5-2020
Problem Id : UVa 10006

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int L,R;
        cin>>L>>R;
        int res=0;
        int divres=0;
        for(int i=L;i<=R;i++)
        {
            int totalDivisor=0;
            for(int j=1;j*j<=i;j++)
            {
                if(j*j==i)totalDivisor++;
                else if(i%j==0)totalDivisor+=2;
            }

            if(totalDivisor>divres)
            {
                divres=totalDivisor;
                res=i;
            }

        }
          printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,R,res,divres);
    }
}
