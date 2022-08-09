import java.io.*;
import java.util.*;

public class BOJ2839_설탕배달 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int[] arr = new int[5001];
		
		int N = Integer.parseInt(br.readLine());
		for(int i=1;i<=N;i++)	arr[i] = Integer.MAX_VALUE;
		for(int i=0;i*5<=N;i++) {
			for(int j=0;i*5 + j*3<=N;j++) {
				arr[i*5 + j*3] = Math.min(arr[i*5+j*3], i + j);
			}
		}
		
		if(arr[N] == Integer.MAX_VALUE)	sb.append(-1);
		else 	sb.append(arr[N]);
		
		System.out.println(sb);
	}
}
