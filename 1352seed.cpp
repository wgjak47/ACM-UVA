#include<cstdio>
#include<cstring>
int left[7]={4,0,2,3,5,1};
int up[7]={2,1,5,0,4,3};
void rot(int *T,int *p)
{
	int q[7];
	memcpy(q,p,sizeof(q));
	for (int i=0;i<6;i++)
		p[i]=T[q[i]];
}
main()
{
	int p0[7]={0,1,2,3,4,5};
	printf("int dice24[26][6]={\n");
	for (int i=0;i<6;i++)
	{
		int p[7];
		memcpy(p,p0,sizeof(p0));
		if (i==0) rot(up,p);
		if (i==1) {rot(left,p);rot(up,p);}
		if (i==3) {rot(up,p);rot(up,p);}
		if (i==4) {rot(left,p);rot(left,p);rot(up,p);}
		if (i==5) {rot(left,p);rot(left,p);rot(left,p);rot(up,p);}
		for (int j=0;j<4;j++)
		{
			printf("{%d,%d,%d,%d,%d,%d},\n",p[0],p[1],p[2],p[3],p[4],p[5]);
			rot(left,p);
		}
	}
	return 0;
}
