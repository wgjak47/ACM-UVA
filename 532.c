#include<stdio.h>
#include<string.h>
char s[41][41][41];
int a[7][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int L,R,C,sum;
int  bfs(int x,int y,int z)
{
	int head=0,tail=1;
	int i,j,k,l,m,n,hx,hy,hz;
	int deep[200000]={0},X[200000]={0},Y[200000]={0},Z[200000]={0};
	s[z][x][y]='#';
	X[head]=x;
	Y[head]=y; 
	Z[head]=z;
	while (head<tail)
	{ 
		for (i=0;i<6;i++)
	  	{
			hx=X[head]+a[i][0];
			hy=Y[head]+a[i][1];
			hz=Z[head]+a[i][2];
			if (hx>=0 && hx<R && hy>=0 && hy<C && hz>=0&& hz<L && s[hz][hx][hy]!='#')
	 		{
				if (s[hz][hx][hy]=='E')
	 			{
					sum=deep[head]+1;
					return 1;
				}
				s[hz][hx][hy]='#';
				X[tail]=hx;
				Y[tail]=hy;
				Z[tail]=hz;
				deep[tail++]=deep[head]+1;
			}
		}
		head++;
	}
	return 0;
}
main()
{
	int i,k,l,j,x,y,z,flag;
/*	freopen("in.txt","r",stdin);*/
	while (scanf("%d%d%d",&L,&R,&C))
	{
		if (L==0 && R==0 && C==0)	break;
		memset(s,'#',sizeof(s));
		getchar();
		sum=0;
		for (i=0;i<L;i++)
		{
			for (j=0;j<R;j++)
			{
				for (l=0;l<C;l++)
				{
					s[i][j][l]=getchar();
						if (s[i][j][l]=='S')
						{
							z=i;x=j;y=l;
						}
				}
				getchar();
			}
			getchar();
		}
/*		for (i=0;i<L;i++)
		{
			for (j=0;j<R;j++)
			{
				for (l=0;l<C;l++)
					putchar(s[i][j][l]);
				putchar('\n');
			}
			putchar('\n');
		}*/
		if (bfs(x,y,z))
		printf("Escaped in %d minute(s).\n",sum);
		else printf("Trapped!\n");
		sum=0;
	}
	return 0;
}
