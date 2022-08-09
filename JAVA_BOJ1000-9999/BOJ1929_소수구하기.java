import java.io.*;
import java.util.*;

public class BOJ1929_소수구하기 {
	
	static boolean[] isPrime;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		isPrime = new boolean[N+1];
		Eratos(N);
		
		for(int i=M;i<=N;i++) 
			if(isPrime[i])
				sb.append(i).append('\n');
		
		System.out.println(sb);
	}
	
	static void Eratos(int N) {
		for(int i=2;i<=N;i++)
			isPrime[i] = true;
		
		for(int i=2;i*i<=N;i++) {
			if(isPrime[i]) {
				for(int j=i*i;j<=N;j+=i)
					isPrime[j] = false;
			}
		}
	}
}
