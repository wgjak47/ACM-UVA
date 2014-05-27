#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
double wins[20];
double chances[20][20];
char name[20][40];
void cal(int a,int b,int c)
{
	double sum=1;
	int m8[10],m4[10],final[10];//八强，四强，决赛
	for (int i=0;i<8;i++)
	{
		m8[i]=i*2+((a&(1<<i))==0?0:1);
		if ((a & (1<<i))==0)
			sum*=chances[m8[i]][m8[i]+1];
		else 
			sum*=chances[m8[i]][m8[i]-1];
	}
	for (int i=0;i<4;i++)
	{
		m4[i]=m8[i*2+((b&(1<<i))==0?0:1)];
		if ((b & (1<<i))==0)
			sum*=chances[m4[i]][m8[i*2+1]];
		else 
			sum*=chances[m4[i]][m8[i*2]];
	}
	for (int i=0;i<2;i++)
	{
		final[i]=m4[i*2+((c&(1<<i))==0?0:1)];
		if ((c & (1<<i))==0)
			sum*=chances[final[i]][m4[i*2+1]];
		else 
			sum*=chances[final[i]][m4[i*2]];
		
	}
	wins[final[0]]+=sum*chances[final[0]][final[1]];
	wins[final[1]]+=sum*chances[final[1]][final[0]];
			
}
void solve()
{
	for (int i=0;i<(1<<8);i++)
	for (int j=0;j<(1<<4);j++)
	for (int k=0;k<(1<<2);k++)
		cal(i,j,k);
	for (int i=0;i<16;i++)
		printf("%-10s p=%.2f%%\n",name[i],wins[i]*100.0);
	double sum=0;
	for (int i=0;i<16;i++) sum+=wins[i];
//		printf("%f\n",sum);
}
main()
{
	for (int i=0;i<16;i++)
	{
		scanf("%s",name[i]);
		wins[i]=0;
	}
	for (int i=0;i<16;i++)
	for (int j=0;j<16;j++)
	{
		scanf("%lf",&chances[i][j]);
		chances[i][j]/=100.0;
	}
	solve();
	return 0;
}
