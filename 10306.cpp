#include<cstdio>
#include<cstring>
int D[310][310];
int cx[50],cy[50];
main()
{
	int T;
	scanf("%d",&T);
	int m,S;
	while (T--)
	{
		memset(D,0,sizeof(D));
		scanf("%d%d",&m,&S);
		for (int i=0;i<m;i++)
			scanf("%d%d",&cx[i],&cy[i]);
		int max=10000;
		for (int i=0;i<=S;i++)
		for (int j=0;j<=S;j++)
		{
			if (D[i][j]!=0 && i*i+j*j==S*S && D[i][j]<max)
				max=D[i][j];
			if (D[i][j]!=0 || (i==0 && j==0))
			for (int k=0;k<m;k++)
			if (i+cx[k]<=S && j+cy[k]<=S)
				if (D[i+cx[k]][j+cy[k]]>D[i][j]+1 || D[i+cx[k]][j+cy[k]]==0)
					D[i+cx[k]][j+cy[k]]=D[i][j]+1;
		}
		if (max==10000)
			printf("not possible\n");
		else printf("%d\n",max);
	}
	return 0;
}
