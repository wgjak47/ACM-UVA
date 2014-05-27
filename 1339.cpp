#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int data1[110],data2[110];
main()
{
	char s1[110],s2[110];
	int fx[30],num[30];
	while (gets(s1)!=NULL)
	{
		gets(s2);
		memset(data1,0,sizeof(data1));
		memset(data2,0,sizeof(data2));
		memset(num,0,sizeof(num));
		int l1=strlen(s1),l2=strlen(s2);
		if (l1!=l2) 
		{
			printf("NO\n");
			continue;
		}
		for (int i=0;i<l1;i++)
			num[s1[i]-'A']++;
		for (int i=0;i<26;i++)
			data1[num[i]]++;
		memset(num,0,sizeof(num));
		for (int i=0;i<l1;i++)
			num[s2[i]-'A']++;
		for (int i=0;i<26;i++)
			data2[num[i]]++;
		if (!memcmp(data1,data2,l1+1))
		printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
