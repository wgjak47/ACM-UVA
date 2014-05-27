#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct lea
{
	int value;
	struct lea *left;
	struct lea *right;
};
int s[1000];
struct lea *creat(int lt)
{
	int temp;
	struct lea * tree;
	scanf("%d",&temp);
	if (temp!=-1)
	tree=(struct lea*)malloc(sizeof(struct lea));
	else return NULL;
	s[lt]+=temp;
/*	tree->value=temp;*/
	tree->left=creat(lt-1);
	tree->right=creat(lt+1);
	return tree;
}
/*void dfs_find(struct lea * i,int lt)
{
	s[lt]+=i->value;
	if ((i->left)!=NULL)
	dfs_find(i->left,lt-1);
	if ((i->right)!=NULL)
	dfs_find(i->right,lt+1);
}*/
main()
{
	struct lea *tree;
	struct lea *i;
	int j,k,mid,reg=0;
	memset(s,-1,sizeof(s));
/*	freopen("in.txt","r",stdin);*/
	while ((tree=creat(100))!=NULL)
	{
/*		for (i=tree;i!=NULL;i=i->left)
			mid++;
		dfs_find(tree,mid-1);*/
		j=0;
		printf("Case %d:\n",++reg);
		while (s[j]==-1) j++;
		k=j;
		while (s[j]!=-1)
		{
			if (j!=k) putchar(' ');
			printf("%d",s[j]+1);
			j++;
		}
		puts("\n");
		memset(s,-1,sizeof(s));
    }
	return 0;
}
