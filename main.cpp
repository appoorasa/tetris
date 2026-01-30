#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


void start_game(string env[])
{
    
}


int main ()
{
    bool ingame;

    string env[20][12];
    for(int i=0;i<20;i++) 
    {
        env[i][0]='|';
        env[i][11]='|';
    }
    for(int i=0;i<20;i++)
    {
        for(int j=1;j<11;j++)
        {
            env[i][j]='.';
        }
    }
    // for(int i=0;i<20;i++)    /////env
    // {
    //     for(int j=0;j<12;j++)
    //     {
    //         cout<<env[i][j];
    //     }
    //     cout<<endl;
    // }

    
    int choice;
    bool validate=true;
    cout<<"1-New Game \n2-Help \n3-Exit";
    cin>>choice;
    while(validate)
    {
        if(choice==1 || choice==2 || choice==3) validate=false;
        // else cout<<
        if(choice==1)
        {
            ingame=true;

        }
        else if(choice==2)
        {

        }
        else
        {

        }
    }
}