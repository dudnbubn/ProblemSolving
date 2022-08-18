import java.io.*;
import java.util.*;

public class BOJ1717_집합의표현 {
	
	static int[] parent;
	
	static int find(int x) {
		if(parent[x] == x)	return x;
		return parent[x] = find(parent[x]);
	}
	
	static void union(int x, int y) {
		x = find(x);
		y = find(y);
		
		parent[y] = x;
	}
	
    public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	int N = Integer.parseInt(st.nextToken());
    	int M = Integer.parseInt(st.nextToken());
    	
    	parent = new int[N+1];
    	for(int i=0;i<=N;i++)	parent[i] = i;
    	
    	int cmd, a, b;
    	for(int i=0;i<M;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		cmd = Integer.parseInt(st.nextToken());
    		a = Integer.parseInt(st.nextToken());
    		b = Integer.parseInt(st.nextToken());
    		
    		if(cmd == 0)	union(a, b);
    		else {
    			if(find(a) == find(b))	sb.append("YES\n");
    			else	sb.append("NO\n");
    		}
    	}
    	
    	System.out.println(sb);
    	
    	br.close();
    }
}