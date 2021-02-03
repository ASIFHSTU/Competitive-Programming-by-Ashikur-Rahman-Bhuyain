#include <bits/stdc++.h>
using namespace std;
//UVa 897

//void allPermutation(int number)
//{
//    int i=1;
//    string num=to_string(number);
//    sort(num.begin(),num.end());
//    cout<<"permutation no : 0 , number is : "<<num<<endl;
//    while(next_permutation(num.begin(),num.end()))
//    {
//        //next_permutation(num.begin(),num.end());
//        cout<<"permutation no : "<<i<<" , number is : "<<num<<endl;
//        i++;
//       if(i>20)break;
//    }
//}

int ag[] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};
int sze = 22;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)return 0;
        if(n>=991)
        {
            cout<<"0\n";
            continue;
        }

        int lb=lower_bound(ag,ag+sze,n)-ag;
       // cout<<"lower bound value : "<<ag[lb]<<endl;
        string help=to_string(n);
        int helpLen=help.size();
        int maxLimit=1;
        for(int i=0;i<helpLen;i++)
        {
            maxLimit*=10;
        }
        if(ag[lb]==n){
            lb++;
        }
        if(ag[lb]<maxLimit)
        {
            cout<<ag[lb]<<endl;
        }
        else {
            cout<<"0"<<endl;
        }

    }
}
