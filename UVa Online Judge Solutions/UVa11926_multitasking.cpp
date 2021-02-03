#include <bits/stdc++.h>
using namespace std;
#define SZ 1000005

bitset<SZ>chk;

bool isConflict(int oneTime,int repeating)
{
    chk.reset();
    int startTime,endTime;
    int b,e,interval;
    bool conflict=false;

    for(int numb=0; numb<oneTime; numb++)
    {
        cin>>startTime>>endTime;

        if(conflict)continue;
        for(int i=startTime; i<endTime; i++)
        {
            if(chk[i])
            {
                conflict=true;
                break;
            }
            chk.set(i);
        }
    }
    for(int numb=0; numb<repeating; numb++)
    {
        cin>>b>>e>>interval;

        if(conflict)continue;
        while(true)
        {
            for(int i=b; i<e; i++)
            {
                if(chk[i])
                {
                    conflict=true;
                    break;
                }

                chk.set(i);
            }
            if(conflict)break;
            b+=interval;
            e+=interval;
            if(b>1000000)
                break;
            if(e>1000000)
                e=1000000;

        }
    }
    return conflict;
}

int main()
{
    int oneTime,regular;
    while(cin>>oneTime>>regular)
    {
        if(oneTime==0 and regular==0)
            return 0;
        if(isConflict(oneTime,regular))
        {
            cout<<"CONFLICT\n";
        }
        else
        {
            cout<<"NO CONFLICT\n";
        }
    }
}
