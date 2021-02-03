#include <bits/stdc++.h>
using namespace std;
struct data
{
    int id,interval;
    int curInterval;
    data(int _id,int _curInterval,int _interval)
    {
        id=_id;
        interval=_interval;
        curInterval=_curInterval;
    }
    bool operator<(const data &p)const
    {
        if(curInterval==p.curInterval)
            return id>p.id;
        return curInterval>p.curInterval;
    }
};
int main()
{
    string st;
    int id,interval;
    priority_queue<data>pq;
    while(true)
    {
        cin>>st;
        if(st=="#")break;
        cin>>id>>interval;
       pq.push(data(id,interval,interval));
    }
    int k;
    cin>>k;
    while(k--)
    {
        data p=pq.top();
        int iid=p.id;
        int iinterval=p.interval;
        int res=p.curInterval+iinterval;
        pq.pop();
        pq.push(data(iid,res,iinterval));
        cout<<iid<<endl;
    }

    return 0;
}
