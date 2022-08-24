import java.io.*;
import java.util.*;

public class BOJ10868_최솟값 {
	
	static int getTree(int start, int end, int node, int[] arr, int[] tree) {
		if(start == end)	return tree[node] = arr[start];
		
		int mid = (start+end)/2;
		return tree[node] = Math.min(getTree(start, mid, node*2, arr, tree), getTree(mid+1, end, node*2+1, arr, tree));
	}
	
	static int getMin(int start, int end, int node, int left, int right, int[] tree) {
		if(start > right || end < left)		return Integer.MAX_VALUE;
		if(left <= start && end <= right)	return tree[node];
		
		int mid = (start+end)/2;
		return Math.min(getMin(start, mid, node*2, left, right, tree), getMin(mid+1, end, node*2+1, left, right, tree));
	}

	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	
    	int N = Integer.parseInt(st.nextToken());
    	int M = Integer.parseInt(st.nextToken());
    	
    	int[] arr = new int[N+1];
    	int[] tree = new int[4*N];
    	for(int i=1;i<=N;i++)	arr[i] = Integer.parseInt(br.readLine());
    	
    	getTree(1, N, 1, arr, tree);
    	
    	int a, b;
    	for(int i=0;i<M;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		a = Integer.parseInt(st.nextToken());
    		b = Integer.parseInt(st.nextToken());
    		
    		sb.append(getMin(1, N, 1, a, b, tree)).append('\n');
    	}
    	
    	System.out.println(sb);
    	br.close();
    }
}