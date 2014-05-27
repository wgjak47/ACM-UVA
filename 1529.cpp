#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
main()
{
	int h,m,hh,mm;
	puts("Program 3 by team X");
	puts("Initial time  Final time  Passes");
	while (scanf("%d%d%d%d",&h,&m,&hh,&mm)==4)
	{
		int	ans=0;
		int sh=h,sm=m;
		int hm=(h*5)%60+m/12;
		while (h!=hh || m!=mm)
		{
			m++;
			if (m%12==0) hm++;
			if (hm==60) hm=0;
			if (m==60) h++,m=0;
			if (h==13) h=1,hm=5;
			if (m==hm && m!=59) 
			{	
				ans++;
			//	printf("%d %d\n",m,hm);
			//	printf("%d %d\n",h,m);
			//	puts("**********");
			}
		}
		pf(i,0,7) putchar(' ');
		printf("%.2d:%.2d",sh,sm);
		pf(i,0,7) putchar(' ');
		printf("%.2d:%.2d",hh,mm);
		printf("%8d\n",ans);
	}
	puts("End of program 3 by team X");
	return 0;
}
