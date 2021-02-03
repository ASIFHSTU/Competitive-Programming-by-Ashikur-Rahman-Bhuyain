#include <bits/stdc++.h>
using namespace std;
#define int long long int
int ext_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int g=ext_gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}

bool LDE(int a,int b,int c,int &x,int &y,int &g)
{
    g=ext_gcd(abs(a),abs(b),x,y);
    if(c%g)return false;
    x*=c/g;
    y*=c/g;
    if(a<0)x=-x;
    if(b<0)y=-y;
    return true;
}

void shift_solution(int &x,int &y,int a,int b,int cnt)
{
    x+=(cnt*b);
    y-=(cnt*a);
}

void solve(int a,int b,int c,int ca,int cb)
{
    int x,y,g;
    bool priority=false;
    double unita=(double)ca/a;
    double unitb=(double)cb/b;
    if(unita<unitb)
    {
        swap(a,b);
        priority=true;
       // cout<<"type changing\n";
    }
    if(!LDE(a,b,c,x,y,g)){
        cout<<"failed\n";
        return;
    }

    a/=g;
    b/=g;
    int sign_a=(a>0)?1:-1;
    int sign_b=(b>0)?1:-1;
    shift_solution(x,y,a,b,-x/b);
    if(x<0)shift_solution(x,y,a,b,sign_b);

    if(y<0)
    {
       shift_solution(x,y,a,b,y/a);
       if(y<0)shift_solution(x,y,a,b,-sign_a);

       if(x<0){
        cout<<"failed\n";
        return;
       }
    }

    if(priority)cout<<y<<" "<<x<<endl;
    else
    cout<<x<<" "<<y<<endl;


}

int32_t main()
{
    int c;
    while(cin>>c)
    {
        if(c==0)return 0;
        int a,ca,b,cb;
        cin>>ca>>a>>cb>>b;
        solve(a,b,c,ca,cb);
    }

    return 0;
}
