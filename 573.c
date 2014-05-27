#include<stdio.h>
#include<string.h>
#define AC return 0
main()
{
  double weak,k,sum,m;
  int h,u,d,f,day;
  int i,j,l,n,success;
/*  freopen("in.txt","r",stdin);*/
  while(scanf("%d%d%d%d",&h,&u,&d,&f)==4)
  {
	 if (h==0) break;
     weak=f/100.0;
	 sum=0;success=0;
	 day=0;
	 k=weak*u;
	 m=u;
	 while (sum>=0)
	 {
		 day++;
		 if (m>0)
		 sum+=m;
		 m-=k;
		 if (sum>h)
		 {
			 success=1;
			 break;
		 }
		 sum-=d;
	 }
	 if (success)
		 printf("success on day %d\n",day);
	 else 
		 printf("failure on day %d\n",day);
  }
  AC;
}

