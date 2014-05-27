#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct fuck
{
	int x,y;
};
vector<fuck> d;
main()
{
	int n;
	int k=1;
	fuck t={0,0};
	d.push_back(t);
	t.y++;
	d.push_back(t);
	while (true)
	{
		for (int i=0;i<k;i++)
		{
			t.x--;
			d.push_back(t);
		}
		for (int i=0;i<k;i++)
		{
			t.y--;
			d.push_back(t);
		}
		for (int i=0;i<k;i++)
		{
			t.x++;
			t.y--;
			d.push_back(t);
		}
		for (int i=0;i<k;i++)
		{
			t.x++;
			d.push_back(t);
		}
		for (int i=0;i<k;i++)
		{
			t.y++;
			d.push_back(t);
		}
		t.y++;
		d.push_back(t);
		for (int i=0;i<k;i++)
		{
			t.y++;
			t.x--;
			d.push_back(t);
		}
		if (d.size()>100002) break;		
		k++;
	}
	while (scanf("%d",&n)==1)
		printf("%d %d\n",d[n-1].x,d[n-1].y);
	return 0;
}
