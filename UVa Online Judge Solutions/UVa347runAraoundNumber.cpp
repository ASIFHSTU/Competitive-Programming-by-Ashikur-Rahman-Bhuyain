#include <bits/stdc++.h>
using namespace std;

int res[10000006];
bool isAN(int n)
{
    string num=to_string(n);
    int len=num.size();
    bool visited[20]={false};
    bool extra[11]={false};
    for(int i=0;i<len;i++)
    {
        if(extra[num[i]-'0']) return false;
        extra[num[i]-'0']=true;
    }

    int now=0,cnt=num[0]-'0';
    for(int i=0;i<len;i++)
    {
        now=(now+cnt)%len;
        if(visited[now])return false;
        visited[now]=true;
        cnt=num[now]-'0';
    }

   // int totalVisited=0;
 //   int cup=0;
//    while(true)
//    {
//        if(visited[cup]==false)
//        {
//            visited[cup]=true;
//            totalVisited++;
//            cup=(cup+(num[cup]-'0'))%len;
//            if(totalVisited==len and cup==0)return true;
//            if(totalVisited==len)return false;
//        }
//        else {
//            if(totalVisited==len and cup==0)return true;
//
//            return false;
//        }
//    }

    return true;
}
int findRunAroundNumbers()
{
  for(int i=9999999;i>9;i--)
  {
      if(isAN(i))
        res[i]=i;
      else res[i]=res[i+1];
  }
}

int main()
{
    findRunAroundNumbers();
    int n;
    //memset(res,-1,sizeof(res));
    int tc=1;
    while(cin>>n)
    {
        if(n==0)return 0;
        printf("Case %d: %d\n",tc,res[n]);
        tc++;
    }

    return 0;
}
