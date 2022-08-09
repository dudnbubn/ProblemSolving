import java.io.*;
import java.util.*;

public class BOJ2581_소수 {
	
	static int N, M;
	static boolean[] isPrime;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		M = Integer.parseInt(br.readLine());
		N = Integer.parseInt(br.readLine());
		
		isPrime = new boolean[N + 1];
		
		Eratos();
		
		int first = 0, sum = 0;
		for(int i=M;i<=N;i++) {
			if(isPrime[i]) {
				if(first == 0)
					first = i;
				sum += i;
			}
		}
		
		if(first == 0)	sb.append(-1);
		else {
			sb.append(sum).append('\n').append(first);
		}
		
		System.out.println(sb);
	}
	
	static void Eratos() {
		for(int i=2;i<=N;i++){
			isPrime[i] = true;
		}
		
		for(int i=2;i*i<=N;i++) {
			if(isPrime[i]) {
				for(int j=i*i;j<=N;j+=i)
					isPrime[j] = false;
			}
		}
	}
}
