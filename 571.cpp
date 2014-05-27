/*本题只要求给出一个解，不要求最优。所给的两个罐子容量一定互质，因此必然可以倒出从0到大罐容量间的任何整数值。原理是若A，B互质，则最小公倍数为A×B，即不存在一个1 < n < B，使得nA能被B整除。令r = nA mod B(mod为取模操作)，那么当n从0到B-1变化时，r可以取到0到B-1之间的任何值。这个是很容易证明的，但我的证明过程非常不专业，还请各位数学老师给予指教！

现在的问题就是用AB两个罐子相互倒水来模拟这个数学过程。设小罐容量为A，大罐容量为B。每次将A装满后倒入B中。若第m次后B已装满，A剩下的水量为r1，则有：

    r1 = mA mod B

然后将B倒空，把A中剩余的r1装入B。又经过n次从把A装满倒入B的操作后B被装满，此时A剩下的水量为r2，则有：

    r2 = (r1 + nA) mod B
    = (mA mod B + nA) mod B
    = (m+n)A mod B

由此可知，倒的方法就是每次将A中的水倒进B，但每次在做这一步之间要先检查A、B中的水量，如果A为空，就将A装满；如果B已倒满，就将B清空。最后一定可以在某个时候在B罐中得到需要的水量。*/
#include<cstdio>
#include<cstring>
main()
{
	int c1,c2,n;
	while (scanf("%d%d%d",&c1,&c2,&n)==3)
	{
		int s1=0,s2=0;
		while (1)
		{
			if (s1==0)
			{
				s1=c1;
				printf("fill A\n");	
			}
			else 
			{
				printf("pour A B\n");
				if (s1+s2<=c2)
					s2+=s1,s1=0;
				else s1=s1-(c2-s2),s2=c2;
			}
			if (s2==c2 && c2!=n)
			{
				printf("empty B\n");
				s2=0;
			}
			else if (s2==n)
			{
				printf("success\n");
				break;
			}
		}
	}
	return 0;
}
