#include<stdio.h>
#include<string.h>
main()
{
	int i,j,k,temp,x;
	int now,next,m;
	while (scanf("%d%d%d",&i,&j,&k)!=EOF)
	{
		x=0;
		temp=j;
		now=0;next=0;
	    while (1)
		{
			m=temp*k+next;
			now=m%i;
			next=m/i;
			temp=now;
			x++;
			if (next==0 && now==j) break;
		}
		printf("%d\n",x);
	}
	return 0;
}	
