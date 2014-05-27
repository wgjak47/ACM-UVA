import java.io.*;
import java.util.*;

class Reader{
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static void init(InputStream input){
		reader=new BufferedReader(new InputStreamReader(input));
		tokenizer=new StringTokenizer("");
	}
	static String next() throws IOException{
		while (!tokenizer.hasMoreElements()){
			tokenizer=new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
	static boolean hasnext() throws IOException{
		if (tokenizer.hasMoreElements())
			return true;
			while (!tokenizer.hasMoreElements()){
				String tmp=reader.readLine();
				if (tmp!=null)
				tokenizer=new StringTokenizer(tmp);
				else return false;
			}
		return true;
	}
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	static double nextDouble() throws IOException{
		return Double.parseDouble(next());
	}
}
class KM{
	int W[][],n;
	int Lx[],Ly[];
	int left[];
	boolean S[],T[];
	boolean read() throws IOException{
		if (!Reader.hasnext()) return false;
		n=Reader.nextInt();
		if (n==-1) return false;
		W=new int[n+2][n+2];
		Lx=new int[n+2];
		Ly=new int[n+2];
		left=new int[n+2];
		S=new boolean[n+2];
		T=new boolean[n+2];
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			W[i][j]=Reader.nextInt();
		return true;
	}
	boolean match(int i){
		S[i]=true;
		for (int j=1;j<=n;j++) if (Lx[i]+Ly[j]==W[i][j] && !T[j]){
			T[j]=true;
			if (left[j]==0 || match(left[j])){
				left[j]=i;
				return true;
			}
		}
		return false;
	}
	void update(){
		int a=1<<30;
		for (int i=1;i<=n;i++) if (S[i])
			for (int j=1;j<=n;j++) if (!T[j]){
				a=Math.min(a, Lx[i]+Ly[j]-W[i][j]);
			}
		for (int i=1;i<=n;i++){
			if (S[i]) Lx[i]-=a;
			if (T[i]) Ly[i]+=a;
		}
	}
	void KM_S(){
		for (int i=1;i<=n;i++){
			left[i]=Lx[i]=Ly[i]=0;
			for (int j=1;j<=n;j++)
				Lx[i]=Math.max(Lx[i],W[i][j]);
		}
		for (int i=1;i<=n;i++){
			while (true){
				for (int j=1;j<=n;j++) S[j]=T[j]=false;
				if (match(i)) break;
				else update();
			}
		}
		output();
	}
	void output(){
		int sum=0;
		for (int i=1;i<=n;i++){
			if (i!=1) System.out.print(' ');
			System.out.print(Lx[i]);
			sum+=Lx[i];
		}
		System.out.println("");
		for (int i=1;i<=n;i++){
			if (i!=1) System.out.print(' ');
			System.out.print(Ly[i]);
			sum+=Ly[i];
		}
		System.out.println("");
		System.out.println(sum);
	}
}
public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Reader.init(System.in);
		KM one=new KM();
		while (one.read()){
			one.KM_S();
		}
	}
}
