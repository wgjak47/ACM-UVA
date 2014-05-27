#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[10000];
int m[10000],sum[10000],temp[10000]={0};
main()
{
	int i,a,j,k,l,n,num,c;int sum_length,sm;
/*	freopen("in.txt","r",stdin);*/
   while(scanf("%s %d",s,&n)==2)
   {
	  j=0;memset(sum,0,sizeof(sum));
      l=strlen(s);memset(m,0,sizeof(m));
	  for (i=l-1;i>=0;i--)
	  if (isdigit(s[i]))
		m[j++]=s[i]-'0';
	  else num=i;j--;
	  for (i=0;i<=j;i++)
	  sum[i]=m[i];
	  sum_length=l;
	  for (i=1;i<n;i++)
	  {
		  for (j=0;j<l;j++)
		  for (k=0;k<sum_length;k++)
		  {
			temp[k+j]+=m[j]*sum[k];
			if (temp[k+j]>=10)
			{
				temp[k+j+1]+=temp[k+j]/10;
				temp[k+j]=temp[k+j]%10;
			}
		  }
		  sum_length=l+sum_length;
		  memcpy(sum,temp,sizeof(temp));
		  memset(temp,0,sizeof(temp));
	  }
	  a=sum_length+l;
	  num=(l-1-num)*n;
	  while(sum[a]==0 && a>0) a--;
	  if (num<=a)
	  {
	  sm=0;while(sum[sm]==0 && sm<num) sm++;
	  for (i=a;i>=sm;i--)
	  {
	  if (i==num-1) printf(".");
      printf("%d",sum[i]); 
	  }
	  if (sm==num) printf(".");
	  }
	  else 
	  {
	      sm=0;while(sum[sm]==0 && sm<=a) sm++;
		  printf(".");
		  for (i=1;i<num-a;i++)
			  printf("0");
		  for (i=a;i>=sm;i--)
			  printf("%d",sum[i]);
	  }
	  putchar ('\n');
   }
   return 0;
}

