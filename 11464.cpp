#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N;	
int data[20][20];
int check(int k)
{
	int sum=0;
	int matrix[20][20];
	memset(matrix,0,sizeof(matrix));
	for (int i=0;i<N;i++)
		if (k&(1<<i)) matrix[0][i]=1;
	for (int i=1;i<N;i++)
	for (int j=0;j<N;j++)
	{
		int z=0;
		if (i>1) z+=matrix[i-2][j];
		if (j+1<N) z+=matrix[i-1][j+1];
		if (j-1>=0) z+=matrix[i-1][j-1]; 
		matrix[i][j]=z%2==1?1:0;
	}
	for (int i=0;i<N;i++)
	for (int j=0;j<N;j++)
	{
		if (matrix[i][j]!=data[i][j] && data[i][j]==1) return -1;
		if (matrix[i][j]) sum++;
		int z=0;
		if (j+1<N) z+=matrix[i][j+1];
		if (j-1>=0) z+=matrix[i][j-1];
		if (i-1>=0) z+=matrix[i-1][j];
		if (i+1<N) z+=matrix[i+1][j];
		if (z%2)  return -1; 
	}
	return sum;
}
main()
{ 
	int T;
	scanf("%d",&T);
	int cases=0;
	while (T--)
 	{
		scanf("%d",&N);
		int kk=0;
		for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
		{
			scanf("%d",&data[i][j]);		
			if (data[i][j]==1) kk++;
		}
		int min=1<<30;
		for (int i=0;i<(1<<N);i++)
		{
			int temp=check(i);
			if (min>temp && temp>=0) min=temp;
		}
		printf("Case %d: ",++cases);
		if (min==1<<30)
			printf("%d\n",-1);
		else printf("%d\n",min-kk);
	}
	return 0;
}
