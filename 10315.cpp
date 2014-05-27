#include<cstdio>
#include<cstring>
#include<cstdlib>
char p1[7][4];
char p2[7][4];
int convert(char c)
{
	if (c>='0' && c<='9') return c-'0';
	else if (c=='T') return 10;
	else if (c=='J') return 11;
	else if (c=='Q') return 12;
	else if (c=='K') return 13;
	else if (c=='A') return 14;
}
int cmp(const void *a,const void *b)
{
	char *x=(char *)a;
	char *y=(char *)b;
	return convert(x[0])-convert(y[0]);
}
bool THS(char p[][4])
{
	for (int i=1;i<5;i++)
		if (p[i][1]!=p[i-1][1] || convert(p[i][0])!=convert(p[i-1][0])+1)
			return false;
	return true;
}
bool four(char p[][4])
{
	if (p[1][0]==p[0][0] && p[1][0]==p[2][0] && p[1][0]==p[3][0]) return true;
	if (p[1][0]==p[0][0] && p[1][0]==p[2][0] && p[1][0]==p[3][0]) return true;
	return false;
}
bool hulu(char p[][4])
{
	if (p[1][0]==p[0][0] && p[1][0]==p[2][0] && p[4][0]==p[3][0])
		return true;
	if (p[2][0]==p[3][0] && p[2][0]==p[4][0] && p[1][0]==p[0][0])
		return true;
	return false;
}
bool tonghua(char p[][4])
{
	for (int i=1;i<5;i++)
		if (p[i][1]!=p[i-1][1])	
			return false;
	return true;
}
bool shunzi(char p[][4])
{
	for (int i=1;i<5;i++)
		if (convert(p[i][0])!=convert(p[i-1][0])+1)
			return false;
	return true;
}
bool three(char p[][4])
{
	if (p[0][0]==p[1][0] && p[0][0]==p[2][0])
		return true;
	if (p[4][0]==p[3][0] && p[4][0]==p[2][0])
		return true;	
	if (p[1][0]==p[2][0] && p[2][0]==p[3][0])
		return true;
	return false;
}
bool tow(char p[][4])
{
	if (p[0][0]==p[1][0] && p[2][0]==p[3][0]) return true;	
	if (p[0][0]==p[1][0] && p[4][0]==p[3][0]) return true;	
	if (p[2][0]==p[1][0] && p[4][0]==p[3][0]) return true;	
	return false;
}
bool one(char p[][4])
{
	if (p[0][0]==p[1][0] || p[2][0]==p[1][0] || p[2][0]==p[3][0] || p[3][0]==p[4][0])
		return true;
	return false;
}
void judge(char p[][4],int *max,int & key)
{
	if (THS(p)) 
	{
		key=8;
		int k=0;
		for (int i=4;i>=0;i--)
			max[k++]=convert(p[i][0]);
	}    
	else if (four(p))
	{
		key=7;
		int k=0;
		int z;
	    z=convert(p[3][0]);
		for (int i=4;i>=0;i--)
			max[k++]=z;
	} 
	else if (hulu(p))
	{ 
		key=6;
		int k=0;
		for (int i=4;i>=0;i--)
			max[k++]=convert(p[2][0]);
	}
	else if (tonghua(p))
	{
		key=5;
		int k=0;
		for (int i=4;i>=0;i--)
			max[k++]=convert(p[i][0]);
	} 
	else if (shunzi(p))
	{ 
		key=4;
		int k=0;
		for (int i=4;i>=0;i--)
			max[k++]=convert(p[i][0]);
	}
	else if (three(p))
	{
		key=3;
		int z=convert(p[2][0]);
		for (int i=0;i<5;i++)
			max[i]=z;			
	}
	else if (tow(p))
	{
		key=2;
		int k=0;
		int k1=0,k2=0;
		for (int i=1;i<5;i++)
			if (p[i][0]==p[i-1][0])	
				if (0==k1)
				k1=convert(p[i][0]);
				else k2=convert(p[i][0]);
		if (k1>k2)
		{
			k=k1;
			k1=k2;
			k2=k;
		}
		for (int i=0;i<2;i++)
			max[i]=k2;
		for (int i=2;i<4;i++)
			max[i]=k1;
		for (int i=0;i<5;i++)
			if (k1!=convert(p[i][0]) && k2!=convert(p[i][0]))
				max[4]=convert(p[i][0]);
	} 
	else if (one(p))
	{
		int k=2;
		int z=0;
		key=1;
		for (int i=1;i<5;i++)
			if (p[i][0]==p[i-1][0])	z=convert(p[i][0]);
		for (int i=4;i>=0;i--)
			if (z!=convert(p[i][0]))
				max[k++]=convert(p[i][0]);
		max[0]=max[1]=z;
		k=0;
	}	
	else 
	{
		int k=0;
		for (int i=4;i>=0;i--)
			max[k++]=convert(p[i][0]);
	}
}
int init()
{
	int max1[10];
	int max2[10];
	memset(max1,0,sizeof(max1));
	memset(max2,0,sizeof(max2));
	int key1=0,key2=0;
	for (int i=0;i<5;i++)
		if (scanf("%s",p1[i])==EOF)
			return 10;
	for (int i=0;i<5;i++)
		if (scanf("%s",p2[i])==EOF)
			return 10;
	qsort(p1,5,sizeof(p1[0]),cmp);
	qsort(p2,5,sizeof(p2[0]),cmp);
	judge(p1,max1,key1);	
	judge(p2,max2,key2);
//	printf("%d %d\n",key1,key2);
	if (key1==key2)
	{
		for (int i=0;i<5;i++)
			if (max1[i]!=max2[i])
				return max1[i]-max2[i]>0?1:-1;
		return 0;
	}
	return key1-key2>0?1:-1;
}
main()
{
	int reg=0;
	while (1)
	{
//		printf("Case :%d\n",++reg);
		int c=init();
		if (c==10) break;
		else if (c==0) printf("Tie.\n");
		else if (c==1) printf("Black wins.\n");
		else if (c==-1) printf("White wins.\n");
	}
	return 0;
}
