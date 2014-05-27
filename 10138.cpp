//细节较多，主要是题目描述不清
//注意忽略掉不成对的“上”一
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define enter true
#define exit false
int payment[26];
struct photo
{
	char name[30];
	int month,day;
	int time;
	int fee;
	bool state;
	int miles;
	bool visit;
};
struct car
{
	char name[30];
	int money;
};
photo input[1010];
car output[510];
int check(char *s,int l)
{
	for (int i=0;i<l;i++)
		if (strcmp(s,output[i].name)==0)
			return i;
	return -1;
}
int cmpo(const car &a,const car &b)
{
	if (strcmp(a.name,b.name)<0) return 1;
	return 0;
}
int cmp(const photo &a,const photo &b)
{
	if (strcmp(a.name,b.name)!=0)
		return strcmp(a.name,b.name)<0?1:0;
	if (a.month!=b.month)
		return a.month<b.month;
	else if (a.day!=b.day)
		return a.day<b.day;
	return a.time<b.time;
}
main()
{
	int T;
	char s[1000];
	scanf("%d",&T);
	getchar();
	getchar();
	while (T--)
	{	
		for (int i=0;i<24;i++)	
			scanf("%d",&payment[i]);
		getchar();
		int k=0;
		int mo,dd,hh,mm;
		char stu[10];
		while (fgets(s,1000,stdin)!=NULL)
		{ 
			if (s[0]=='\n') break;
			sscanf(s,"%s %d:%d:%d:%d %s %d",input[k].name,&input[k].month,&input[k].day,&hh,&mm,stu,&input[k].miles);
			input[k].fee=payment[hh];
			input[k].time=hh*60+mm;
			if (stu[1]=='n') 
				input[k].state=enter;
			else if (stu[1]=='x')
				input[k].state=exit;
			input[k].visit=false;
			k++;
		}
		sort(input,input+k,cmp);
	/*	for (int i=0;i<k;i++)
			printf("%d %d\n",input[i].state,input[i].miles);*/
		int l=0;
		for (int i=0;i<k;i++)
		if (!input[i].visit && input[i].state==enter)
		for (int j=i+1;j<k;j++)	
			if (!input[j].visit && !strcmp(input[i].name,input[j].name))
			{
				if (input[j].state==exit)
				{
					input[i].visit=input[j].visit=true;
					int lt=check(input[i].name,l);
					if (lt==-1)
					{
						strcpy(output[l].name,input[i].name);
						output[l].money=abs(input[j].miles-input[i].miles)*input[i].fee+100;
						l++;
					}
					else 
						output[lt].money+=abs(input[j].miles-input[i].miles)*input[i].fee+100;
				}
				else input[i].visit=true;
				break;
			}
/*		int now=0;
		int last=0;
		bool find=false;
		while (now<k)
		{
			int fee=0;
			while (now<k && strcmp(input[last].name,input[now].name)==0)
			{
				if (!find)
				{
					if (input[now].state==enter)
						find=true,last=now;
					else continue;
				}
				else 
				{
						if (input[now].state==exit)
						{
							find=false;
							fee+=100+abs(input[now].miles-input[now].miles)*input[now].fee;	
						}
						else 
							continue;
				}
				now++;
			}
		}*/
//		sort(output,output+l,cmpo);
		for (int i=0;i<l;i++)
			printf("%s $%.2f\n",output[i].name,output[i].money/100.0+2);
		if (T) putchar('\n');
	}
	return 0;
}
