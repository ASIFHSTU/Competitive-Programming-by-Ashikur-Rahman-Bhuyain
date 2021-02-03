#include <bits/stdc++.h>
using namespace std;

struct data
{
    int number,ct;
    data(int _n,int _c)
    {
        number=_n;
        ct=_c;
    }
    bool operator<(const data &d)const
    {
        if(ct==d.ct)return number<d.number;
        return ct<d.ct;
    }
};

vector<data>vec;
vector<int>primes;
int cnt[2000003];
int totalPrimes;

int numberOfFact(int number)
{
         int ct=0;
        int sqn=sqrt(number);
        int i=0;
        while(number>1)
        {
            if(primes[i]>sqn || i==totalPrimes-1)break;
            while(number%primes[i]==0)
            {
                ct++;
                number/=primes[i];
            }
            i++;
            //cout<<"stacked at : "<<number<<endl;
        }
        if(number>1)ct++;
        return ct;
}

void preprocess()
{
    int n=2000001;

    memset(cnt,0,sizeof(cnt));
    primes.push_back(2);
    int sqn=sqrt(n)+1;
    int sqqn=sqrt(sqn)+1;
    for(int i=3;i<=sqqn;i+=2)
    {

        if(cnt[i]==0)
        {
            for(int j=i*i;j<=sqn;j+=i*2)
            {
                cnt[j]=1;
            }
        }
    }
    for(int i=3;i<=sqn;i+=2)
        if(cnt[i]==0)primes.push_back(i);



}

void pp2()
{
     vec.push_back(data(1,0));
     vec.push_back(data(2,1));


     totalPrimes=primes.size();

    for(int i=3;i<=2000001;i++)
    {
        int ccct=numberOfFact(i);

        vec.push_back(data(i,ccct));
    }

}

int main()
{
    preprocess();
    pp2();
    sort(vec.begin(),vec.end());
    int n;
    int kase=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)return 0;
        int r=vec[n-1].number;
        printf("Case %d: %d\n",kase,r);
        kase++;
    }
}
