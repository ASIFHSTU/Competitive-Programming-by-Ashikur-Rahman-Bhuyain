
//UVa 11565
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int A,B,C;
    cin>>A>>B>>C;

   int mx=max(A,B);
    mx=max(mx,C);
    for(int i=-100;i<=100;i++)
    {
        for(int j=-100;j<=100;j++)
        {
            for(int k=-100;k<=100;k++)
            {
                if( i!=j and j!=k and i!=k and i+j+k==A and i*j*k==B and i*i+j*j+k*k==C)
                {
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    return;
                }


            }
        }
    }
    cout<<"No solution.\n";
    return;

}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
        solve();

    return 0;
}
