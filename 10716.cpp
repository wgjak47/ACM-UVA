#include<cstdio>
#include<cstring>
#include<cstdlib>
char s[110];
int move(int i,int j)
{
	char temp;	
	if (i<j) 
	{
		int l=j;
		while (l>i)
		{
			temp=s[l];
			s[l]=s[l-1];
			s[l-1]=temp;
			l--;
		}
	}
	else 
	{
		int l=j;
		while (l<i)
		{
			temp=s[l];
			s[l]=s[l+1];
			s[l+1]=temp;
			l++;
		}
	}
	return abs(i-j);
}
main()
{
	int N;
	scanf("%d",&N);
	getchar();
	while (N--)
	{
		int ans=0;
		int t[30];
		memset(t,0,sizeof(t));
		scanf("%s",s);
		int l=strlen(s);	
		for (int i=0;i<l;i++)
			t[s[i]-'a']++;
		int sum=0;
		for (int i=0;i<26;i++)
			if (t[i]%2) sum++;
		if (sum>1) {
		printf("Impossible\n");
		continue;
		}
		int left=0,right=l-1;
		while (left<right)
		{
			if (s[left]==s[right]);
			else 
			{
				for (int i=right;i>=left;i--)
					if (s[i]==s[left] && left!=i)
					{
						ans+=move(right,i);
						break;
					}
					else if (i==left)
					{
						ans+=l/2-left;
						right++;
					}
			}
			left++;right--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
