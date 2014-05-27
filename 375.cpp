#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double pi=atan(1)*4.0;
double sum;
double angle(double B,double H)
{
	double R,slide;
	slide=sqrt(B*B/4.0+H*H);
	R=B*H/(slide*2.0+B);
//	cout<<R<<endl;
//	cout<<R*2.0*pi<<endl;
	return R;
}
main()
{
	double B,H;
	int n;
	double R;
	cin>>n;
	while (n--)
	{
		sum=0;
		cin>>B>>H;
		while ((R=angle(B,H))>=0.000001)
		{
			//B:b=H:H-2R
			sum+=pi*2.0*R;
			B=B*(H-2*R)/H;
			H-=2*R;
		}
//		cout<<endl;
		printf("%13lf\n",sum);
		if (n!=0) cout<<endl;
	}
	return 0;
}
