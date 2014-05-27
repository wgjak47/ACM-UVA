#include<cstdio>
#include<cstring>
#include<cstdlib>
char s[100];
char word[1010][20];
char dict[1000][20];
char fx[30];
bool vis[30];
int first[1010],next[10010];
int z;
bool outs;
int start[100],end[100];
int cmp(const void *a,const void *b)
{
	return strlen((char *)a)-strlen((char *)b);
}
int hash(int z)
{
	int l=strlen(dict[z]);
	int sum=0;
	for (int i=0;i<l;i++)
	{
		sum=sum*2+s[i];
		sum%=1000;
	}
	return sum;
}
bool find(int z)
{
	int h=hash(z);
	for (int i=first[h];i!=-1;i=next[i])
		if (!strcmp(dict[z],dict[i]))
			return false;
	next[z]=first[h];
	first[h]=z;
	return true;
}
bool igets()
{
	z=0;
	if (gets(s)==NULL) return false;
	memset(first,-1,sizeof(first));
	int l=strlen(s);
	int st=0;
	while (s[st]==' ') st++;
	while (s[l-1]==' ') l--;
	int k=0;
	for (int i=st;i<l;i++)
	{
		if (s[i]>='a' && s[i]<='z')
			dict[z][k++]=s[i],dict[z][k]='\0';
		else if (s[i]==' ')
			{
				while (s[i]==' ') i++;
				i--;
				if (find(z)) z++;
				k=0;
			}	
	}
	return true;
}
void outputs()
{
	int l=strlen(s);
	for (int i=0;i<l;i++)
		if (s[i]>='a' && s[i]<='z')
			putchar(fx[s[i]-'a']);
		else putchar(' ');
	putchar('\n');
}
bool com(int k,int t)
{
	char temp[30];
	bool tev[30];
	memcpy(temp,fx,sizeof(fx));
	memcpy(tev,vis,sizeof(tev));
	int l=strlen(dict[t]);
	for (int i=0;i<l;i++)
	if ((!vis[word[k][i]-'a'] && fx[dict[t][i]-'a']==0) || fx[dict[t][i]-'a']==word[k][i])
		fx[dict[t][i]-'a']=word[k][i],vis[word[k][i]-'a']=true;	
	else 
	{
		memcpy(fx,temp,sizeof(fx));
		memcpy(vis,tev,sizeof(vis));
		return false;
	}
	return true;
}
void dfs(int d)
{
	if (d==z+1)
	{
		outputs();
		outs=true;
		return ;
	}	
	else 
	{
		char temp[30];
		bool tev[30];
		int l=strlen(dict[d]);
		if (start[l]==-1) 
			return ;
		memcpy(temp,fx,sizeof(fx));
		memcpy(tev,vis,sizeof(tev));
		for (int i=start[l];i<=end[l];i++)
		{
			if (!outs && com(i,d))
			{
			dfs(d+1);
			memcpy(fx,temp,sizeof(fx));
			memcpy(vis,tev,sizeof(tev));
			}
		}
	}
}
main()
{
	int N;
	scanf("%d",&N);
	getchar();
	memset(start,-1,sizeof(start));
	memset(end,-1,sizeof(end));
	for (int i=0;i<N;i++)
		scanf("%s",word[i]);
	qsort(word,N,sizeof(word[0]),cmp);
	for (int i=0;i<N;i++)
	{
		int l=strlen(word[i]);
		if (start[l]==-1)  start[l]=i;
		end[l]=i;
	}
	getchar();
	while (igets())
	{
		memset(vis,0,sizeof(vis));
		memset(fx,0,sizeof(fx));
		outs=false;
		dfs(0);
		if (!outs)
		{
			int l=strlen(s);
			for (int i=0;i<l;i++)
				if (s[i]>='a' && s[i]<='z')
					putchar('*');
				else putchar(' ');
			putchar('\n');
		}
	}
	return 0;
}
