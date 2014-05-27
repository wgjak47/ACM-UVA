#include<cstdio>
#include<cstring>
const int MAX = 1100;
int GN[700][MAX];
int int_strlen(int *a)
{
	int i=0;
	while (a[i]!=-1) i++;
		return i;
}
void rote(char *a)
{
	int i=0,j=strlen(a)-1;
	char c;
	while (i<j)
	{
		c=a[i];
		a[i]=a[j];
		a[j]=c;
		i++;j--;
	}
}
void big(int *des,int *a,int *b)
{
	int la=int_strlen(a);
	int lb=int_strlen(b);
	int max=lb>la?lb:la;
	for (int i=0;i<max;i++)
	{
		if (a[i]!=-1)
			des[i]+=a[i];
		if (b[i]!=-1)
			des[i]+=b[i];
		if (des[i]>=10) 
		{
			des[i]-=10;	
			des[i+1]++;
			if (i+1>=max) 
			{
				max++;	
				break;
			}
		}
	}	
	des[max]=-1;
/*	for (int i=max-1;i>=0;i--)
		printf("%d",des[i]);
	printf("  *****  %d",max);
			putchar('\n');*/
}
void pre_feb()
{
	memset(GN,0,sizeof(GN));
	GN[0][0]=1;GN[0][1]=-1;
	GN[1][0]=1;GN[1][1]=-1;
	for (int i=2;i<500;i++)
		big(GN[i],GN[i-1],GN[i-2]);
}
int int_strcmp(int *a,int *b)
{
	int la,lb;
	la=int_strlen(a);
	lb=int_strlen(b);
	int i=la;
	if (la==lb)
	{
		while (a[i]==b[i] && i>0) i--;
		return a[i]-b[i];
	}
	else return la-lb;
}
int find(char *a,bool *flag)
{
	int temp[110];
	int l=strlen(a);
	for (int i=0;i<l;i++)
		temp[i]=a[i]-'0';
	temp[l]=-1;
	for (int i=1;i<500;i++)
	{
		int m=int_strcmp(temp,GN[i]);
			if (m==0) 
			{
				*flag=true;
				return i;
			}
			else  if (m<0)
			return i;
	}
}
main()
{
	char first[MAX];
	char second[MAX];
	int lf,ls;
	int temp[110];
	pre_feb();
	while (scanf("%s%s",first,second)!=EOF)
	{
		if (first[0]==second[0] && first[0]=='0') break;
		rote(first);
		rote(second);
		if (strcmp(first,second)!=0)
		{
			bool flag1=false;
			bool flag2=false;
			int result=find(second,&flag1)-find(first,&flag2);
			if (flag1) result++;
			printf("%d\n",result);
		}
		else 
		{
			int l=strlen(first);
			for (int i=0;i<l;i++)
				temp[i]=first[i]-'0';
			temp[l]=-1;
			bool yes=false;
			for (int i=1;i<500;i++)
			{
				int l=int_strcmp(temp,GN[i]);
				if (l==0)	
				{yes=true;break;}
				else if (l<0) break;
			}
			if (yes) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
