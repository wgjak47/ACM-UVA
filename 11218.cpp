#include<iostream>
#include<cstring>
#include<cstdio>
#include<stdlib.h>
#define a1[X] group[X].a1
#define a2[X] group[X].a2
#define a3[X] group[X].a3
using namespace std;
struct group
{
	int a1,a2,a3,score;
};
group fuck[90];
int N;
int max;
int reg=0;
int find_max()
{
	bool people[10]={false};
	for (int i=0;i<N;i++)
	for (int j=i+1;j<N;j++)
	for (int k=j+1;k<N;k++)
	{
		int flag=0;
		people[a1[i]]=people[a2[i]]=people[a3[i]]=true;
		people[a1[j]]=people[a2[j]]=people[a3[j]]=true;
		people[a1[k]]=people[a2[k]]=people[a3[k]]=true;
		for (int m=1;m<10;m++)
			if (people[m]==false) {flag=1;break;}
			memset(people,false,sizeof(people));
			if (flag) continue;		
			return max;
	}
}
int cmp (const void *a,const void *b)
{
	return (struct group *)a->score-(struct group *)b->score;
}
main()
{
	while (cin>>N)
	{
		if (N==0) break;
		max=-1;
		for (int m=0;m<N;m++)
		cin>>fuck[m].a1>>fuck[m].a2>>fuck[m].a3>>fuck[m].score;
		qsort(fuck,N,sizeof(struct group),cmp);
		find_max();
		cout<<"Case "<<++reg<<": "<<max<<endl;
	}
	return 0;
}
