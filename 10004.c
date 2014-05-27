#include<stdio.h>
#include<string.h>
int G[210][210];
int con[210];
int m;
main()
{ 
	int i,j,k,n,no;
/*	freopen("in.txt","r",stdin);*/
	while (scanf("%d",&m)==1)
 	{
		if (m==0) break;
		no=0;
		memset(G,0,sizeof(G));
		memset(con,0,sizeof(con));
		con[0]=1;
		scanf("%d",&n);
		for (i=0;i<n;i++)
 		{
			scanf("%d%d",&k,&j);
			G[k][j]=1;
			G[j][k]=1;
		}
		for (j=0;j<m;j++)
		for (i=0;i<m;i++)
			if (con[i]==0 && G[i][j] && con[j]!=0) con[i]=-con[j];
		for (i=0;i<m;i++)
		for (j=0;j<m;j++)
			if (G[i][j]) if (con[i]==con[j])
				{
					no=1;
					break;
				}
		if (!no) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}
	return 0;
}
