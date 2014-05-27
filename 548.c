#include<stdio.h>
#include<string.h>
int a[10011],b[10011];
struct tree
{
	struct tree *left,*right;
	int value;
};
struct tree te[10011];
int reg=0;
int root;
int min;
int lt;
struct tree *solve(int start,int end)
{
	int i,j,k;
	for (i=start;i<=end;i++)
		if (a[i]==b[root]) break;
	struct tree *node=&te[reg++];
	node->value=b[root--];
	if (end>=i+1 && root>=0)
	node->right=solve(i+1,end);
	else node->right=NULL;
	if (start<=i-1 && root>=0)
	node->left=solve(start,i-1);
	else node->left=NULL;
	return node;
}
void back(struct tree *fuck,int sum)
{
	if (fuck!=NULL)
	if (fuck->left!=NULL)
	back(fuck->left,sum+(fuck->value));
	if (fuck->right!=NULL)
	back(fuck->right,sum+(fuck->value));
	if (fuck->left==NULL && fuck->right==NULL)
		if (min>(sum+fuck->value))
		{
			min=sum+fuck->value;
			lt=fuck->value;
		}
	return ;
}
main()
{
	int i,j,k,l,m,n;
	i=0;
	while (scanf("%d",&a[i++])==1)
	{
		char c=getchar();
		if (c=='\n')
		{
			for (j=0;j<i;j++)
				scanf("%d",&b[j]);
			root=i-1;
			min=2147483647;
			struct tree *result=solve(0,i-1);
			back(result,0);
			i=0;
			reg=0;
			printf("%d\n",lt);
		}
	}
	return 0;
}
