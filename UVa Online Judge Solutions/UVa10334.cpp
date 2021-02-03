#include <bits/stdc++.h>
using namespace std;
#define Reverse(st) reverse(st.begin(),st.end())
string fib[1005];
string strSum(string st1,string st2)
{
    int len1=st1.size();
    int len2=st2.size();
    if(len1<len2){
        swap(len1,len2);
        swap(st1,st2);
    }
    string res;
    int rem,sum,carry;
    rem=sum=carry=0;
    Reverse(st1);
    Reverse(st2);

    for(int i=0;i<len1;i++)
    {
        if(i>=len2){
            sum=(st1[i]-'0')+carry;
        }
        else {
            sum=(st1[i]-'0')+(st2[i]-'0')+carry;
        }
        carry=sum/10;
        rem=sum%10;
        res.push_back(rem+'0');
    }
    if(carry!=0)
    {
        res.push_back(carry+'0');
    }
    Reverse(res);
    return res;

}


void findFib()
{
    fib[0]="1";
    fib[1]="2";
    for(int i=2;i<=1001;i++)
    {
        fib[i]=strSum(fib[i-1],fib[i-2]);
    }
}

void solve(string st1,string st2)
{


}

int main()
{

    findFib();
    int n;
    while(cin>>n)
    {
        cout<<fib[n]<<endl;
    }
    return 0;
}

