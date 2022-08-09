import java.io.*;
import java.util.*;

public class BOJ2023_신기한소수 {
	
	static int N;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		N = Integer.parseInt(br.readLine());

		recur(0, 0);
		
		System.out.println(sb);
		br.close();
	}
	
	static void recur(int depth, int num) {
		if(depth == N) {
			sb.append(num).append('\n');
			return;
		}
		
		int next;
		boolean isPrime;
		for(int i=0;i<10;i++) {
			isPrime = true;
			next = num * 10 + i;
			if(next < 2)	continue;
			for(int j=2;j*j<=next;j++) {
				if(next % j == 0) {
					isPrime = false;
					break;
				}
			}
			if(isPrime) {
				recur(depth+1, next);
			}
		}
	}
}
