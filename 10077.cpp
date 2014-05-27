#include<cstdio>
#include<cstring>
struct FS
{
	int FZ,FM;//分子、分母
	FS  operator=(FS  a)
	{
		FZ=a.FZ;
		FM=a.FM;
		return *this;
	}
	friend FS operator+(FS &a,FS &b);
	bool operator==(FS & b)
	{
		if(FZ==b.FZ && FM==b.FM)
			return true;
		return false;
	}
	bool operator>(FS &B)
	{
		if (FZ*B.FM>FM*B.FZ)
			return true;
		return false;
	}
};
FS operator+(FS &a,FS &b)
{
	FS temp;
	temp.FZ=a.FZ+b.FZ;
	temp.FM=a.FM+b.FM;
	return temp;
}
FS L,R;
main()
{
	int m,n;
	FS S;
	int T;
	while (scanf("%d%d",&m,&n)==2)
	{
		S.FZ=m;S.FM=n;
		L.FZ=0;L.FM=1;
		R.FZ=1;R.FM=0;
		int k=0;
		while (1)
		{
			k++;
			FS mid;
			mid=L+R;
			if (mid==S) break;
			else if (mid>S)
			{
				printf("L");
				R=mid;
			}
			else 
			{
				printf("R");
				L=mid;
			}
		}
		putchar('\n');
	}
	return 0;
}
