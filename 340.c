#include<stdio.h>
#include<string.h>
int a[11];
int judge1(int s[],int m[],int n)
{
	int i=0,reg=0;
	while (i<n)
	{
		if (s[i]==m[i]) reg++;
		i++;
	}
    return reg;
}
int judge2(int m[],int n)
{
	int i,reg=0;;
	int b[10]={0};
	for (i=0;i<n;i++)
		b[m[i]]++;
	for (i=0;i<10;i++)
	{
		if (b[i]<=a[i]) reg+=b[i];
		else reg+=a[i];
	}
	return reg;
}
main()
{
	int s[1010],m[1010];
	int i,j,k=0,l,n,h;
/*	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);*/
	while (scanf("%d",&n)==1)
	{
      if (n==0) break;
      memset(a,0,sizeof(a));
	  for (i=0;i<n;i++)
		  scanf("%d",&s[i]);
	   for (i=0;i<n;i++) a[s[i]]++;
		  printf("Game %d:\n",++k);
	  while (1)
	  {
		  for (i=0;i<n;i++)
			  scanf("%d",&m[i]);
		  if (m[0]==0) break;
		  h=judge1(s,m,n);
		  printf("    (%d,%d)\n",h,judge2(m,n)-h);
	  }
	}
	return 0;


}
