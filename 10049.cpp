#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(a,b) a>b?a:b
// 递推方法：设 G（n） 表示满足 f（k） > f(k - 1) 时的自变量值，观察序列可以知道 G（1）
//  = 2，G（2） = 4，G（3） = 6，G（4） = 9，... ，由序列的定义可以知道区间 
//  [G（n - 1），G（n）） 有 f（n） 个 n，则可以知道：
// 
//  G（n） = f（1） + f（2） + f（3） + ... + f（n） + 1
// 
//  则有：
// 
//  G（n） = G（n - 1） + f（n）
// 
//  由于已经知道 [G（n - 1），G（n）） 之间的数函数值都是 n。则可以通过以下方式计算
//  G（n） 的值：
//  G（1） = 2，G（2） = 4，k = 1，对于[G（k），G（k + 1））之间的数，其 f（n） =
//  k + 1，则有 G（n） = G（n - 1） + k + 1。
// 
using namespace std;
int finds[1000001];
main()
{
	int N;
	finds[0]=1;
	finds[1]=2;
	finds[2]=4;
	int k=2;
	int max=0;
	while (1)
	{
		bool all=false;
		for (int i=finds[k-1];i<=finds[k];i++)
		{
			finds[i]=finds[i-1]+k;
			if (finds[i]>=2000000000)
			{
				max=max(i,max);
				all=true;
				break;
			}
		}
		k++;
		if (all) break;
	}
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		if (N==1) printf("1\n");
		else  if (N==2) printf("2\n");
		else if (N==3) printf("2\n"); 
		else 
		printf("%ld\n",upper_bound(finds,finds+max,N)-finds);
	}
	return 0;
}
