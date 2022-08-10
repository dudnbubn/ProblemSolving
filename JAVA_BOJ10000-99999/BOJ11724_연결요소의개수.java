import java.io.*;
import java.util.*;

public class BOJ11724_연결요소의개수 {
	static boolean[] visited;
	static ArrayList<Integer>[] al;
	
	static void BFS(int node) {
		ArrayDeque<Integer> q = new ArrayDeque<>();
		
		q.offer(node);
		visited[node] = true;
		int cur;
		while(!q.isEmpty()) {
			cur = q.poll();
			for(int i : al[cur]) {
				if(!visited[i]) {
					visited[i] = true;
					q.offer(i);
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		visited  = new boolean[N+1];
		al = new ArrayList[N+1];
		for(int i=1;i<=N;i++)
			al[i] = new ArrayList<>(); 
		
		int u, v;
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			u = Integer.parseInt(st.nextToken());
			v = Integer.parseInt(st.nextToken());
			al[u].add(v);
			al[v].add(u);
		}
		
		int result = 0;
		for(int i=1;i<=N;i++) {
			if(!visited[i]) {
				result++;
				BFS(i);
			}
		}
		System.out.println(result);
		
		br.close();
	}
}
