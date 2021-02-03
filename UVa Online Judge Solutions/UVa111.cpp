#include <bits/stdc++.h>
using namespace std;
int main()
{
    string st;
    int n;
    int key[21];
    map<int,int>mp;
    while(getline(cin,st))
    {
        stringstream in;
        in<<st;
        vector<int>ar;
        int value;
        while(in>>value)
        {
            ar.push_back(value);

        }
        int len=ar.size();

       // cout<<"size of ar : "<<len<<endl;
        if(len==1)
        {

            n=ar[0];
            mp.clear();

            for(int i=1;i<=n;i++)
            {
                cin>>value;
                key[value]=i;
            }

            for(int i=1;i<=n;i++)
            {
                mp[key[i]]=i;
            }

            cin.ignore();
           // cout<<"continue called. "<<endl;
            continue;
        }

  /*      cout<<"The key array is : "<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<key[i]<<" ";
        }
        cout<<"_____________________________________\n\n";
*/


        int nar[21];
        for(int i=0;i<len;i++)
        {
            nar[ar[i]-1]=i+1;
        }




        for(int i=0;i<len;i++)
        {
            ar[i]=mp[nar[i]];
        }


        int LIS[len+1];
        for(int i=0;i<=len;i++)
        {
            LIS[i]=1;
        }
        int res=1;
        int pre[len+1];
        for(int i=0;i<=len;i++)
        {
            pre[i]=i;
        }
        for(int i=1;i<len;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(ar[j]<ar[i])
                {
                    if(LIS[i]<LIS[j]+1)
                        LIS[i]=max(LIS[i],LIS[j]+1);

                }
                 res=max(res,LIS[i]);
            }
        }
      //  cout<<"result is : ";
        cout<<res<<endl;

    }
}

/**
   Input :
   10
    3 1 2 4 9 5 10 6 8 7
    1 2 3 4 5 6 7 8 9 10
    4 7 2 3 10 6 9 1 5 8
    3 1 2 4 9 5 10 6 8 7
    2 10 1 3 8 4 9 5 7 6


*/
