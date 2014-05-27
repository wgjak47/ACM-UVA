#include<cstdio>
#include<cstring>
main()
{
	int N,M;
	while (scanf("%d%d",&N,&M)==2)
	{
		if (N==0) break;
		int ans=0;
		if (M==1 || N==1)
		{
			if (M==1) ans=N;
			else ans=M;
		}
		else 
		if (M==2 || N==2)
		{
			if (M==2)
			{
				if (N>=4)  ans+=N/4*4;
				if (N%4<2) ans+=(N%4)*2;
				else ans+=4;
			}
			else 
			{
				if (M>=4)  ans+=M/4*4;
				if (M%4<2) ans+=(M%4)*2;
				else ans+=4;
			}
		}
		else 
		if (N%2==0)
			ans=N/2*M;
		else
		{
			ans=N/2*M;
			if (M%2==0) ans+=M/2;	
			else ans+=M/2+1;
		}
		printf("%d knights may be placed on a %d row %d column board.\n",ans,N,M);
	}
	return 0;
}
