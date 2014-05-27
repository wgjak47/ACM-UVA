#include<stdio.h>
#include<string.h>
const int step[10][3]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
int nx,ny,sum;
void find(int rx,int ry)
{
	int Y[10000]={0};
	int X[10000]={0};
	int deep[10000]={0};
	int queen[9][9]={0};
	int i,j=0,k=1,hx,hy;
	X[0]=rx;
	Y[0]=ry;
	deep[0]=0;
	queen[rx][ry]=1;
	while (j<k)
	{
		for (i=0;i<8;i++)
		{
			hx=X[j]+step[i][0];
			hy=Y[j]+step[i][1];
			if (hx>0 && hx<=8 && hy>0 && hy<=8 && !queen[hx][hy])
 			{
				if (hx==nx&&hy==ny)
				{
					sum=deep[j]+1;
					if (j>=10000) printf("%d",j);
					return ;
				}
				X[k]=hx;
				Y[k]=hy;
				deep[k++]=deep[j]+1;
				if (k>=10000) printf("%d",k);
				if (j>=10000) printf("%d",j);
				queen[hx][hy]==1;
			}
		}
		j++;
	}
}
main()
{   
	char a[3],b[3];
	int ry,rx,n;
	freopen("in.txt","r",stdin);
	while (scanf("%s%s",a,b)==2)
  	{
		sum=0;
		getchar();
		rx=a[0]-'a'+1;
		ry=a[1]-'0';
		nx=b[0]-'a'+1;
		ny=b[1]-'0';
		printf("%d %d %d %d",rx,ry,nx,ny);
	if (rx!=nx || ry!=ny) find(rx,ry);
     printf("To get form %s to %s takes %d knight moves.\n",a,b,sum);
	 }
	return 0;
}
