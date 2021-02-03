#include <bits/stdc++.h>
using namespace std;
int main()
{
    int lim=2147483647;
    string a,b;
    char ch;
    int ai,bi;
    bool ab,bb;
    while(cin>>a>>ch>>b)
    {
        ab=bb=false;
        cout<<a<<" "<<ch<<" "<<b<<endl;
        if(a.size()>10)
        {
            cout<<"first number too big\n";
            ab=true;
        }
        else {
            ai=stoi(a);
            if(ai>lim)
            {
                cout<<"first number too big\n";
                ab=true;
            }

        }

        if(b.size()>10)
        {
            cout<<"second number too big\n";
            bb=true;
        }
        else {
            bi=stoi(b);
            if(bi>lim)
            {
                cout<<"second number too big\n";
                bb=true;
            }

        }

        if(ab || bb)
        {
            cout<<"result too big\n";
        }
        else {
                int rrr;
            if(ch=='+')
            {
                rrr=ai+bi;
            }
            else{
                rrr=ai*bi;
            }

            if(rrr>lim)
            {
                cout<<"result too big\n";
            }
        }
    }

}
