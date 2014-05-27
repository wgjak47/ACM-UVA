#include<cstdio>
#include<cstring>
struct data 
{
	int row,column;
};
data output[5001];
int x1[5001],y1[5001],x2[5001],y2[5001];
bool row[5001],column[5001];
bool solve(int N)
{
	for (int i=1;i<=N;i++)
	{
		int min=-1;
		for (int j=0;j<N;j++)
		if (!row[j] && x1[j]<=i && x2[j]>=i && (min==-1 || x2[min]>x2[j]))
			min=j;
		if (min!=-1)
		output[min].row=i,row[min]=true;
		else return false;
	}
	for (int i=1;i<=N;i++)
	{
		int min=-1;
		for (int j=0;j<N;j++)
		if (!column[j] && y1[j]<=i && y2[j]>=i && (min==-1 || y2[min]>y2[j]))
			min=j;
		if (min!=-1)
		output[min].column=i,column[min]=true;
		else return false;
	}
	return true;
}
main()
{
	int N;
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		memset(row,0,sizeof(row));
		memset(column,0,sizeof(column));
		for (int i=0;i<N;i++)
			scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		if (solve(N))
			for (int i=0;i<N;i++)
				printf("%d %d\n",output[i].row,output[i].column);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
