import java.io.*;
import java.util.*;

public class BOJ12015_가장긴증가하는부분수열2 {
	static int N;
	static int[] arr;
	
	static int lowerBound(int[] arr, int start, int end, int key) {
		int mid;
		while(start < end) {
			mid = (start + end) / 2;
			
			if(arr[mid] < key)	start = mid + 1;
			else 	end = mid;
		}
		return start;
	}
	
	static int LIS() {
		int[] cache = new int[N];
		int index = 0;
		cache[0] = arr[0];
		for(int i=1;i<N;i++) {
			if(arr[i] > cache[index]) 
				cache[++index] = arr[i];
			else {
				int index2 = lowerBound(cache, 0, index, arr[i]);
				cache[index2] = arr[i];
			}
		}
		return index + 1;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		
		st = new StringTokenizer(br.readLine(), " ");
		for(int i=0;i<N;i++)
			arr[i] = Integer.parseInt(st.nextToken());
		
		System.out.println(LIS());
		
		br.close();
	}
}
