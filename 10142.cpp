#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
int vote[1001][21];
int number;
char name[21][100];
int max(int *a,bool *b,int *maxlt)
{
	int max=0;
	for (int i=1;i<=number;i++)
		if (b[i] && a[i]>max) {max=a[i];*maxlt=i;}
	return max;
}
int min(int *a,bool *b)
{
	int min=1001;
	for (int i=1;i<=number;i++)
		if (b[i] && a[i]<min) min=a[i];
	return min;
}
void fuck(int k)
{
	int point[1001];
	int member[21];
	bool lose[21];
	memset(point,0,sizeof(point));
	memset(member,0,sizeof(member));
	memset(lose,true,sizeof(lose));
	int maxlt,maxv,minv;
	while (1)
	{
		for (int i=0;i<k;i++)
		{
			while (!lose[vote[i][point[i]]])
				point[i]++;
			member[vote[i][point[i]]]++;
		}
		if ((maxv=max(member,lose,&maxlt))==(minv=min(member,lose)))
		{
			for (int i=1;i<=number;i++)
				if (lose[i]) cout<<name[i]<<endl;
			return ;
		}
		else if (maxv*2>k)
		{
			cout<<name[maxlt]<<endl;
			return ;
		}
		else 
		{
			for (int i=1;i<=number;i++)
				if (lose[i] && minv==member[i]) lose[i]=false;
		}
		memset(member,0,sizeof(member));
	}
}
main()
{
	char temp[10];
	int total;
	char c;
	//freopen("data.txt","r",stdin);
	cin>>total;
	getchar();
	getchar();
	while (total--)
	{ 
		cin>>number;
		getchar();
		for (int i=1;i<=number;i++)
		{
			gets(name[i]);
		}
		int k=0;
		while ((c=getchar())!=EOF)
		{
			if (isdigit(c))
			{
				ungetc(c,stdin);
				for (int i=0;i<number;i++)
					scanf("%d",&vote[k][i]);
				k++;
				getchar();
	 		}
			else if (c=='\n') 
				break;
	 	}
		fuck(k);
		if (total) cout<<endl;
	} 
	return 0;
}

