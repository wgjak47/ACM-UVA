#include<cstdio>
#include<cstring>
#include<cstdlib>
int G[30][30];
int vis[300];
int queue[300],solve[300],node[300];
int min=100,length;
int total;
void dfs(int reg,int deep)
{
    int flag=0,max;
    queue[deep]=reg;
    for (int i=0;i<27;i++)
        if (node[i] && !vis[i])
        {
            flag=1;
            vis[i]=1;
            dfs(i,deep+1);
            vis[i]=0;
        }
        if (deep==total-1)
        {
          /*  for (int i=0;i<=deep;i++)
            printf("%c ",queue[i]+'A');
            putchar('\n');*/
			max=0;
            for (int i=0;i<total;i++)
            {
                for (int j=i;j<total;j++)
                if (G[queue[i]][queue[j]])
                {
			/*		printf("%d %d %d\n",i,j,abs(i-j));*/
					if (max<abs(i-j))
						max=abs(i-j);
                }
            }
		//	printf("%d\n",max);
            if (max<min)
            {
                min=max;
                memcpy(solve,queue,sizeof(solve));
            }
        }
    
}
void solve_it()
{
	total=0;
	for (int j=0;j<27;j++)
		if (node[j])
			total++;
    for (int i=0;i<27;i++)
	if (node[i])
    {
        vis[i]=1;
        dfs(i,0);
        vis[i]=0;
    }
    for (int j=0;j<total;j++)
    printf("%c ",solve[j]+'A');
    printf("-> ");
    printf("%d\n",min);
	min=100;
    memset(G,0,sizeof(G));
    memset(vis,0,sizeof(vis));
	memset(node,0,sizeof(node));
}
main()
{
    int i,j,k,l,m,n,flag=0;
    char temp[100];
    char c,past;
    memset(G,0,sizeof(G));
    memset(vis,0,sizeof(vis));
	memset(node,0,sizeof(node));
   // freopen("in.in","r",stdin);
    while(c=getchar())
    {
        if (c=='#') break;
        if (c=='\n') 
		{
			solve_it();
			flag=0;
		}
        if (c==':') {flag=1;continue;}
        if (c==';') {flag=0;continue;}
        if (flag)
        {
			node[c-'A']=1;	
            G[past-'A'][c-'A']=1;
            G[c-'A'][past-'A']=1;
        }
        else 
		{
			past=c;
			node[c-'A']=1;
		}
    }
    return 0;
}
