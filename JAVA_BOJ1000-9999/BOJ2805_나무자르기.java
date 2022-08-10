import java.io.*;
import java.util.*;

public class BOJ2805_나무자르기 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int start = 1, end = 0;
		int[] arr = new int[N];
		st = new StringTokenizer(br.readLine(), " ");
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			end = end > arr[i] ? end : arr[i];
		}
		
		while(start <= end) {
			int mid = (start + end) / 2;
			long len = 0;
			for(int i=0;i<N;i++) 
				len += Math.max(0, (arr[i] - mid));
			if(len < M)	end = mid -1;
			else 	start = mid + 1;
		}
		System.out.println(end);
		
		br.close();
	}
	
}
