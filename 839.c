#include<stdio.h>
#include<stdlib.h>
struct fuck
{
	int wl,wr,dl,dr;
	int suml,sumr;
	struct fuck *left,*right;
};
struct fuck *creat (int *flag,int i)
{
	int j,k;
	struct fuck* a;
	a=(struct fuck*)malloc(sizeof (struct fuck));
	scanf("%d%d%d%d",&(a->wl),&(a->dl),&(a->wr),&(a->dr));
	if (a->wl==0)
		a->left=creat(flag,i+1);
	if (a->wr==0)
		a->right=creat(flag,i+1);
	if (*flag!=1)
	{	
	if (a->wl==0) a->wl=a->left->wr+a->left->wl;
	if (a->wr==0) a->wr=a->right->wr+a->right->wl;
	a->sumr=a->wr*a->dr;a->suml=a->wl*a->dl;
	if (a->sumr!=a->suml) *flag=1;
	}
	return a;
}
main()
{
	struct fuck *head;
	int flag;
	int i,j,k,m,n;
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
    for (i=0;i<n;i++)
	{
		flag=0;
		head=creat(&flag,0);
		if (!flag) printf("YES\n");
		else printf("NO\n");
		if (i!=n-1) putchar('\n');
	}
	return 0;
}
