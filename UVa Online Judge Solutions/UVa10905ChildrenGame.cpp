#include <bits/stdc++.h>
using namespace std;
struct data
{
    string num;
    int len;
    bool operator<(const data &p)const
    {
        string num2=p.num;
        return num+num2>num2+num;
    }
};
void solve(int n)
{
   data allNumber[n];
   string temp;
   for(int i=0;i<n;i++)
   {
       cin>>temp;
       allNumber[i].num=temp;
       allNumber[i].len=temp.size();
   }
   sort(allNumber,allNumber+n);
   for(int i=0;i<n;i++)
   {
       cout<<allNumber[i].num;
   }cout<<endl;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)return 0;
        solve(n);
    }
}
