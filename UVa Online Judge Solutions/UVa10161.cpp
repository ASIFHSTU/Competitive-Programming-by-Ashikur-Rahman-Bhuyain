#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sqn=sqrt(2000000000)+1;
    int ar[sqn+1];
    int increaser=1;
    ar[1]=1;
    for(int i=2;i<=sqn;i++)
    {
        increaser+=2;
        ar[i]=ar[i-1]+increaser;
    }

    int n;
    int dif,row,column;
    while(cin>>n)
    {
        if(n==0)return 0;
        int upper=sqrt(n)+1;

        int pos=lower_bound(ar+1,ar+upper,n)-ar;

        dif=ar[pos]-n;
            if(dif<pos)
            {
                row=dif+1;
                column=pos;
            }
            else{
                row=pos;
                column=((2*pos)+n)-ar[pos]-1;
            }

        if(pos%2==0)
        {
            swap(row,column);
        }

        cout<<row<<" "<<column<<endl;

    }
}
