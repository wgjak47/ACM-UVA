#include<stdio.h>
#include<string.h>
char s[1020];
int G[30][30];
int reg[30][2];
int max;
int vis[30];
void dfs_fuck(int i)
{
	int j;
	max++;
	vis[i]=1;
	for (j=0;j<26;j++)
		if (G[i][j] && !vis[j])
			dfs_fuck(j);
}
main()
{:
	int i,j,k,l,m,n;
	int ans;
	int flag1,ok,flag2,start,total;
/*	freopen("in.txt","r",stdin);*/
	scanf("%d",&n);
	getchar();
	for (ans=0;ans<n;ans++)
	{
		flag1=0;
		flag2=0;
		ok=1;
		max=0;
		total=0;
		memset(G,0,sizeof(G));
		memset(reg,0,sizeof(reg));
		memset(vis,0,sizeof(vis));
		scanf("%d",&m);
		{
			getchar();
			for (j=0;j<m;j++)
			{
				scanf("%s",s);
				l=strlen(s);
				G[s[0]-'a'][s[l-1]-'a']++;
			    reg[s[0]-'a'][0]++;
				reg[s[l-1]-'a'][1]++;	
			}
		}
		start=s[0]-'a';
		for (i=0;i<26;i++)
		{
			if (reg[i][0] || reg[i][1])
				total++;
			if (reg[i][0]!=reg[i][1])
			{
				if (flag1>1 || flag2>1)
				{
					ok=0;
					break;
				}
				if (reg[i][0]-reg[i][1]==1)
				{
					flag1++;
					start=i;
				}
				else
				if (reg[i][0]-reg[i][1]==-1)
					flag2++;
				else
				{
				   ok=0;
				   break;
				}	
			}
		}
		if (ok)
		{
			dfs_fuck(start);
/*			printf("%d\n",start);*/
			if (max==total)
			printf("Ordering is possible.\n",max);
			else
			printf("The door cannot be opened.\n",max,total);
		}
		else
		printf("The door cannot be opened.\n");
	}
	return 0;
}
