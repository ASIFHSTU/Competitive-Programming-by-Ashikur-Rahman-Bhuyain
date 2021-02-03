#include <bits/stdc++.h>
using namespace std;
#define N 33006
#define READ(f)              freopen(f,  "r" ,stdin)
#define WRITE(f)             freopen(f,  "w" ,stdout)
vector<int>primes;
bool color[N+2];

struct data{
int to,from;
data(int _from,int _to)
{
    to=_to;
    from=_from;
}
};
vector<data>answer;

void sieve()
{
    primes.push_back(2);
    for(int i=3;i*i<=N;i+=2)
    {
        if(color[i]==false)
        {
            for(int j=i*i;j<N;j+=(i+i))
             {
                color[j]=true;
            }
        }
    }

    for(int i=3;i<N;i+=2)
    {
        if(color[i]==false)primes.push_back(i);
    }
}

void solve(int a,int b)
{
    if(b<7){
        return;
    }



    int lb=lower_bound(primes.begin(),primes.end(),a)-primes.begin();
    int ub=upper_bound(primes.begin(),primes.end(),b)-primes.begin();
//    if(primes[ub]!=b)
//    {
//        ub--;
//    }

//     cout<<"lower bound value : "<<primes[lb]<<endl;
//     cout<<"upper bound value : "<<primes[ub]<<endl;

   int last=lb;
   int k=lb+1,dis;
   if(k<ub)dis=primes[k]-primes[k-1];
   while(k<ub)
   {
       while(k<ub and dis==primes[k]-primes[k-1])k++;
       if(k-last>=3)
       {
           answer.push_back(data(last,k-1));
       }
       if(k<ub)
       {
           last=k-1;
           dis=primes[k]-primes[k-1];
       }
   }
}
void printRes()
{
     int anssize=answer.size();
            bool cheker[anssize];
            memset(cheker,true,sizeof(cheker));

            for(int i=answer.size()-1;i>0;i--)
            {
                for(int j=0;j<i;j++)
                {
                    if((answer[i].from<=answer[j].from and answer[j].to<answer[i].to) || (answer[i].from<answer[j].from and answer[j].to<=answer[i].to))
                        cheker[j]=false;

                }

            }

            for(int i=0;i<anssize;i++)
            {
                if(cheker[i])
                {
                    cout<<primes[answer[i].from];
                    for(int k=answer[i].from+1;k<=answer[i].to;k++)
                    {
                        cout<<" "<<primes[k];
                    }cout<<endl;
                }
            }
}

int main()
{
   //READ("input.txt");
    //WRITE("output.txt");
    sieve();

    int a,b;
    while(true)
    {
        cin>>a>>b;
        if(a==0 and b==0)break;
        if(a>b)swap(a,b);
        solve(a,b);
    }
    printRes();
}
