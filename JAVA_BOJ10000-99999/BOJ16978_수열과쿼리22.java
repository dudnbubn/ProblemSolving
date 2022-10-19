import java.io.*;
import java.util.*;

public class BOJ16978_수열과쿼리22 {
	
	static int N;
	static long[] tree, arr;
	
	static long getTree(int start, int end, int node) {
		if(start == end) return tree[node] = arr[start];
		
		int mid = (start + end)/2;
		return tree[node] = getTree(start, mid, node*2) + getTree(mid+1, end, node*2+1);
	}
	
	static long getSum(int start, int end, int node, int left, int right) {
		if(start > right || end < left)	return 0;
		if(left <= start && end <= right)	return tree[node];
		
		int mid = (start+end)/2;
		return getSum(start, mid, node*2, left, right) + getSum(mid+1, end, node*2+1, left, right);
	}
	
	static void update(int start, int end, int node, int index, long dif) {
		if(index < start || end < index)	return;
		
		tree[node] += dif;
		if(start == end)	return;
		int mid = (start+end)/2;
		update(start, mid, node*2, index, dif);
		update(mid+1, end, node*2+1, index, dif);
	}
	
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        arr = new long[N+1];
        tree = new long[N*4];
        
        st = new StringTokenizer(br.readLine(), " ");
        for(int i=1;i<=N;i++)	arr[i] = Long.parseLong(st.nextToken());
        
        int M = Integer.parseInt(br.readLine());
        ArrayDeque<int[]> queries1 = new ArrayDeque<>();
        ArrayDeque<int[]>[] queries2 = new ArrayDeque[M+1];
        ArrayDeque<Long>[] results = new ArrayDeque[M+1];
        ArrayList<Integer> cmds = new ArrayList<>();
        for(int i=0;i<=M;i++) {
        	queries2[i] = new ArrayDeque<>();
        	results[i] = new ArrayDeque<>();
        }
        
        int cmd, index, from, to;
        for(int i=0;i<M;i++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	cmd = Integer.parseInt(st.nextToken());
        	if(cmd == 1) {
        		from = Integer.parseInt(st.nextToken());
        		to = Integer.parseInt(st.nextToken());
        		queries1.add(new int[] {from, to});
        	}
        	else {
        		index = Integer.parseInt(st.nextToken());
        		from = Integer.parseInt(st.nextToken());
        		to = Integer.parseInt(st.nextToken());
        		queries2[index].add(new int[] {from, to});
        		cmds.add(index);
        	}
        }
        
        getTree(1, N, 1);
        
        int nth = 0;
        for(int[] query : queries2[nth]) {
    		from = query[0];
    		to = query[1];
    		results[nth].add(getSum(1, N, 1, from, to));
    	}
        
        int[] cur;
        long prev;
        while(!queries1.isEmpty()) {
        	nth++;
        	
        	cur = queries1.poll();
        	from = cur[0];
        	to = cur[1];
        	prev = arr[from];
        	arr[from] = to;
        	update(1, N, 1, from, to-prev);
        	
        	for(int[] query : queries2[nth]) {
        		from = query[0];
        		to = query[1];
        		results[nth].add(getSum(1, N, 1, from, to));
        	}
        }
        
        for(int c : cmds) {
        	sb.append(results[c].poll()).append('\n');
        }
        
        System.out.println(sb);
        br.close();
    }
}