import java.io.*;
import java.util.*;

public class BOJ2357_최솟값과최댓값 {
	
	static int[] arr;
	static int[][] tree;
	
	static int[] segmentTree(int start, int end, int node) {
		if(start == end)	{
			tree[node][0] = tree[node][1] = arr[start];
			return tree[node];
		}
		
		int mid = (start + end)/2;
		int[] left = segmentTree(start, mid, node*2);
		int[] right = segmentTree(mid+1, end, node*2+1);
		tree[node][0] = left[0] > right[0] ? left[0] : right[0];
		tree[node][1] = left[1] < right[1] ? left[1] : right[1];
		return tree[node];
	}
	
	static int[] getMaxMin(int start, int end, int node, int left, int right) {
		if(left > end || right < start)	return new int[] {Integer.MIN_VALUE, Integer.MAX_VALUE};
		if(left <= start && end <= right)	return tree[node];
		
		int mid = (start + end)/2;
		int[] l = getMaxMin(start, mid, node*2, left, right);
		int[] r = getMaxMin(mid+1, end, node*2+1, left, right);
		
		int maximum = l[0] > r[0] ? l[0] : r[0];
		int minimum = l[1] < r[1] ? l[1] : r[1];
		return new int[] {maximum, minimum};
	}
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	
    	int N = Integer.parseInt(st.nextToken());
    	int M = Integer.parseInt(st.nextToken());
    	
    	arr = new int[N+1];
    	for(int i=1;i<=N;i++)	arr[i] = Integer.parseInt(br.readLine());
    	tree = new int[4*N][2];
    	
    	segmentTree(1, N, 1);
    	int a, b;
    	int[] result;
    	for(int i=1;i<=M;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		a = Integer.parseInt(st.nextToken());
    		b = Integer.parseInt(st.nextToken());
    		result = getMaxMin(1, N, 1, a, b);
    		sb.append(result[1]).append(' ').append(result[0]).append('\n');
    	}
    	
    	System.out.println(sb);
    	br.close();
    }
}