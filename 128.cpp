#include<cstdio>
#include<cstring>
#define MOD 34943
main()
{
	char s[1025];
	while (gets(s)!=NULL)
	{
		if (s[0]=='#') break;
		int l=strlen(s);
		long long ans=0;
		for (int i=0;i<l;i++)
			ans=((ans<<8)+s[i])%MOD;
		ans=(ans<<16)%MOD;
		ans=MOD-ans;
		ans%=MOD;
		//printf("%lld\n",ans);
		long long ans1=ans,ans2;
		ans1=ans1>>8;
		ans2=ans-(ans1<<8);
		sprintf(s,"%.2llx %.2llx",ans1,ans2);
		for (int i=0;i<strlen(s);i++)
			if (s[i]>='a' && s[i]<='z') s[i]=s[i]-'a'+'A';
		puts(s);
	}
	return 0;
}
