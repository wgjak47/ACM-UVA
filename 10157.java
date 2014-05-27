import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(System.in);
		BigInteger a[][]=new BigInteger[310][310];
		BigInteger temp=BigInteger.ZERO;
		for (int i=0;i<=300;i++)
		for (int j=0;j<=300;j++)
			a[i][j]=BigInteger.ZERO;
		for (int i=0;i<300;i++)
			a[0][i]=BigInteger.ONE;
		a[0][0]=BigInteger.ONE;
		//System.out.println(a[1][2]);
		for (int i=1;i<=150;i++)
		for (int j=1;j<=150;j++)
		{
			for (int k=0;k<i;k++)
			{
				temp=a[k][j-1].multiply(a[i-1-k][j]);
				a[i][j]=a[i][j].add(temp);
			}
		}
		while (cin.hasNext())
		{
		int n = cin.nextInt();
		int m = cin.nextInt();
		if (n%2==0)
		System.out.println(a[n/2][m].subtract(a[n/2][m-1]));
		else System.out.println(0);
		}
	}
}
