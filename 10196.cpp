#include<iostream>
#include<cstring>
#include<cstdio>
char G[9][9];
using namespace std;
bool solve(bool color,int Bx,int By)
{
    int i,j;
    bool black=true;
    int flag1,flag2,flag3,flag4;
    char r,q,b,k,n,p;
    if (color)
    {
        r='R';
        q='Q';
        b='B';
        k='K';
        n='N';
        p='P';
    }
    else
    {
        r='r';
        q='q';
        b='b';
        k='k';
        n='n';
        p='p';
    }
    flag1=flag2=flag3=flag4=true;
    for (i=1; black && (flag1 || flag2 || flag3 || flag4); i++)
    {
        if ( Bx-i<0) flag1=false;
        if (flag1 && G[Bx-i][By]!='.')
        {
            if (G[Bx-i][By]==r ||  G[Bx-i][By]==q)
            {
                black=false;
            }
            flag1=false;
        }
        if ( Bx+i>=8) flag2=false;
        if (flag2 && G[Bx+i][By]!='.')
        {
            if (G[Bx+i][By]==r ||  G[Bx+i][By]==q)
            {
                black=false;
            }
            flag2=false;
        }
        if (By+i>=8) flag3=false;
        if (flag3 && G[Bx][By+i]!='.')
        {
            if (G[Bx][By+i]==r ||  G[Bx][By+i]==q)
            {
                black=false;
            }
            flag3=false;
        }
        if (By-i<0) flag4=false;
        if (flag4 && G[Bx][By-i]!='.')
        {
            if (G[Bx][By-i]==r ||  G[Bx][By-i]==q)
            {
                black=false;
            }
            flag4=false;
        }
    }
    flag1=flag2=flag3=flag4=true;
    if (black)
        for (i=1; black && (flag1 || flag2 || flag3 || flag4); i++)
        {
            if (Bx+i>=8 || By+i>=8) flag1=false;
            if (flag1 && G[Bx+i][By+i]!='.')
            {
                if (G[Bx+i][By+i]==b ||  G[Bx+i][By+i]==q)
                {
                    black=false;
                }
                flag1=false;
            }
            if (Bx+i>=8 || By-i<0) flag2=false;
            if (flag2 && G[Bx+i][By-i]!='.')
            {
                if (G[Bx+i][By-i]==b ||  G[Bx+i][By-i]==q)
                {
                    black=false;
                }
                flag2=false;
            }
            if (Bx-i<0 || By+i>=8) flag3=false;
            if (flag3 && G[Bx-i][By+i]!='.')
            {
                if (G[Bx-i][By+i]==b ||  G[Bx-i][By+i]==q)
                {
                    black=false;
                }
                flag3=false;
            }
            if ( Bx-i<0 || By-i>=8) flag4=false;
            if (flag4 && G[Bx-i][By-i]!='.')
            {
                if (G[Bx-i][By-i]==b ||  G[Bx-i][By-i]==q)
                {
                    black=false;
                }
                flag4=false;
            }
        }
    int bz[9][2]= {{2,1},{1,2},{2,-1},{-1,2},{-2,-1},{-1,-2},{1,-2},{-2,1}};
    for (i=0; i<8; i++)
        if (Bx+bz[i][0]>=0 &&By+bz[i][1]>=0 && Bx+bz[i][0]<8 &&By+bz[i][1]<8 && G[Bx+bz[i][0]][By+bz[i][1]]==n)
        {
            black=false;
            break;
        }
    if (color)
    {
      if ((Bx+1<8 && By+1<8 && G[Bx+1][By+1]==p) || (Bx+1<8 && By-1>=0 && G[Bx+1][By-1]==p)) black=false;
	}
    else  if ((Bx-1>=0 && By-1>=0 && G[Bx-1][By-1]==p) || (Bx-1>=0 && By+1<8 && G[Bx-1][By+1]==p)) black=false;
    
    if (black) return false;
    return true;
}
main()
{
    int i=0,j,k;
    int reg=1;
  //  freopen("data.txt","r",stdin);
    while (gets(G[i++])!=NULL)
        if (i==8)
        {
            cin.get();
            int Bx=-1,By=-1;
            int Wx=-1,Wy=-1;
            for (i=0; i<8; i++)
                for (j=0; j<8; j++)
                {
                    if (G[i][j]=='k')
                    {
                        Bx=i;
                        By=j;
                    }
                    else if (G[i][j]=='K')
                    {
                        Wx=i;
                        Wy=j;
                    }
                }
            if (Bx==-1) return 0;
            if (solve(true,Bx,By)) cout<<"Game #"<<reg++<<": black king is in check."<<endl;
            else if (solve(false,Wx,Wy)) cout<<"Game #"<<reg++<<": white king is in check."<<endl;
            else cout<<"Game #"<<reg++<<": no king is in check."<<endl;
            i=0;
        }
    return 0;
}
