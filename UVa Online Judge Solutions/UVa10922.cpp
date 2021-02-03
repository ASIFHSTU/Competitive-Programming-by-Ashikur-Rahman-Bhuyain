/*
Name : Ashikur Rahman Bhuyain
Date : 18-5-2020
Problem : UVa10922
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string number;
    while(cin>>number)
    {
        if(number=="0")return 0;
        string orn=number;
        int sum=0;
        int NinthDegree=1;
        while(number.size()>1)
        {
            sum=0;
            for(int i=0;i<number.size();i++)
            {
                sum+=(number[i]-'0');
            }
            number=to_string(sum);

            NinthDegree++;

           // cout<<"Step "<<NinthDegree<<" : "<<number<<endl;
        }
        if(NinthDegree!=1)NinthDegree--;
        if(number=="9")
        {
            cout<<orn<<" is a multiple of 9 and has 9-degree "<<NinthDegree<<".\n";
        }
        else {
            cout<<orn<<" is not a multiple of 9.\n";
        }
    }
}
