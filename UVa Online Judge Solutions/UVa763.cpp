#include <bits/stdc++.h>
using namespace std;
#define Reverse(st) reverse(st.begin(),st.end())
string fib[105];
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
string cutLeadingZero(string st)
{
    int len=st.size();
    int z=0;
    for(int i=0;i<len;i++)
    {
        if(st[i]!='0')break;
        z++;
    }
    string res=st.substr(z);
   // cout<<res<<endl;
    return res;
}
string strSubtract(string st1,string st2)
{
    string res;
    st1=cutLeadingZero(st1);
    st2=cutLeadingZero(st2);
    int len1=st1.size();
    int len2=st2.size();

    if(len2>len1)return st1;

    if(len2==len1)
    {
        for(int i=0;i<len1;i++)
        {
            if(st1[i]<st2[i])return st1;
            if(st1[i]>st2[i])break;
        }
    }
    Reverse(st1);
    Reverse(st2);

    int carry=0;
    int dig1,dig2,sr;
    for(int i=0;i<len1;i++)
    {
       dig2=0;
       dig1=st1[i]-'0';
       if(i<len2)dig2=st2[i]-'0';
       dig2+=carry;
       carry=0;

       if(dig1<dig2)
       {
           dig1+=10;
           carry=1;
       }

       sr=dig1-dig2;
       res.push_back(sr+'0');

    }

    Reverse(res);
    res=cutLeadingZero(res);
    return res;

}

void findFib()
{
    fib[0]="1";
    fib[1]="2";
    for(int i=2;i<=101;i++)
    {
        fib[i]=strSum(fib[i-1],fib[i-2]);
    }
}
void printFib()
{
    for(int i=0;i<20;i++)
    {
        cout<<"fib["<<i+1<<"] = " <<fib[i]<<endl;
    }
}
string findNum(string st)
{
    int len=st.size();
    Reverse(st);
    string res="";
    for(int i=0;i<len;i++)
    {
        if(st[i]=='1'){
            res=strSum(res,fib[i]);
        }
    }
    return res;
}

void FibBase(string num)
{
    string r=num;
    bool ok=false;
    for(int i=101;i>=0;i--)
    {
        r=strSubtract(num,fib[i]);
        if(r==num and ok){
            cout<<"0";
        }
        else if(r!=num){
            cout<<"1";
            ok=true;
            num=r;
        }
    }
}
void solve(string st1,string st2)
{
    if(st1=="0" and st2=="0"){
        cout<<"0\n";
        return;
    }
    string num1=findNum(st1);
    string num2=findNum(st2);
    string sum=strSum(num1,num2);

    FibBase(sum);
    cout<<endl;

}

int main()
{

    findFib();
    //printFib();

   bool started=false;
   string st1,st2;
    while(cin>>st1>>st2)
    {
        if(started)cout<<endl;
        started=true;
        //cout<<"after cutting leading zero of num1 : "<<cutLeadingZero(st1)<<endl;
       // cout<<"substraction is : "<<strSubtract(st1,st2)<<endl;
        solve(st1,st2);
    }
    return 0;
}
