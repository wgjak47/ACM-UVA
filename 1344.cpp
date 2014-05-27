#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
main()
{
	int N;
	int tj[1100],qw[1100];
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		for (int i=0;i<N;i++)
			scanf("%d",&tj[i]);
		for (int j=0;j<N;j++)
			scanf("%d",&qw[j]);
		sort(tj,tj+N);
		sort(qw,qw+N);
		int twin=0,qwin=0;
		int ts=0,te=N-1;
		int qs=0,qe=N-1;
		while (ts<=te && qs<=qe)
		{
			if (tj[te]>qw[qe])
			{
				te--;
				qe--;
				twin++;
			}
			else if (tj[te]<qw[qe])
			{
				ts++;
				qe--;
				qwin++;
			}
			else 
			{
				if (tj[ts]>qw[qs])
				{
					ts++;
					qs++;
					twin++;
				}	
				else if (tj[ts]<qw[qs])
				{
					ts++;
					qe--;
					qwin++;
				}
				else
				{
					if (tj[ts]<qw[qe])
					{
						ts++;
						qe--;
						qwin++;
					}
					else 
					{
						qe--;
						te--;
					}
				}
			}
		}
		printf("%d\n",(twin-qwin)*200);
	}
	return 0;
}
