#include <bits/stdc++.h>
using namespace std;

struct data
{
    string teamName;
    int totalPoint;
    int played,win,loss,draw;
    int totalGoal,totalAgainst;
    data()
    {
        totalPoint=0;
        played=0;
        win=0;
        loss=0;
        draw=0;
        totalGoal=0;
        totalAgainst=0;
    }
    bool operator <(const data &p) const
    {
        if(totalPoint==p.totalPoint)
        {
            if(win==p.win)
            {
                if((totalGoal-totalAgainst)==(p.totalGoal-p.totalAgainst))
                {
                    if(totalGoal==p.totalGoal)
                    {
                        if(played==p.played)
                        {   string tn1=teamName;
                        string tn2=p.teamName;
                        transform(tn1.begin(),tn1.end(),tn1.begin(),::tolower);
                        transform(tn2.begin(),tn2.end(),tn2.begin(),::tolower);

                            return tn1<tn2;
                        }
                        return played<p.played;
                    }
                    return totalGoal>p.totalGoal;
                }
                return (totalGoal-totalAgainst)>(p.totalGoal-p.totalAgainst);
            }
            return win>p.win;
        }
        return totalPoint>p.totalPoint;
    }
};

void solve()
{
    map<string,int>mp;
    string start;
    getline(cin,start);

    int totalTeam,events;
    cin>>totalTeam;
    cin.ignore();

    data team[totalTeam];
    string teamName;
    for(int i=0;i<totalTeam;i++)
    {
        getline(cin,teamName);
        team[i].teamName=teamName;
        mp[teamName]=i;
    }

    cin>>events;
    cin.ignore();

    string eventName;
    for(int i=0;i<events;i++)
    {
        getline(cin,eventName);
        int len=eventName.size();
        string t1,t2;
        int score1=0,score2=0;
        int j;
        for(j=0;j<len and eventName[j]!='#';j++)
        {
            t1.push_back(eventName[j]);
        }
        for(j=j+1;j<len and eventName[j]!='@';j++)
        {
            score1=score1*10+(eventName[j]-'0');
        }
        for(j=j+1;j<len and eventName[j]!='#';j++)
        {
            score2=score2*10+(eventName[j]-'0');
        }
        for(j=j+1;j<len;j++)
        {
            t2.push_back(eventName[j]);
        }

        int teamInd1=mp[t1];
        int teamInd2=mp[t2];

        team[teamInd1].played++;
        team[teamInd1].totalGoal+=score1;
        team[teamInd1].totalAgainst+=score2;

        team[teamInd2].played++;
        team[teamInd2].totalGoal+=score2;
        team[teamInd2].totalAgainst+=score1;


        if(score1>score2)
        {
            team[teamInd1].totalPoint+=3;
            team[teamInd1].win++;
            team[teamInd2].loss++;
        }
        else if(score1<score2)
        {
            team[teamInd2].totalPoint+=3;
            team[teamInd2].win++;
            team[teamInd1].loss++;
        }
        else {
            team[teamInd1].totalPoint++;
            team[teamInd2].totalPoint++;
            team[teamInd1].draw++;
            team[teamInd2].draw++;
        }
    }

    sort(team,team+totalTeam);

    cout<<start<<endl;
   for(int i=0;i<totalTeam;i++)
   {
       cout<<i+1<<") "<<team[i].teamName<<" "<<team[i].totalPoint<<"p, "<<team[i].played<<"g ("<<team[i].win<<"-"<<team[i].draw<<"-"<<team[i].loss<<"), "<<team[i].totalGoal-team[i].totalAgainst<<"gd ("<<team[i].totalGoal<<"-"<<team[i].totalAgainst<<")\n";
   }

}
int main()
{
    int tc;
    cin>>tc;
    cin.ignore();
    for(int i=0;i<tc;i++)
    {
        if(i)cout<<endl;
        solve();
    }
    return 0;
}


/*
Input :
2
World Cup 1998 - Group A
4
Brazil
Norway
Morocco
Scotland
6
Brazil#2@1#Scotland
Norway#2@2#Morocco
Scotland#1@1#Norway
Brazil#3@0#Morocco
Morocco#3@0#Scotland
Brazil#1@2#Norway
Some strange tournament
5
Team A
Team B
Team C
Team D
Team E
5
Team A#1@1#Team B
Team A#2@2#Team C
Team A#0@0#Team D
Team E#2@1#Team C
Team E#1@2#Team D

*/
