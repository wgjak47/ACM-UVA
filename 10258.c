#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct contest
{
	int number,times;
	int solved;
	int part;
};
int cmp(const void *a,const void *b)
{
	int part1=((struct contest *)a)->part;
	int part2=((struct contest *)b)->part;
	if (part1>part2) return -1;
	if (part2>part1) return 1;
	int s1=((struct contest *)a)->solved;
	int s2=((struct contest *)b)->solved;
	if (s1!=s2) return (s2>s1);
	int t1=((struct contest *)a)->times;
	int t2=((struct contest *)b)->times;
	if (t1!=t2) return (t1>t2);
	int number1=((struct contest *)a)->number;
	int number2=((struct contest *)b)->number;
	return (number1>number2);
	return 0;
}
struct contest s[110]; 
main()
{
	int member;
	int solve[110][11];
	int time,question;
	char c;
	char temp,temp1;
	int total;
	int i;
	int n;
	scanf("%d",&total);
	c=getchar();
	c=getchar();
	while (total--)
	{
		n=0;
		memset(solve,0,sizeof(solve));
		for (i=0;i<110;i++)
		{s[i].solved=0;s[i].number=i;s[i].times=0;s[i].part=0;}
		while ((temp=getchar())!=EOF)
		{
			if (temp!='\n')
			{
				ungetc(temp,stdin);
	    	    scanf("%d%d%d%c%c",&member,&question,&time,&temp1,&c);
				getchar();
			}
			else break;
			if (c=='C') 
			{
				s[member].part=1;
				if (solve[member][question]!=-1)
				{
					s[member].solved++;
					s[member].times+=time+20*solve[member][question];
					solve[member][question]=-1;
				}
			}
			else if (c=='I')
			{
				s[member].part=1;
				if (solve[member][question]!=-1)
				solve[member][question]++;
			}
			else if (c=='R' || c=='U' || c=='E')
			{
				s[member].part=1;
			}
		} 
		qsort(s,101,sizeof(struct contest),cmp);
		int j=-1;
		while (s[++j].part)
		printf("%d %d %d\n",s[j].number,s[j].solved,s[j].times);
		if (total) putchar('\n');
	}
	return 0;
}
