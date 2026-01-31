#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <ctime>
using namespace std;

class piece
{
    private:
    int x1,y1;
    int x2,y2;
    int x3,y3;
    int x4,y4;
    bool isactive;
    public:
    bool getact() {return isactive; }

    void setter(int pcode)
    {
        if(pcode==0)
        {
            x1=0; y1=4;
            x2=0; y2=5;
            x3=0; y3=6;
            x4=0; y4=7;
        }
        else if(pcode=1)
        {
            x1=0; y1=4;
            x2=0; y2=5;
            x3=0; y3=6;
            x4=1; y4=5;
        }
        else if(pcode==2)
        {
            x1=0; y1=4;
            x2=0; y2=5;
            x3=1; y3=5;
            x4=1; y4=6;
        }
        else if(pcode==3)
        {
            x1=0; y1=5;
            x2=0; y2=6;
            x3=1; y3=5;
            x4=1; y4=6;
        }
        else if(pcode==4)
        {
            x1=0; y1=4;
            x2=1; y2=4;
            x3=1; y3=5;
            x4=1; y4=6;
        }
    }
    void setact(bool x) {isactive=x;}
    

    bool piece_placement(int pcode,char (&env)[21][12])
    {
        
        
        if(env[x1][y1]=='.' && env[x2][y2]=='.' && env[x3][y3]=='.' && env[x4][y4]=='.')
        {
            env[x1][y1]='#';
            env[x2][y2]='#';
            env[x3][y3]='#';
            env[x4][y4]='#';
        }

        else return false;
        return true;

    }
    bool conditions(int pcode,char op,char (&env)[21][12])
    {
        if(op=='s')
        {
            if(block(pcode,env)) return false;
            else return true;
        }
        if(op=='a')
        {
            if(pcode==0)
            {
                if(env[x1][y1-1]=='.') return true;
                else return false;
            }
        }

    }
    bool block(int pcode,char (&env)[21][12])
    {
        if(pcode==0)
        {
            if((env[x1+1][y1]=='_' || env[x1+1][y1]=='#') ||
               (env[x2+1][y2]=='_' || env[x2+1][y2]=='#') ||
               (env[x3+1][y3]=='_' || env[x3+1][y3]=='#') ||
               (env[x4+1][y4]=='_' || env[x4+1][y4]=='#')    ) return true;
        }
        else if(pcode==1)
        {
            if((env[x1+1][y1]=='_' || env[x1+1][y1]=='#') || 
               (env[x3+1][y3]=='_' || env[x3+1][y3]=='#') ||
               (env[x4+1][y4]=='_' || env[x4+1][y4]=='#')    ) return true;

        }
        else if(pcode==2)
        {
            if((env[x1+1][y1]=='_' || env[x1+1][y1]=='#') || 
               (env[x3+1][y3]=='_' || env[x3+1][y3]=='#') ||
               (env[x4+1][y4]=='_' || env[x4+1][y4]=='#')    ) return true;
            
        }
        else if(pcode==3)
        {
            if((env[x3+1][y3]=='_' || env[x3+1][y3]=='#') ||
               (env[x4+1][y4]=='_' || env[x4+1][y4]=='#')    ) return true;
        }
        else if(pcode==4)
        {
            if((env[x2+1][y2]=='_' || env[x2+1][y2]=='#') ||
               (env[x3+1][y3]=='_' || env[x3+1][y3]=='#') ||
               (env[x4+1][y4]=='_' || env[x4+1][y4]=='#')    ) return true;
        }
        return false;
    }
    bool movedown(int pcode,char (&env)[21][12])
    {
        
        if(conditions(pcode,'s',env))
        {
            x1++;
            x2++;
            x3++;
            x4++;
            env[x1-1][y1]='.';
            env[x2-1][y2]='.';
            env[x3-1][y3]='.';
            env[x4-1][y4]='.';
            piece_placement(pcode,env);
        }

    }
    bool moveleft(int pcode,char (&env)[21][12])
    {
        if(conditions(pcode,'a',env))
        {
            env[x1][y1]='.';
            env[x2][y2]='.';
            env[x3][y3]='.';
            env[x4][y4]='.';
            y1--;
            y2--;
            y3--;
            y4--;
            piece_placement(pcode,env);
        }
    }

    bool moveright(int pcode,char (&env)[21][12])
    {
        if(conditions(pcode,'d',env))
        {
            env[x1][y1]='.';
            env[x2][y2]='.';
            env[x3][y3]='.';
            env[x4][y4]='.';
            y1++;
            y2++;
            y3++;
            y4++;
            piece_placement(pcode,env);

        }
    }
    

};

void start_game(char (&env)[21][12])
{

    //list:
    // 0: ####

    // 1: ###
    //     #

    // 2: ##
    //     ##

    // 3: ##
    //    ##

    // 4: #
    //    ###

    bool ingame=true;
    clock_t time=clock();
    piece p;
    int pcode=rand() % 5;
    p.setter(pcode);
    p.piece_placement(pcode,env);
    p.setact(true);
    
    while(ingame)
    {
        if(p.block(pcode,env)) p.setact(false);
        if(!p.getact())
        {
            int pcode=rand() % 5;
            p.setter(pcode);
            p.piece_placement(pcode,env);
        }
        if(clock()-time>400)
        {
            p.movedown(pcode,env);
            time=clock();
            
        }
        if(_kbhit())
        {
            char x=getch();
            if(x=='s')
            {
                p.movedown(pcode,env);
            }
            if(x=='a')
            {
                p.moveleft(pcode,env);
            }
            if(x=='d')
            {
                p.moveright(pcode,env);
            }
        }



    }


}
void game(char (&env)[21][12])
{
    int choice;
    bool ingame;
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


int main ()
{
    

    char env[21][12];
    for(int i=0;i<21;i++) 
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
    for(int i=1;i<11;i++)
    {
        env[20][i]='_';
    }
    for(int i=0;i<21;i++)    /////env
    {
        for(int j=0;j<12;j++)
        {
            cout<<env[i][j];
        }
        cout<<endl;
    }

    srand(time(0));
    game(env);
   
}