#include <bits/stdc++.h>
using namespace std;
struct data
{
    char x,y;
    data(){}
    data(char _x,char _y)
    {
        x=_x;
        y=_y;
    }
};

bool isMovable(data a,data b)
{
    if(a.x==b.x || a.y==b.y)return true;

    return false;
}
vector<stack<data>>cards;
void solve(char ch1)
{
    cards.clear();
    char ch2;
    cin>>ch2;
    stack<data>st;
    st.push(data(ch1,ch2));
    cards.push_back(st);
    for(int i=0;i<51;i++)
        {
            cin>>ch1>>ch2;
            stack<data>stk;
    stk.push(data(ch1,ch2));
    cards.push_back(stk);
        }
        while(true)
        {
            int pos;
            for(pos=1;pos<cards.size();pos++)
            {
                if(pos>2 and isMovable(cards[pos].top(),cards[pos-3].top())){
                    cards[pos-3].push(cards[pos].top());
                    cards[pos].pop();
                    break;
                }
                if(pos>0 and isMovable(cards[pos].top(),cards[pos-1].top()))
                {
                    cards[pos-1].push(cards[pos].top());
                    cards[pos].pop();
                    break;
                }
            }

            if(pos==cards.size())break;
            if(cards[pos].empty()){
                cards.erase(cards.begin()+pos);
            }
        }

        if(cards.size()==1)
        {
            cout<<"1 pile remaining:";
        }
        else {
            cout<<cards.size()<<" piles remaining:";
        }
        for(int i=0;i<cards.size();i++)
        {
            cout<<" "<<cards[i].size();
        }cout<<endl;

}

int main()
{
    char ch;
    while(cin>>ch)
    {
        if(ch=='#')return 0;
        solve(ch);
    }

}
