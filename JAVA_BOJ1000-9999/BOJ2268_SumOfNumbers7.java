import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class BOJ2268_SumOfNumbers7 {
	
	static int[] arr;
	static long[] tree;
	
	static long getTree(int start, int end, int node) {
		if(start == end)	return tree[node] = arr[start];
		
		int mid = (start + end)/2;
		return tree[node] = getTree(start, mid, node*2) + getTree(mid+1,end,node*2+1);
	}
	
	static long getSum(int start, int end, int node, int left, int right) {
		if(start > right || end < left)	return 0;
		if(left <= start && end <= right)	return tree[node];
		
		int mid = (start + end)/2;
		return getSum(start, mid, node*2, left, right) + getSum(mid+1,end,node*2+1,left,right);
	}
	
	static void update(int start, int end, int node, int index, long change) {
		if(start > index || end < index)	return;
		
		tree[node] += change;
		if(start == end)	return;
		
		int mid = (start + end)/2;
		update(start, mid, node*2, index, change);
		update(mid+1,end,node*2+1, index, change);
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        arr = new int[N+1];
        tree = new long[N*4];
        
        getTree(1, N, 1);
        
        int a,b,c;
        for(int i=0;i<M;i++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	a = Integer.parseInt(st.nextToken());
        	b = Integer.parseInt(st.nextToken());
        	c = Integer.parseInt(st.nextToken());
        	if(a == 0) {
        		if(b < c)	sb.append(getSum(1,N,1,b,c)).append('\n');
        		else 		sb.append(getSum(1,N,1,c,b)).append('\n');
        	}
        	else {
        		update(1,N,1,b,c-arr[b]);
        		arr[b] = c;
        	}
        }
        
        System.out.println(sb);
        br.close();
    }
}