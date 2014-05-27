#include<iostream>
#include<cstdio>
#include<cstring>
char s1[110][35];
char s2[110][35];
int dp[110][110];
int r[110][110];		
int l1,l2;
bool init()
{
	l1=0;
	l2=0;
	int flag1=1,flag2=1;
	while (flag1=scanf("%s",s1[l1]),s1[l1++][0]!='#');
	while (flag2=scanf("%s",s2[l2]),s2[l2++][0]!='#');
	l1--;
	l2--;
	if (flag1==-1 || flag2==-1)
	return false;
	return true;
}
main()
{
	while (init())
	{
		memset(dp,0,sizeof(dp));	
		memset(r,0,sizeof(r));
		for (int i=l1-1;i>=0;i--)
		for (int j=l2-1;j>=0;j--)
		if (!strcmp(s1[i],s2[j]))
		{
			dp[i][j]=dp[i+1][j+1]+1;
			r[i][j]=3;
		}
		else if (dp[i+1][j]>dp[i][j+1])
		{
			dp[i][j]=dp[i+1][j];
			r[i][j]=2;
		}
		else 
		{
			dp[i][j]=dp[i][j+1];
			r[i][j]=1;
		}
		int k=0,l=0;
		int reg=0;
	//	printf("%d\n",dp[0][0]);
		while (r[k][l]!=0)
		{
			if (r[k][l]==3)
			{
				if (reg++) putchar(' ');
			   	printf("%s",s1[k]);	
			}
			switch(r[k][l])
			{
				case 3:k++,l++;break;
				case 2:k++;break;
				case 1:l++;break;		   
			}
		}
		putchar('\n');
	}
	return 0;
}

