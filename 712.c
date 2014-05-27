#include<stdio.h>
#include<string.h>
main()
{
	int a[10],b[1000];
	int i,j,k,l,m,n,number=0;;
	char c,x,p;
	int start,end,reg;
    char s[1000];
/*	freopen("in.txt","r",stdin);*/
	while (scanf("%d",&n)==1)
	{		
		if (n==0) break;
		printf("S-Tree #%d:\n",++number);
		getchar();
		for (i=0;i<n;i++)
		scanf("%c%d%c",&c,&a[i],&p);
		gets(s);
		scanf("%d",&m);
		getchar();
		for (j=0;j<m;j++)
		{
			for (i=0;i<n;i++)
			{
				c=getchar();
				b[i]=c-'0';
 			}
			start=0;end=strlen(s);
			reg=0;
			while (end-start!=1)
	 		{
				switch(b[a[reg]-1])
	 			{
					case 1:start+=(end-start)/2;break;
					case 0:end-=(end-start)/2;break;
				}
				reg++;
			}
			if (b[a[reg-1]]==0)
			putchar(s[start]);
			else putchar(s[end-1]);
			getchar();
 		}
			printf("\n\n");
	}
    return 0;
}
