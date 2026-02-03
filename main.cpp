#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

class piece
{
    private:
    int x1,y1;
    int x2,y2;
    int x3,y3;
    int x4,y4;
    int r;
    bool isactive;
    public:
    bool getact() {return isactive; }
    void rop() {r++;}
    void setter(int pcode)
    {
        r=0;
        if(pcode==0)
        {
            x1=0; y1=4;
            x2=0; y2=5;
            x3=0; y3=6;
            x4=0; y4=7;
        }
        else if(pcode==1)
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
    void piece_placement(int pcode,char (&env)[21][12])
    {
        env[x1][y1]='#';
        env[x2][y2]='#';
        env[x3][y3]='#';
        env[x4][y4]='#';
    }
    bool conditions(int pcode,char op,char (&env)[21][12])
    {
        if(op=='s')
        {
            if(block(pcode,env)) return false;
            else return true;
        }
        else if(op=='a')
        {
            if(pcode==0)
            {
                if(r%2==0)
                {
                    if( y1>=2 && env[x1][y1-1]=='.') return true;
                    else return false;
                }
                else
                {
                    if(y1>=2 && env[x1][y1-1]=='.' && env[x2][y2-1]=='.' && env[x3][y3-1]=='.' && env[x4][y4-1]=='.') return true;
                    else return false;
                }
            }
            else if(pcode==1)
            {
                if(r%4==0)
                {
                    if(y1>=2 && env[x1][y1-1]=='.' && env[x4][y4-1]=='.') return true;
                    else return false;
                }
                else if(r%4==1)
                {
                    if(y4>=2 && env[x1][y1-1]=='.' && env[x4][y4-1]=='.' && env[x3][y3-1]=='.') return true;
                    else return false;
                }
                else if(r%4==2)
                {
                    if(y3>=2 && env[x4][y4-1]=='.' && env[x3][y3-1]=='.') return true;
                    else return false;
                }
                else if(r%4==3)
                {
                    if(y1>=2 && env[x1][y1-1]=='.' && env[x2][y2-1]=='.' && env[x3][y3-1]=='.') return true;
                    else return false;
                }
            }
            else if(pcode==2)
            {
                if(r%2==0)
                {
                    if(y1>=2  && env[x1][y1-1]=='.' && env[x3][y3-1]=='.') return true;
                    else return false;
                }
                else
                {
                    if( y4>=2 && env[x1][y1-1]=='.' && env[x3][y3-1]=='.' && env[x4][y4-1]=='.') return true;
                    else return false;
                }
            }
            else if(pcode==3)
            {
                if( y3>=2 && env[x1][y1-1]=='.' && env[x3][y3-1]=='.') return true;
                else return false;
            }
            else if(pcode==4)
            {
                if(r%4==0)
                {
                    if(y2>=2 && env[x1][y1-1]=='.' && env[x2][y2-1]=='.') return true;
                    else return false;
                }
                else if(r%4==1)
                {
                    if(y2>=2 && env[x2][y2-1]=='.' && env[x4][y4-1]=='.' && env[x3][y3-1]=='.') return true;
                    else return false;
                }
                else if(r%4==2)
                {
                    if(y4>=2 && env[x4][y4-1]=='.' && env[x1][y1-1]=='.') return true;
                    else return false;
                }
                else if(r%4==3)
                {
                    if( y1>=2 && env[x1][y1-1]=='.' && env[x4][y4-1]=='.' && env[x3][y3-1]=='.') return true;
                    else return false;
                }
            }
            
        }
        else if(op=='d')
        {
           if(pcode==0)
            {
                if(r%2==0)
                {
                    if(y4<=11 && env[x4][y4+1]=='.') return true;
                    else return false;
                }
                else
                { 
                    if( y4<=11 && env[x4][y4+1]=='.' && env[x3][y3+1]=='.' && env[x2][y2+1]=='.' && env[x1][y1+1]=='.') return true;
                    else return false;
                }
            }
            else if(pcode==1)
            {
                if(r%4==0)
                {
                    if(y3<=11 && env[x3][y3+1]=='.' && env[x4][y4+1]=='.') return true;
                    else return false;
                }
                if(r%4==1)
                {
                    if(y1<=11 && env[x3][y3+1]=='.' && env[x1][y1+1]=='.' && env[x2][y2+1]=='.') return true;
                    else return false;
                }
                if(r%4==2)
                {
                    if(y1<=11 && env[x1][y1+1]=='.' && env[x4][y4+1]=='.') return true;
                    else return false;
                }
                if(r%4==3)
                {
                    if(y4<=11 && env[x3][y3+1]=='.' && env[x1][y1+1]=='.' && env[x4][y4+1]=='.') return true;
                    else return false;
                }

            }
            else if(pcode==2)
            {
                if(r%2==0)
                {
                    if(y4<=11 && env[x4][y4+1]=='.' && env[x2][y2+1]=='.') return true;
                    else return false;
                }
                else
                {
                    if( y1<=11 && env[x4][y4+1]=='.' && env[x2][y2+1]=='.' && env[x1][y1+1]=='.') return true;
                    else return false;
                }
            }
            else if(pcode==3)
            {
                if( y2<=11 && env[x2][y2+1]=='.' && env[x4][y4+1]=='.') return true;
                else return false;
            }
            else if(pcode==4)
            {
                if(r%4==0)
                {
                    if( y4<=11 && env[x1][y1+1]=='.' && env[x4][y4+1]=='.') return true;
                    else return false;
                }
                if(r%4==1)
                {
                    if(y1<=11 &&  env[x3][y3+1]=='.' && env[x1][y1+1]=='.' && env[x4][y4+1]=='.') return true;
                    else return false;
                }
                if(r%4==2)
                {
                    if(y1<=11 && env[x1][y1+1]=='.' && env[x2][y2+1]=='.') return true;
                    else return false;
                }
                if(r%4==3)
                {
                    if(y2<=11 &&  env[x3][y3+1]=='.' && env[x2][y2+1]=='.' && env[x4][y4+1]=='.') return true;
                    else return false;
                }
            } 
        }
        else if(op=='i')
        {
            if(env[x1][y1]=='.' && env[x2][y2]=='.' && env[x3][y3]=='.' && env[x4][y4]=='.') return true;
            else return false;
        }
        else if(op='x')
        {
            if(pcode==0)
            {
                if(r%2==0 && x1>=3 && x3<=18)
                {
                    if( env[x1-2][y1+2]=='.' && env[x2-1][y1+1]=='.' && env[x4+1][y4-1]=='.') return true;
                    else return false;
                }
                else if(r%2==1 && y3<=9 && y1>=3)
                {
                    if(env[x1+2][y1-2]=='.' && env[x2+1][y1-1]=='.' && env[x4-1][y4+1]=='.')  return true;
                    else return false;
                }
            }
            else if(pcode==1)
            {
                if(r%4==0 && x2>=1)
                {
                    if(env[x2-1][y2]=='.') return true;
                    else return false;
                }
                else if(r&4==1 && y2<=9)
                {
                    if(env[x2][y2+1]=='.') return true;
                    else return false;
                }
                else if(r%4==2)
                {
                    if(env[x2+1][y2]=='.') return true;
                    else return false;
                }
                else if(r%4==3 && y2>=2)
                {
                    if(env[x2][y2-1]=='.') return true;
                    else return false;
                }
            }
            else if(pcode==2)
            {
                if(r%2==0 && x2>=1)
                {
                    if(env[x2-1][y2]=='.' && env[x3][y3-1]=='.') return true;
                    else return false;
                }
                else if(r%2==1 && y2<=9)
                {
                    if(env[x4][y4+1]=='.' && env[x2+1][y2+1]=='.') return true;
                    else return false;
                }
            }
            else if(pcode==4)
            {
                if(r%4==0)
                {
                    if(env[x4-1][y4]=='.' && env[x3-1][y3]=='.' && env[x3+1][x3]=='.') return true;
                    else return false;
                }
                else if(r%4==1 && y3>=2)
                {
                    if(env[x3][y3+1]=='.' && env[x3][y3-1]=='.' && env[x4][y4+1]=='.') return true;
                    else return false;
                }
                else if(r%4==2 && x3>=1)
                {
                    if(env[x3-1][y3]=='.' && env[x3+1][y3]=='.' && env[x3+1][y4]=='.') return true;
                    else return true;
                }
                else if(r%4==3  && y3<=9 )
                {
                    if(env[x3][y3+1]=='.' && env[x3][y3-1]=='.' && env[x4][y4-1]=='.') return true;
                    else return false;
                }
            }
        }
        else if(op=='w')
        {
            if(pcode==0)
            {
                if(r%2==0)
                {
                    if(env[x1-1][y1]=='.' && env[x2-1][y2]=='.' && env[x3-1][y3]=='.' && env[x4-1][y4]=='.' ) return true;
                    else return false;
                }
                else 
                {
                    if(env[x1-1][y1]=='.') return true;
                    else return false;
                }
            }
            else if(pcode==1)
            {
                if(r%4==0)
                {
                    if(env[x1-1][y1]=='.' && env[x2-1][y2]=='.' && env[x3-1][y3]=='.') return true;
                    else return false;
                }
                else if(r%4==1)
                {
                    if(env[x1-1][y1]=='.' && env[x4-1][y4]=='.') return true;
                    else return false;
                }
                else if(r%4==2)
                {
                    if(env[x1-1][y1]=='.' && env[x4-1][y4]=='.' && env[x3-1][y3]=='.') return true;
                    else return false;
                }
                else if(r%4==3)
                {
                    if(env[x4-1][y4]=='.' && env[x3-1][y3]=='.') return true;
                    else return false;
                }
            }
            else if(pcode==3)
            {
                if(env[x1-1][y1]=='.' && env[x2-1][y2]=='.') return true;
                else return false;
            }
            else if(pcode==4)
            {
                if(r%4==0)
                {
                    if(env[x1-1][y1]=='.' && env[x4-1][y4]=='.' && env[x3-1][y3]=='.') return true;
                    else return false;
                }
                else if(r%4==1)
                {
                    if(env[x1-1][y1]=='.' && env[x2-1][y2]=='.') return true;
                    else return false;
                }
                else if(r%4==2)
                {
                    if(env[x2-1][y2]=='.' && env[x4-1][y4]=='.' && env[x3-1][y3]=='.') return true;
                    else return false;
                }
                else if(r%4==3)
                {
                    if(env[x4-1][y4]=='.' && env[x1-1][y1]=='.') return true;
                    else return false;
                }
            }
        }
        return true;

    }
    bool block(int pcode,char (&env)[21][12])
    {
        if(pcode==0)
        {
            if(r%2==0)
            {
                if(env[x1+1][y1]!='.' || env[x2+1][y2]!='.' || env[x3+1][y3]!='.' || env[x4+1][y4]!='.') return true;
            }
            else if(r%2==1)
            {
                if(env[x4+1][y4]!='.') return true;
            }
        }
        else if(pcode==1)
        {
            if(r%4==0)
            {
                if((env[x1+1][y1]!='.' || env[x3+1][y3]!='.' || env[x4+1][y4]!='.') ) return true;
            }
            else if(r%4==1)
            {
                if( env[x3+1][y3]!='.' || env[x4+1][y4]!='.' ) return true;
            }
            else if(r%4==2)
            {
                if( env[x3+1][y3]!='.' || env[x1+1][y1]!='.' || env[x2+1][y2]!='.') return true;
            }
            else if(r%4==3)
            {
                if( env[x1+1][y1]!='.' || env[x4+1][y4]!='.' ) return true;
            }

            

        }
        else if(pcode==2)
        {
           if(r%2==0)
            {
                if(env[x1+1][y1]!='.' ||  env[x3+1][y3]!='.' || env[x4+1][y4]!='.') return true;
            }
            else if(r%2==1)
            {
                if(env[x2+1][y2]!='.'  || env[x4+1][y4]!='.') return true;
            }
            
        }
        else if(pcode==3)
        {
            if((env[x3+1][y3]=='_' || env[x3+1][y3]=='#') ||
               (env[x4+1][y4]=='_' || env[x4+1][y4]=='#')    ) return true;
        }
        else if(pcode==4)
        {
           if(r%4==0)
            {
                if( env[x2+1][y2]!='.' || env[x3+1][y3]!='.' || env[x4+1][y4]!='.') return true;
            }
            else if(r%4==1)
            {
                if(env[x1+1][y1]!='.'  || env[x4+1][y4]!='.') return true;
            }
            else if(r%4==2)
            {
                if(env[x1+1][y1]!='.'  || env[x3+1][y3]!='.' || env[x4+1][y4]!='.') return true;
            }
            else if(r%4==3)
            {
                if(env[x1+1][y1]!='.' || env[x2+1][y2]!='.' ) return true;
            }
        }
        return false;
    }
    void movedown(int pcode,char (&env)[21][12])
    {
        
        if(conditions(pcode,'s',env))
        {
            env[x1][y1]='.';
            env[x2][y2]='.';
            env[x3][y3]='.';
            env[x4][y4]='.';
            x1++;
            x2++;
            x3++;
            x4++;
            piece_placement(pcode,env);
        }

    }
    void moveleft(int pcode,char (&env)[21][12])
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
    void moveright(int pcode,char (&env)[21][12])
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
    void moveup (int pcode,char (&env)[21][12])
    {
        if(conditions(pcode,'w',env))
        {
            env[x1][y1]='.';
            env[x2][y2]='.';
            env[x3][y3]='.';
            env[x4][y4]='.';
            x1--;
            x2--;
            x3--;
            x4--;
            piece_placement(pcode,env);
        }
    }
    void rotate(int pcode,char (&env)[21][12])
    {
        if(conditions(pcode,'x',env))
        {
            if(pcode==0)
            {
                if(r%2==0)
                {
                    env[x1][y1]='.';
                    env[x2][y2]='.';
                    env[x3][y3]='.';
                    env[x4][y4]='.';
                    x1-=2;
                    y1+=2;
                    x2--;
                    y2++;
                    x4++;
                    y4--;
                    piece_placement(pcode,env);
                }
                else if(r%2==1)
                {
                    env[x1][y1]='.';
                    env[x2][y2]='.';
                    env[x3][y3]='.';
                    env[x4][y4]='.';
                    x1+=2;
                    y1-=2;
                    x2++;
                    y2--;
                    x4--;
                    y4++;
                    piece_placement(pcode,env);
                }

            }
            else if(pcode==1)
            {
                if(r%4==0)
                {
                    env[x1][y1]='.';
                    env[x2][y2]='.';
                    env[x3][y3]='.';
                    env[x4][y4]='.';
                    x1--;
                    y1++;
                    x3++;
                    y3--;
                    x4--;
                    y4--;
                    piece_placement(pcode,env);
                }
                else if(r%4==1)
                {
                    env[x1][y1]='.';
                    env[x2][y2]='.';
                    env[x3][y3]='.';
                    env[x4][y4]='.';
                    x1++;
                    y1++;
                    x3--;
                    y3--;
                    x4--;
                    y4++;
                    piece_placement(pcode,env);
                }
                else if(r%4==2)
                {
                    env[x1][y1]='.';
                    env[x2][y2]='.';
                    env[x3][y3]='.';
                    env[x4][y4]='.';
                    x1++;
                    y1--;
                    x3--;
                    y3++;
                    x4++;
                    y4++;
                    piece_placement(pcode,env);
                }
                else if(r%4==3)
                {
                    env[x1][y1]='.';
                    env[x2][y2]='.';
                    env[x3][y3]='.';
                    env[x4][y4]='.';
                    x1--;
                    y1--;
                    x3++;
                    y3++;
                    x4++;
                    y4--;
                    piece_placement(pcode,env);
                }

            }
            else if(pcode==2)
            {
                if(r%2==0)
                {
                    env[x1][y1]='.';
                    env[x2][y2]='.';
                    env[x3][y3]='.';
                    env[x4][y4]='.';
                    x1--;
                    y1++;
                    x3--;
                    y3--;
                    y4-=2;
                    piece_placement(pcode,env);
                }
                else if(r%2==1)
                {
                    env[x1][y1]='.';
                    env[x2][y2]='.';
                    env[x3][y3]='.';
                    env[x4][y4]='.';
                    x1++;
                    y1--;
                    x3++;
                    y3++;
                    y4+=2;
                    piece_placement(pcode,env);
                }
            }
            else if(pcode==4)
            {
                if(r%4==0)
                {
                    env[x1][y1]='.';
                    env[x2][y2]='.';
                    env[x3][y3]='.';
                    env[x4][y4]='.';
                    y1+=2;
                    x2--;
                    y2++;
                    x4++;
                    y4--;
                    piece_placement(pcode,env);
                }
                else if(r%4==1)
                {
                    env[x1][y1]='.';
                    env[x2][y2]='.';
                    env[x3][y3]='.';
                    env[x4][y4]='.';
                    x1+=2;
                    x2++;
                    y2++;
                    x4--;
                    y4--;
                    piece_placement(pcode,env);
                }
                else if(r%4==2)
                {
                    env[x1][y1]='.';
                    env[x2][y2]='.';
                    env[x3][y3]='.';
                    env[x4][y4]='.';
                    y1-=2;
                    x2++;
                    y2--;
                    x4--;
                    y4++;
                    piece_placement(pcode,env);
                }
                else if(r%4==3)
                {
                    env[x1][y1]='.';
                    env[x2][y2]='.';
                    env[x3][y3]='.';
                    env[x4][y4]='.';
                    x1-=2;
                    x2--;
                    y2--;
                    x4++;
                    y4++;
                    piece_placement(pcode,env);
                }
            }
        }
    }

};
void game(char (&env)[21][12]);
void gotoXY(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int score_check(char (&env)[21][12])
{
    bool x;
    int ans[4]={-1,-1,-1,-1};
    int a=0;
    for(int i=19;i>=0;i--)
    {
        x=true;
        for(int j=1;j<11;j++)
        {
            if(env[i][j]=='.') x=false;
        }
        if(x)
        {
            ans[a]=i;
            a++;
            // cout<<a<<endl;
        }
    }

    if(ans[1]!=-1) ans[1]+=1;
    if(ans[2]!=-1) ans[1]+=2;
    if(ans[3]!=-1) ans[1]+=3;

    for(int k=0;k<4;k++)
    {
        if(ans[k]==-1) break;
        if(ans[k]!=-1)
        {
            for(int i=1;i<11;i++)
            {
                env[ans[k]][i]='.';
            }

            for(int i=ans[k]-1;i>=0;i--)
            {
                for(int j=1;j<11;j++)
                {
                    env[i+1][j]=env[i][j];
                    env[i][j]='.';
                }
            }
        }
    }

    if(a==0) return 0;
    if(a==1) return 100;
    if(a==2) return 300;
    if(a==3) return 500;
    if(a==4) return 800;
    return 0;
}
void display(char (&env)[21][12],int score,int lines,string state,string cheat)
{
    gotoXY(0, 0);
    cout<<"                 "<<endl;
    cout<<"                 "<<endl;
    cout<<"                 "<<endl;
    cout<<"Score: "<<score<<"   Lines: "<<lines<<"  State: "<<state<<"  cheat: "<<cheat<<endl;
    cout<<endl;
    for(int i=0;i<21;i++)    /////env
    {
        for(int j=0;j<12;j++)
        {
            cout<<env[i][j];
        }
        cout<<endl;
        
    }
    cout<<"\nControls: a=left  d=right  s=down  x=rotate  p=pause  q=quit  c=cheat code ";
    if(cheat=="ON") cout<<" w=up\n";
    cout<<"                   \n";
}
bool Cheat(string x)
{
    if(x=="asghar") return true;
    else if(x=="kokab") return false;
    return false;
}
void start_game(char (&env)[21][12])
{
    // 0: ####    1: ###    2: ##     3: ##    4: #
    //                #         ##       ##       ###

    bool ingame=true,cheat=false;
    clock_t time=clock();
    piece p;
    int pcode=rand() % 5;
    p.setter(pcode);
    p.piece_placement(pcode,env);
    p.setact(true);
    int score=0,lines=0,temp;
    string state="Playing",cheat_state="OFF";
    while(ingame)
    {

        if(p.block(pcode,env))
        {
            p.setact(false);
            temp=score_check(env);
            score+=temp;
            if(temp) lines+=1;
            else if(temp) lines+=2;
            else if(temp) lines+=3;
            else if(temp) lines+=4;
        }
        
        if(!p.getact())
        {
            pcode=rand() % 5;
            p.setter(pcode);
            if (p.conditions(pcode,'i',env)) p.piece_placement(pcode,env);
            else 
            {
                cout<<"\nYou Lost\nYour score is: "<<score<<endl;
                cout<<"\n\n\n";
                game(env);
            }
            
            p.setact(true);
        }
        
        if(_kbhit())
        {
            char x=_getch();
            if(x=='s'|| x=='S') p.movedown(pcode,env);
            if(x=='a'|| x=='A') p.moveleft(pcode,env);
            if(x=='d'|| x=='D') p.moveright(pcode,env);
            if(x=='w'|| x=='W') if(cheat==true) p.moveup(pcode,env);
            if(x=='x'|| x=='X')
            {
               p.rotate(pcode,env);
               p.rop();
            }
            if(x=='p'|| x=='P')
            {
                state="Paused ";
                display(env,score,lines,state,cheat_state);
                char y=' ';
                do
                {
                    y=_getch();
                } while (y!='p' && y!='q');
                if(y=='q')
                {
                    game(env);
                    ingame=false;
                }
            }
            if(x=='q'|| x=='Q')
            {
                cout<<"are you sure you want to exit? (y/n)\n\n\n";
                char y=' ';
                do
                {
                    y=_getch();
                } while (y!='n' && y!='y');
                if(y=='y')
                {
                    game(env);
                    ingame=false;
                }
                
            }
            if(x=='c'|| x=='C')
            {
                string c;
                getline(cin,c);
                if(c=="asghar") cheat=true;
                else if (c=="kokab") cheat=false;
                else cheat=false;
            }
        }
        if(clock()-time>500 && cheat==false)
        {
            p.movedown(pcode,env);
            time=clock();
            
        }
        
        if(cheat==true) cheat_state="ON";
        else cheat_state="OFF";
        
        display(env,score,lines,state,cheat_state);
        state="Playing";
        
        Sleep(5);
    }


}
void game(char (&env)[21][12])  
{

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

    int choice;
    bool ingame;
    bool validate=true;
    string s="1-New Game \n2-Help \n3-Exit\n";
    cout<<s;

    while(validate)
    {
        cin>>choice;
        if(choice==1 || choice==2 || choice==3) validate=false;
        if(choice==1)
        {
            gotoXY(0, 0);
            start_game(env);

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
    

    srand(time(0));
    game(env);
   
}