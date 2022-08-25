import java.io.*;
import java.util.*;

public class BOJ1865_웜홀 {
	
	static boolean BellmanFord(int N, ArrayList<int[]> edges) {
		final int INF = (int)2e9;
		int[] distance = new int[N+1];
		distance[1] = 0;
		for(int i=2;i<=N;i++)	distance[i] = INF;
		
		int S, E, T;
		for(int k=1;k<=N-1;k++) {
			for(int[] edge : edges) {
				S = edge[0];
				E = edge[1];
				T = edge[2];
				
				distance[E] = Math.min(distance[E], distance[S] + T);
			}
		}
	
		for(int[] edge : edges) {
			S = edge[0];
			E = edge[1];
			T = edge[2];
			
			if(distance[E] > distance[S] + T)
				return true;
		}
		return false;
	}
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st;
    	
    	int TC = Integer.parseInt(br.readLine());
    	
    	int N, M, W, S, E, T;
    	ArrayList<int[]> edges = new ArrayList<>();
    	for(int tc=1;tc<=TC;tc++) {
    		edges.clear();
    		st = new StringTokenizer(br.readLine(), " ");
    		N = Integer.parseInt(st.nextToken());
    		M = Integer.parseInt(st.nextToken());
    		W = Integer.parseInt(st.nextToken());
    		
    		for(int i=0;i<M;i++) {
    			st = new StringTokenizer(br.readLine(), " ");
    			S = Integer.parseInt(st.nextToken());
    			E = Integer.parseInt(st.nextToken());
    			T = Integer.parseInt(st.nextToken());
    			edges.add(new int[] {S, E, T});
    			edges.add(new int[] {E, S, T});
    		}
    		for(int i=0;i<W;i++) {
    			st = new StringTokenizer(br.readLine(), " ");
    			S = Integer.parseInt(st.nextToken());
    			E = Integer.parseInt(st.nextToken());
    			T = Integer.parseInt(st.nextToken());
    			edges.add(new int[] {S, E, -T});    			
    		}
    		
    		if(BellmanFord(N, edges))	sb.append("YES").append('\n');
    		else 	sb.append("NO").append('\n');
    	}
    	
    	System.out.println(sb);
    	br.close();
    }
}