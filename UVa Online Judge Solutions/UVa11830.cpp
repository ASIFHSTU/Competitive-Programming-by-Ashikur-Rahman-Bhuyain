#include <bits/stdc++.h>
using namespace std;
int main()
{
    char ch;
    string st;
    while(true)
    {
        cin>>ch>>st;
        if(ch=='0')return 0;

        string res;

        int len=st.size();
        bool paichi=false;
        for(int i=0;i<len;i++)
        {
            if(st[i]!=ch)
            {
                if(st[i]!='0')
                {
                    paichi=true;
                    res.push_back(st[i]);
                }
                else if(paichi){
                    res.push_back(st[i]);
                }
            }
        }

        if(res.size()==0)
        {
            cout<<"0\n";
        }
        else {
            cout<<res<<endl;
        }
    }
}
