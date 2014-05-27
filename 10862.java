import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;
public class Main {
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			if (n==0) break;
			BigInteger d[]= new BigInteger[4010];
			d[0]=BigInteger.ONE;
			d[1]=d[0];
			for (int i=2;i<=4000;i++)
				d[i]=d[i-1].add(d[i-2]);
			System.out.println(d[n*2-1]);
		}
	}
}
