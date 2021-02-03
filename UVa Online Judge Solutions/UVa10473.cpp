#include<bits/stdc++.h>
using namespace std;


int main()
{
    char st[20];
    int num;
    while(true)
    {
        scanf("%s",st);
        if(st[0]=='-')return 0;
        if(strlen(st)>2 and st[1]=='x')
        {
            sscanf(st,"%x",&num);
            cout<<num<<endl;
        }
        else{
            sscanf(st,"%d",&num);
            printf("0x%X\n",num);
        }
    }
}
