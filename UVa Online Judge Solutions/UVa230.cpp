/*
Name : Ashikur Rahman Bhuyain
Date : 22-5-2020
Problem Id : UVa230

*/


#include <bits/stdc++.h>
using namespace std;
struct book
{
    string title,author;
    bool operator < (const book &other)const
    {
        if(author!=other.author)
            return author<other.author;
        return title<other.title;
    }
};

vector<book>allBooks;
void readAllBooks()
{

    string temp;
    book currentBook;
    while(cin>>temp,temp!="END")
    {
        currentBook.title="";
        bool first=true;

        while(*(temp.end()-1)!='"')
        {
            if(!first)
               currentBook.title+=" ";

               first=false;
               currentBook.title+=temp;
               cin>>temp;
        }
        if(!first)currentBook.title+=" ";
        currentBook.title+=temp;

        cin>>temp;
        cin.ignore();
        getline(cin,currentBook.author);
        allBooks.push_back(currentBook);

    }
}

void printAllBooks()
{
    int len=allBooks.size();
    for(int i=0;i<len;i++)
    {
        cout<<allBooks[i].title<<" by "<<allBooks[i].author<<endl;
    }
}

int main()
{
    readAllBooks();
    sort(allBooks.begin(),allBooks.end());
    //printAllBooks();
    int totalBooks=allBooks.size();
    map<string,int>position;
    for(int i=0;i<totalBooks;i++)
    {
        position[allBooks[i].title]=i;
    }

    vector<bool>borrowed(totalBooks,false);
    vector<bool>returned(totalBooks,false);

    string command,bookname;
    while(cin>>command,command!="END")
    {
        if(command=="BORROW")
        {
            cin.ignore();
            getline(cin,bookname);
            int pos=position[bookname];
            borrowed[pos]=true;
            returned[pos]=false;
        }
        else if(command=="RETURN")
        {
            cin.ignore();
            getline(cin,bookname);
            returned[position[bookname]]=true;
        }
        else {
            int previous=-1;
            for(int i=0;i<totalBooks;i++)
            {
                if(!borrowed[i])
                    previous=i;
                else if(returned[i])
                {
                    if(previous==-1)
                        cout<<"Put "<<allBooks[i].title<<" first\n";
                    else
                        cout<<"Put "<<allBooks[i].title<<" after "<<allBooks[previous].title<<"\n";

                    returned[i]=false;
                    borrowed[i]=false;
                    previous=i;
                }
            }

            cout<<"END\n";
        }

    }
}


/**
Input :
"The Canterbury Tales" by Chaucer, G.
"Algorithms" by Sedgewick, R.
"The C Programming Language" by Kernighan, B. and Ritchie, D.
END
BORROW "Algorithms"
BORROW "The C Programming Language"
RETURN "Algorithms"
RETURN "The C Programming Language"
SHELVE
END

*/
