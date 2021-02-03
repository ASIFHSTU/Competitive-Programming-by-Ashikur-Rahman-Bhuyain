 /*
Name : Ashikur Rahman Bhuyain
Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh

Problem id : UVa13178
*/

#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    scanf("%d",&n);
    int mod=n%3;
    if(mod==0 || mod==2)
    {
        printf("YES\n");

    }
    else {
        printf("NO\n");
    }
}
int main()
{
    int tc;
    scanf("%d",&tc);
    for(int i=0;i<tc;i++)solve();
    return 0;
}

