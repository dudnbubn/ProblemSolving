import java.io.*;
import java.util.*;

public class BOJ1275_커피숍2 {
	
	static long[] arr;
	static long[] tree;
	
	static long getTree(int start, int end, int node) {
		if(start == end)	return tree[node] = arr[start];
		
		int mid = (start+end)/2;
		return tree[node] = getTree(start, mid, node*2) + getTree(mid+1, end, node*2+1);
	}
	
	static long getSum(int start, int end, int node, int left, int right) {
		if(left > end || right < start)	return 0;
		if(left <= start && end <= right)	return tree[node];
		
		int mid = (start+end)/2;
		return getSum(start, mid, node*2, left, right) + getSum(mid+1, end, node*2+1, left, right);
	}
	
	static void update(int start, int end, int node, int index, long gap) {
		if(start > index || end < index)	return;
		
		tree[node] += gap;
		if(start == end)	return;
		
		int mid = (start+end)/2;
		update(start, mid, node*2, index, gap);
		update(mid+1, end, node*2+1, index, gap);
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N = Integer.parseInt(st.nextToken());
		int Q = Integer.parseInt(st.nextToken());
		arr = new long[N+1];
		tree = new long[4*N];
		
		st = new StringTokenizer(br.readLine(), " ");
		for(int i=1;i<=N;i++)	arr[i] = Long.parseLong(st.nextToken());
		getTree(1, N, 1);
		int x, y, a, b;
		for(int q=0;q<Q;q++) {
			st = new StringTokenizer(br.readLine(), " ");
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			
			if(x < y)	sb.append(getSum(1, N, 1, x, y)).append('\n');
			else		sb.append(getSum(1, N, 1, y, x)).append('\n');
			
			long gap = b - arr[a];
			update(1, N, 1, a, gap);
			arr[a] = b;
		}
		
		System.out.println(sb);
		br.close();
	}
}
