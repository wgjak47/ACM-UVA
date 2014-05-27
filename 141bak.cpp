#include<cstdio>
#include<cstring>
bool G[52][52];
bool Gs[120][1260];
bool temp[1260];
int head[1011],next[1200];
int N;
int hash(bool *S)
{
	int sum=0;
	for (int i=0;i<N*N;i++)
		if (S[i])
		sum=sum+i*2;
	return sum%200;
}
void insert(int i)
{
	for (int j=0;j<N;j++)
	for (int k=0;k<N;k++)
	if (G[j][k])	
	Gs[i][j*N+k]=true;
	int h=hash(Gs[i]);
	next[i]=head[h];
	head[h]=i;
}
bool find(bool *S)
{
	int i,h=hash(S);
	for (i=head[h];i!=-1;i=next[i])
	if (!memcmp(S,Gs[i],sizeof(bool)*N*N))
	{
	for (int k=0;k<N;k++)
	{
		for (int j=0;j<N;j++)
		if (S[k*N+j]) printf("#");
		else printf(".");
		putchar('\n');
	}
	puts("--------");
	for (int k=0;k<N;k++)
	{
		for (int j=0;j<N;j++)
		if (Gs[i][k*N+j]) printf("#");
		else printf(".");
		putchar('\n');
	}
	puts("--------");
		return true;
	}
	return false;
}
bool judge()
{
	memset(temp,false,sizeof(temp));
	for (int i=0;i<N;i++)
	for (int j=0;j<N;j++)
		if (G[i][j])
			temp[i*N+j]=true;
	if (find(temp)) return true;
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		if (temp[i*N+j]) printf("#");
		else printf(".");
		putchar('\n');
	}
	puts("--------");
	memset(temp,false,sizeof(temp));
	for (int i=0;i<N;i++)
	for (int j=0;j<N;j++)
		if (G[i][j])
		temp[j*N+(N-i-1)]=true;
	if (find(temp)) return true;
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		if (temp[i*N+j]) printf("#");
		else printf(".");
		putchar('\n');
	}
	puts("--------");
	memset(temp,false,sizeof(temp));
	for (int i=0;i<N;i++)
	for (int j=0;j<N;j++)
		if (G[i][j])
			temp[(N-j-1)*N+i]=true;
	if (find(temp)) return true;
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		if (temp[i*N+j]) printf("#");
		else printf(".");
		putchar('\n');
	}
	puts("--------");
	memset(temp,false,sizeof(temp));
	for (int i=0;i<N;i++)
	for (int j=0;j<N;j++)
		if (G[i][j])
			temp[(N-i-1)*N+(N-j-1)]=true;
	if (find(temp)) return true;
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		if (temp[i*N+j]) printf("#");
		else printf(".");
		putchar('\n');
	}
	puts("--------");
	puts("judge end");
	return false;
}
main()
{
	char c;
	int x,y;
	while (scanf("%d",&N),N!=0)
	{
		memset(head,-1,sizeof(head));
		bool draw=true;
		bool win=false;
		memset(G,false,sizeof(G));
		for (int i=0;i<2*N;i++)
		{	
			scanf("%d%d %c",&x,&y,&c);
			x--;y--;
			if (!win)
			{
			if (c=='+')
			{
				G[x][y]=true;
				if (!judge())
					insert(i);
				else {printf("Player %d wins on move %d\n",i%2==0?2:1,i+1);win=true;draw=false;}
		 	}
			else if (c=='-')
		 	{
				G[x][y]=false;
				if (!judge())
					insert(i);
				else {printf("Player %d wins on move %d\n",i%2==0?2:1,i+1);win=true;draw=false;}
			}
			}
		} 
		if (draw) printf("Draw\n");
	}
	return 0;
}
