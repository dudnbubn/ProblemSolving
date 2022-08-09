import java.io.*;
import java.util.*;

public class BOJ11659_구간합구하기4 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int[] arr = new int[N + 1];
		st = new StringTokenizer(br.readLine(), " ");
		for(int i=1;i<=N;i++) 
			arr[i] = arr[i-1] + Integer.parseInt(st.nextToken());
			
		
		int a, b;
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			sb.append(arr[b] - arr[a-1]).append('\n');
		}
		
		System.out.println(sb);
		br.close();
	}
	
}
