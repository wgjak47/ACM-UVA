#include<cstdio>
#include<cstring>
char doom[50]={"the quick brown fox jumps over the lazy dog"};
char in[110][90];
char fx[100];
bool str(char s)
{
	if (s>='a' && s<='z')
		return true;
	return false;
}
bool judge(char *s)
{
	char vis[100];
	bool v[30];
	memset(v,0,sizeof(v));
	memset(vis,0,sizeof(vis));
	if (strlen(doom)!=strlen(s)) return false;
	int l=strlen(doom);
	for (int i=0;i<l;i++)
		if (str(doom[i])!=str(s[i]))
		return false;	
	for (int i=0;i<l;i++)
		if (s[i]!=' ' && ((vis[s[i]-'a']==0 && !v[doom[i]-'a']) || vis[s[i]-'a']==doom[i]))
		{
			vis[s[i]-'a']=doom[i];
			v[doom[i]-'a']=true;
		}
	for (int i=0;i<26;i++)
		if (vis[i]==0) return false;
	memcpy(fx,vis,sizeof(vis));
	return true;
}
void output(int k)
{
	for (int i=0;i<k;i++)
	{
		int l=strlen(in[i]);
		for (int j=0;j<l;j++)
			if (in[i][j]!=' ')
			putchar(fx[in[i][j]-'a']);
			else putchar(' ');
		putchar('\n');
	}	
}
main()
{
	int N;
	scanf("%d",&N);
	getchar();
	getchar();
	while (N--)
	{
		int k=0;
		memset(fx,0,sizeof(fx));
		bool find=false;
		while (gets(in[k]),strlen(in[k])!=0) k++;
		for (int i=0;i<k;i++)
			if (judge(in[i]))
			{
				find=true;
				break;
			}
		if (find) output(k);
		else printf("No solution.\n");
		if (N) putchar('\n'); 
	}
	return 0;
}
