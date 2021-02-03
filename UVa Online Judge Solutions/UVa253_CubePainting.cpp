#include <bits/stdc++.h>
using namespace std;

string rotateDown(string st)
{
    string temp;
    temp.push_back(st[4]);
    temp.push_back(st[0]);
    temp.push_back(st[2]);
    temp.push_back(st[3]);
    temp.push_back(st[5]);
    temp.push_back(st[1]);

    return temp;
}

string rotateLeft(string st)
{
    string temp;
    temp.push_back(st[0]);
    temp.push_back(st[3]);
    temp.push_back(st[1]);
    temp.push_back(st[4]);
    temp.push_back(st[2]);
    temp.push_back(st[5]);

    return temp;
}

void solve(string pos)
{
    string pos1,pos2;
    for(int i=0; i<12; i++)
    {
        if(i<6)
            pos1.push_back(pos[i]);
        else
            pos2.push_back(pos[i]);
    }
    string posextra=rotateLeft(pos1);
    for(int i=0; i<=3; i++)
    {
        pos1=rotateDown(pos1);
        posextra=rotateDown(posextra);

        for(int j=0; j<=3; j++)
        {

            pos1=rotateLeft(pos1);
            posextra=rotateLeft(posextra);


            if(pos1==pos2 || posextra==pos2)
            {
                cout<<"TRUE\n";
                return;
            }
        }
    }
    cout<<"FALSE\n";
    return;
}

int main()
{
    string pos;
    while(cin>>pos)
    {
        solve(pos);
    }
}
