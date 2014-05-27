import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			int m = cin.nextInt();
			int g[]=new int[22];
			g[0]=1;
			for (int i=1;i<=m;i++) g[i]=g[i-1]*n;
			for (int i=1;i<=m;i++) g[i]+=g[i-1];
			BigInteger f[]=new BigInteger[110];
			f[0]=BigInteger.ONE;
			for (int i=1;i<=m;i++)
			{
				f[i]=BigInteger.ONE;
				BigInteger tmp=BigInteger.ZERO;
				for (int j=1;j<=n;j++)
				{
					tmp=C(j*g[i-1],g[i-1]);
					f[i]=f[i].multiply(f[i-1].multiply(tmp));
				}
			}
			System.out.println(f[m]);
		}
	}
	public static BigInteger C(int a,int b)
	{
		BigInteger tmp=BigInteger.ONE;
		for (int i=a;i>a-b;i--)
			tmp=tmp.multiply(BigInteger.valueOf(i));
		for (int i=2;i<=b;i++)
			tmp=tmp.divide(BigInteger.valueOf(i));
		return tmp;
	}
}
