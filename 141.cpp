#include<cstdio>
#include<cstring>
bool G[52][52];
bool Gs[120][1260];
bool temp[1260];
int head[101100],next[120000];
int N;
int hash(bool *S)
{
	int sum=0;
	for (int i=0;i<N*N;i++)
		if (S[i]==true)
			sum+=i;
	return sum%10000;
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
bool find()
{
	int i,h=hash(temp);
	int t=0;
	for (i=head[h];i!=-1;i=next[i])
	{
		t=0;
		for (int j=0;j<N*N;j++)
			if (Gs[i][j]!=temp[j])
			{
				t=1;break;
			}
		if (t==0) return true;
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
	if (find()) return true;
	memset(temp,false,sizeof(temp));
	for (int i=0;i<N;i++)
	for (int j=0;j<N;j++)
		if (G[i][j])
			temp[j*N+(N-i-1)]=true;
	if (find()) return true;
	memset(temp,false,sizeof(temp));
	for (int i=0;i<N;i++)
	for (int j=0;j<N;j++)
		if (G[i][j])
			temp[(N-j-1)*N+i]=true;
	if (find()) return true;
	memset(temp,false,sizeof(temp));
	for (int i=0;i<N;i++)
	for (int j=0;j<N;j++)
		if (G[i][j])
			temp[(N-i-1)*N+(N-j-1)]=true;
	if (find()) return true;
	return false;
}
int main()
{
	char c;
	int x,y;
	bool draw;
	bool win;
	while (scanf("%d",&N),N!=0)
	{
		draw=true;
		win=false;
		memset(head,-1,sizeof(head));
		memset(G,false,sizeof(G));
		memset(Gs,false,sizeof(Gs));
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
				else {printf("Player %d wins on move %d\n",(i+1)%2+1,i+1);win=true;draw=false;}
		 	}
			else if (c=='-')
		 	{
				G[x][y]=false;
				if (!judge())
					insert(i);
				else {printf("Player %d wins on move %d\n",(i+1)%2+1,i+1);win=true;draw=false;}
			}
			}
		} 
		if (draw) printf("Draw\n");
	}
	return 0;
}
