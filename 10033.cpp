#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int d,n,i;
int commond[1002];
bool flag;
char s[1002][5]; 
int reg[11];
int all;
void f1()
{
	flag=false;
	all++;
}
void f2()
{
	int d=s[i][1]-'0',n=s[i][2]-'0';
	reg[d]=n;
	all++;
}
void f3()
{
	int d=s[i][1]-'0',n=s[i][2]-'0';
	reg[d]+=n;	
	reg[d]%=1000;
	all++;
}
void f4()
{
	int d=s[i][1]-'0',n=s[i][2]-'0';
	reg[d]*=n;
	reg[d]%=1000;
	all++;
}
void f5()
{
	int d=s[i][1]-'0';
	int ss=s[i][2]-'0';
	reg[d]=reg[ss];
	all++;
}
void f6()
{

	int d=s[i][1]-'0';
	int ss=s[i][2]-'0';
	reg[d]+=reg[ss];
	reg[d]%=1000;
	all++;
}
void f7()
{

	int d=s[i][1]-'0';
	int ss=s[i][2]-'0';
	reg[d]*=reg[ss];
	reg[d]%=1000;
	all++;
}
void f8()
{
	int d=s[i][1]-'0';
	int a=s[i][2]-'0';
	int temp=(s[reg[a]][0]-'0')*100+(s[reg[a]][1]-'0')*10+(s[reg[a]][2]-'0');
	reg[d]=temp;
	all++;
}
void f9()
{

	int ss=s[i][1]-'0';
	int a=s[i][2]-'0';
	int temp=reg[ss];
	sprintf(s[reg[a]],"%.3d",temp);
	all++;
}
void f0()
{
	int d=s[i][1]-'0';
	int ss=s[i][2]-'0';
	if (reg[ss]!=0)
		i=reg[d]-1;
	all++;
}
main()
{
	int total;
	int lg;
	cin>>total;
	getchar();
	getchar();
	while (total--)
	{
		memset(reg,0,sizeof(reg));
		memset(s,'0',sizeof(s));
		all=0;
		flag=true;
		lg=0;
			while(cin.get(s[lg++][0]))
			{
				if (s[lg-1][0]=='\n') {lg--;break;}
				cin.get(s[lg-1][1]);
				cin.get(s[lg-1][2]);
				getchar();
			}
			for (i=0;i<1000;i++)
			{
				if (!flag) break;
				switch(s[i][0])
				{
				  case '1':f1();break;
				  case '2':f2();break;
				  case '3':f3();break;
				  case '4':f4();break;
				  case '5':f5();break;
				  case '6':f6();break;
				  case '7':f7();break;
				  case '8':f8();break;
				  case '9':f9();break;
				  case '0':f0();break;
				  default :break;
				}
			}
				cout<<all<<endl;
				if (total) putchar('\n');
			}
			return 0;
}
