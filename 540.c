#include<stdio.h>
#include<string.h>
int team[1000010];
struct queue
{
	int value;
	struct queue * next;
};
struct queue a[1000000];
int ans;
struct queue *location[3000];
struct queue *head;
void ENqueue(int k)
{
	int flag=0;
	struct queue *i,*pre,*new,*last;
	if (head==NULL)
	{
		head=&a[ans++];
		head->value=k;
		location[team[k]]=head;
		flag=1;
		head->next=NULL;
	}
	else 
	{
		if (location[team[k]]!=NULL)
		{
			flag=1;
			new=&a[ans++];
			new->value=k;
			new->next=location[team[k]]->next;
			location[team[k]]->next=new;
			location[team[k]]=new;
		}
	}
	if (!flag)
	{
		for (i=head;i!=NULL;i=i->next) last=i;
		new=&a[ans++];
		new->value=k;
		new->next=NULL;
		last->next=new;
		location[team[k]]=new;
	}
}
void DEqueue()
{
	printf("%d\n",head->value);
	if (location[team[head->value]]==head) location[team[head->value]]=NULL;
	head=head->next;
}
main()
{
	int N;
	int temp,i,j,k,l,m,n,reg=0;
/*	freopen("in.txt","r",stdin);*/
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		ans=0;
		printf("Scenario #%d\n",++reg);
		memset(team,0,sizeof(team));
		memset(location,0,sizeof(location));
		head=NULL;
		while (N--)
		{
			scanf("%d",&m);
			for (i=0;i<m;i++)
			{
				scanf("%d",&temp);
				team[temp]=N+1;
			}
		}
		char com[20];
		getchar();
		while (scanf("%s",com)==1)
		{
			if (com[0]=='S')
				break;
			if (com[0]=='E')
			{
				scanf("%d",&k);
				ENqueue(k);
			}
			else if (com[0]=='D')
				DEqueue();
		}
		puts("");
	}
	return 0;
}
