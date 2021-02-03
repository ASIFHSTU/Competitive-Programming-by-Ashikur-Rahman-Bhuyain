/*
Name : Ashikur Rahman Bhuyain
Institution : Hajee Mohammad Danesh Science and Technology University,Dinajpur,Bangladesh

Problem id : UVa101
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 25
int blockRecord[MX];
int block_position[MX][MX];

void moveLoad(int a,int posOfA)
{
    int i,j,k;
    for(i=0;i<MX;i++)
    {
        if(block_position[posOfA][i]==a)break;
    }

    for(j=i+1;j<MX;j++)
    {
        if(block_position[posOfA][j]==-1)break;
        int nextPart=block_position[posOfA][j];
        for(k=0;k<MX;k++)
        {
            if(block_position[nextPart][k]==-1)
            {
                block_position[nextPart][k]=nextPart;
                blockRecord[nextPart]=nextPart;
                break;
            }
        }
        block_position[posOfA][j]=-1;
    }

}

void Move(int a,int destination)
{
    int i,j,k;
    int posOfA=blockRecord[a];
    for(i=0;i<MX;i++)
    {
        if(block_position[posOfA][i]==a)break;

    }

    for( j=i;j<MX;j++)
    {
        if(block_position[posOfA][j]==-1)break;
        for(k=0;k<MX;k++)
        {
            if(block_position[destination][k]==-1)
            {
                block_position[destination][k]=block_position[posOfA][j];
                blockRecord[block_position[posOfA][j]]=destination;
                break;
            }
        }
        block_position[posOfA][j]=-1;
    }

}

void moveOnto(int a,int b)
{
    int posA=blockRecord[a];
    int posB=blockRecord[b];
    moveLoad(a,posA);
    moveLoad(b,posB);
    Move(a,posB);
}

void moveOver(int a,int b)
{
    int posA=blockRecord[a];
    int posB=blockRecord[b];
    moveLoad(a,posA);
    Move(a,posB);
}

void pileOnto(int a,int b)
{
    int posA=blockRecord[a];
    int posB=blockRecord[b];
    moveLoad(b,posB);
    Move(a,posB);
}

void pileOver(int a,int b)
{
    int posA=blockRecord[a];
    int posB=blockRecord[b];
    Move(a,posB);
}

int main()
{
    int n;
    cin>>n;

   memset(block_position,-1,sizeof(block_position));

    for(int i=0;i<n;i++)
    {
        blockRecord[i]=i;
        block_position[i][0]=i;
    }

    while(true)
    {
        string st1,st2;
        int a,b;
        cin>>st1;
        if(st1=="quit")break;
        cin>>a>>st2>>b;
        if(a==b or blockRecord[a]==blockRecord[b])continue;
        if(st1=="move" and st2=="onto")
        {
           moveOnto(a,b);

        }
        else if(st1=="move" and st2=="over")
        {
            moveOver(a,b);

        }
        else if(st1=="pile" and st2=="onto")
        {
            pileOnto(a,b);
        }
        else if(st1=="pile" and st2=="over")
        {
            pileOver(a,b);
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d:",i);
        for(int j=0;j<MX;j++)
        {
            if(block_position[i][j]==-1){
                cout<<endl;
                break;
            }
            cout<<" "<<block_position[i][j];
        }
    }
    return 0;
}
