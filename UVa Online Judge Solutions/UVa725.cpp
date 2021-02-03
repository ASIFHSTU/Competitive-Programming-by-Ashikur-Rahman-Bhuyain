#include <bits/stdc++.h>
using namespace std;
#define setBit(S, j) (S |= (1 << j))

void solve(int n)
{
    bool ok=false;
    for(int fgh=1234;fgh<=98765;fgh++)
    {
        int abcde=fgh*n;
        if(abcde>98765)continue;
        int used;
        if(fgh<10000)
        {
            used=1;
        }
        else used=0;
        int lastDigit,temp=abcde;
        while(temp)
        {
            lastDigit=temp%10;
            temp/=10;
           setBit(used,lastDigit);
        }
        temp=fgh;
        while(temp)
        {
            lastDigit=temp%10;
            temp/=10;
            setBit(used,lastDigit);
        }
        if(used==(1<<10)-1)
        {
            ok=true;
            printf("%05d / %05d = %d\n",abcde,fgh,n);
        }
    }
         if(!ok)
            printf("There are no solutions for %d.\n",n);

}

int main()
{
    int n;
    int kase=0;
    while(cin>>n)
    {
        if(n==0)return 0;
        if(kase)cout<<endl;
        kase++;
        solve(n);
    }
}
