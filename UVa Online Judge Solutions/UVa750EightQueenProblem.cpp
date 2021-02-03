#include <bits/stdc++.h>
using namespace std;
int a,b,row[8],ct;

bool rakhaJabeKi(int r,int c)
{
    for(int prev=0;prev<c;prev++)
    {
        if(row[prev]==r || abs(row[prev]-r)==abs(prev-c))return false;
    }
    return true;
}

void backTrack(int c)
{
    if(c==8 and row[b]==a)
    {
        ct++;
        printf("%2d      %d",ct, row[0] + 1);
        for (int j = 1; j < 8; j++)
            printf(" %d", row[j] + 1);
        printf("\n");
    }
    for(int r=0;r<8;r++)
    {
        if(rakhaJabeKi(r,c))
        {
            row[c]=r;
            backTrack(c+1);
        }
    }
}

int main()
{
    int tc;
    cin>>tc;
    for(int kase=0;kase<tc;kase++)
    {
        if(kase)cout<<endl;

        cin>>a>>b;
        a--;b--;
        memset(row,0,sizeof(row));ct=0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        backTrack(0);
    }
}
