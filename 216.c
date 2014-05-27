#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct aa
{
	int x,y;
} fuck;
int vis[100];
fuck a[100];
int location[100];
int temp[100];
double farm[100][100];
double sum;
void brother_hood_of_nod(int n,int reg,double far,int rear)
{
	int i;
	if (reg==n)
	{
		if (far<sum) 
		{
			sum=far;
			memcpy(location,temp,sizeof(temp));
		}
	}
	else 
		for (i=0;i<n;i++)
		if (!vis[i])
		{
			vis[i]=1;
			temp[reg]=i;
			if (reg!=0)
			brother_hood_of_nod(n,reg+1,far+farm[rear][i],i);
			else 
			brother_hood_of_nod(n,reg+1,far,i);
			vis[i]=0;
		}
}
main()
{
	int i,j,k,l,m,n,reg=0;
	while (scanf("%d",&n)==1)
	{
		if (n==0) break;
		printf("**********************************************************\nNetwork #%d\n",++reg);
		memset(vis,0,sizeof(vis));
		memset(location,0,sizeof(location));
		for (i=0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
		farm[j][i]=farm[i][j]=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y))+16;
		sum=100000000;
		brother_hood_of_nod(n,0,0,0);
		for (i=0;i<n-1;i++)
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",a[location[i]].x,a[location[i]].y,a[location[i+1]].x,a[location[i+1]].y,farm[location[i]][location[i+1]]);
		printf("Number of feet of cable required is %.2lf.\n",sum);
	}
	return 0;
}
