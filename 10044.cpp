#include<cstdio>
#include<cstring>
#define INF 10000000
char s[5010][1010];
int G[5010][5010];
int d[5010];
int first[5010],next[10010000];
int total;
int hash(char *temp)
{
	int a=0;
	int l=strlen(temp);
	for (int i=0;i<l;i++)
	{
		a=a*2+temp[i];
		a%=5000;
	}
	return a;
}
int insert(char *temp,bool check)
{
	int h=hash(temp);
	for (int i=first[h];i!=-1;i=next[i])
	{
		if (!strcmp(s[i],temp)) 
			return i;
	}
	if (check) return -1;
	strcpy(s[total],temp);
	next[total]=first[h];
	first[h]=total;
	total++;		
	return total-1;
}
void init(char *ace)
{
	int l=strlen(ace);	
	int last=0;
	char temp[5010];
	int k[5010];
	memset(k,0,sizeof(k));
	int reg=0;
	for (int i=1;i<l;i++)
		if ((ace[i]==',' || ace[i]==':') && ace[i-1]=='.')
		{
			int j=0;
			for (int q=last;q<i;q++)
				temp[j++]=ace[q];
			temp[j]='\0';
			k[reg++]=insert(temp,0);	
			if (ace[i]==':')  
				break;
			i+=2;
			last=i;
		}
	for (int i=0;i<reg;i++)
	for (int j=0;j<reg;j++)
	if (i!=j)
	{
		G[k[i]][k[j]]=1;
		G[k[j]][k[i]]=1;
	}		
}
void search (int key)
{
	for (int i=0;i<total;i++)
		G[i][i]=0;
	for (int i=0;i<total;i++)
	for (int j=0;j<total;j++)
		if (G[i][j]==-1) G[i][j]=INF;
	bool v[5010];
	memset(v,0,sizeof(v));
	for (int i=0;i<total;i++) d[i]=INF;
		d[key]=0;
	for (int i=0;i<total;i++)
	{
		int x,m=INF;
		for (int y=0;y<total;y++) if (!v[y] && d[y]<=m) m=d[x=y];	
		v[x]=true;
		for (int y=0;y<total;y++) 
			if (d[y]>d[x]+G[x][y]) d[y]=d[x]+G[x][y];
	}
	return ;
}
main()
{
	int T;
	int M,N;
	scanf("%d",&T);
	int cases=0;
	while (T--)
	{
		total=0;
		memset(first,-1,sizeof(first));
		scanf("%d%d",&M,&N);
		char ace[10100];
		memset(G,-1,sizeof(G));
		getchar();
		for (int i=0;i<M;i++)
		{
			gets(ace);	
			init(ace);
		}
		char in[10100];
		int key=-1;
		for (int i=0;i<total;i++)
			if (!strcmp(s[i],"Erdos, P.")) key=i;
		if (key!=-1)
		search(key);
		printf("Scenario %d\n",++cases);
		for (int j=0;j<N;j++)
		{
			gets(in);
			int h=insert(in,1);
			printf("%s",in);
			if (h!=-1 && d[h]<1000000) printf(" %d\n",d[h]);
			else printf(" infinity\n");	
		}
	}
	return 0;
}
