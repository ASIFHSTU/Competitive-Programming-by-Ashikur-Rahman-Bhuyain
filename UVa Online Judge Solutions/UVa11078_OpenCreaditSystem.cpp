 #include <bits/stdc++.h>
 using namespace std;

 void solve()
 {
     int n;
     int sen=0;
     int res=INT_MIN;
     int v;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         cin>>v;
         if(i==0){sen=v;
         continue;
         }
         res=max(res,(sen-v));
         sen=max(sen,v);
     }
     cout<<res<<endl;
 }

 int main()
 {
     int tc;
     cin>>tc;
     while(tc--)solve();

     return 0;
 }
