import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(System.in);
		int S=cin.nextInt();
		while (S-- > 0)
		{
		int n = cin.nextInt();
		BigInteger ans = BigInteger.ONE;
		BigInteger temp4 = BigInteger.ONE;
		BigInteger temp2 = BigInteger.ONE;
		for(int i = 0; i < 4; ++i)
			temp4 = temp4.multiply(BigInteger.valueOf(n-i));
		temp4=temp4.divide(BigInteger.valueOf(24));
		for (int i=0;i<2;++i)
			temp2 = temp2.multiply(BigInteger.valueOf(n-i));
		temp2 = temp2.divide(BigInteger.valueOf(2));
		ans=ans.add(temp2.add(temp4));
		System.out.println(ans);
		byte
		}
	}
}
