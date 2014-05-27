#include<stdio.h>
#include<string.h>
void my_gets(char *a)
{
    char c;
	int i=0;
	while ((c=getchar()),c!='#' && c!='\n')
		a[i++]=c;
	a[i]='\0';
}
typedef struct team
{
	char teamname[200];
	int tp,tpe,gp,win,ties,loss,gd,gs,ga;
};
team teams[1001];
void fuck(int g1,int g2,int t1,int t2)
{
   teams[t1].gp+=1;
   teams[t2].gp+=1;
   teams[t1].gs+=g1;
   teams[t1].ga+=g2;
   teams[t2].gs+=g2;
   teams[t2].ga+=g1;
   if (g1>g2) {teams[t1].tpe+=3;teams[t1].win++;teams[t2].loss++;}
   if (g1==g2) {teams[t1].tpe+=1;teams[t2].tpe+=1;teams[t1].ties++;teams[t2].ties++;}
   if (g1<g2) {teams[t2].tpe+=3,teams[t2].win++;teams[t1].loss++;}
}
int cmp(const void *a,const void *b)
{
   team *t1,*t2;
   t1=(team *)a;
   t2=(team *)b;
   if (t1->tpe!=t2->tpe) 
	   return (t1->tpe)-(t2->tpe);/*score*/
   else if (t1->win!=t2->win)
	   return (t1->win)-(t2->win);/*win*/
   else if (((t1->gs)-(t1->ga))!=((t2->gs)-(t2->ga)))
	   return (t1->gs-t1->ga)-(t2->gs-t2->ga); 
   else if (t1->gs!=t2->gs)
	   return (t1->gs)-(t2->gs);
   else if (t1->gp!=t2->gp)
	   return (t2->gp)-(t1->gp);
   else return strcasecmp(t2->teamname,t1->teamname);
}
main()
{
/*	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);*/
	int g1,g2,t1,t2;
	int i,j,ks,k,l,m,n,all;
    char title[120];
	char s1[200],s2[200];
	scanf("%d",&all);
	getchar();
	for (ks=0;ks<all;ks++)
	{
	if (ks!=0) putchar ('\n');
	for (i=0;i<=1000;i++)
	{
		teams[i].tp=0;
		teams[i].tpe=0;
		teams[i].gp=0;
		teams[i].win=0;
		teams[i].ties=0;
		teams[i].loss=0;
		teams[i].gd=0;
		teams[i].gs=0;
		teams[i].ga=0;
		memset(teams[i].teamname,0,sizeof(teams[i].teamname));
	}
		gets(title);
	    scanf("%d",&n);
		getchar();
		puts(title);
		for (i=0;i<n;i++)
		gets(teams[i].teamname);
		scanf("%d",&m);	
		getchar();
		for (i=0;i<m;i++)
		{
			my_gets(s1);
			scanf("%d@%d",&g1,&g2);
			getchar();
			my_gets(s2);
			for (j=0;j<n;j++)
				if (!strcmp(s1,teams[j].teamname))
				{t1=j;break;}
			for (j=0;j<n;j++)
				if (!strcmp(s2,teams[j].teamname))
				{t2=j;break;}
			fuck(g1,g2,t1,t2);
		}
	 qsort(teams,n,sizeof(team),cmp);
	 for (i=n-1;i>=0;i--)
	 printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",n-i,teams[i].teamname,teams[i].tpe,teams[i].gp,teams[i].win,teams[i].ties,teams[i].loss,teams[i].gs-teams[i].ga,teams[i].gs,teams[i].ga);
	}
	return 0;
}
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
/*fuck fuck fuck you you you you you*/
