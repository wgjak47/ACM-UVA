import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		BigInteger a[] = new BigInteger[10010];
		BigInteger tow[] = new BigInteger[200];
		tow[0] = BigInteger.ONE;
		BigInteger t = BigInteger.ONE;
		t=t.add(BigInteger.ONE);
		for (int i = 1; i < 150; i++)
			tow[i] = tow[i - 1].multiply(t);
		int k = 1,reg=1;
		a[1]=BigInteger.ONE;
		a[0]=BigInteger.ZERO;
		for (int i=2;i<10001;i++)
		{
			a[i]=BigInteger.ZERO;
			a[i]=a[i].add(a[i-k].multiply(t));
			a[i]=a[i].add(tow[k]);
			a[i]=a[i].subtract(BigInteger.ONE);
			reg++;
			if (reg==k+1) {k++;reg=0;}
		}
		while (cin.hasNext()) {
			int n = cin.nextInt();
			System.out.println(a[n]);
		}
	}
}
