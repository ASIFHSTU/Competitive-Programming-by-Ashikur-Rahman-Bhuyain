#include <bits/stdc++.h>
using namespace std;
int total_second_dif(int h1,int m1,int s1,int h2,int m2,int s2)
{

}
int main()
{
    string st1,st2;
    int h1,h2,m1,m2,speed;
    h1=h2=m1=m2=speed=0;
    double total_traversed=0.0;
    char ch;
    while(cin>>st1)
    {
        stringstream ss;
        ss<<st1;
        if(st1.size()>8)
        {
            ss>>h2>>ch>>m2>>ch>>s2;
            total_second_dif=(h1,m1,s1,h2,m2,s2);
        }
    }
}
