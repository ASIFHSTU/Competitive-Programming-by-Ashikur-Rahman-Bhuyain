#include <bits/stdc++.h>
using namespace std;
int main()
{
    int hight[10003];
    int maxCord=0;
    memset(hight,0,sizeof(hight));
    int x,y,h;
    while(cin>>x>>h>>y)
    {
        maxCord=max(maxCord,y);
        for(int i=x;i<y;i++)
        {
            if(hight[i]<h)hight[i]=h;
        }
    }
  int preHight=0;
  bool started=false;
    for(int i=0;i<10000;i++)
    {
        if(hight[i]!=preHight)
        {
            if(started)
            cout<<" "<<i<<" "<<hight[i];
            else
            {
                cout<<i<<" "<<hight[i];
                started=true;
            }
            preHight=hight[i];
        }
    }
   cout<<endl;
    return 0;
}
