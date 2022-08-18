import java.io.*;
import java.util.*;

public class BOJ1504_특정한최단경로 {
	
	static int N, E;
	static ArrayList<int[]>[] edges;
	static int[][] distance;
	static boolean[] visited;
	
	static void Dijkstra(int start, int index) {
		for(int i=1;i<=N;i++)	visited[i] = false;
		PriorityQueue<int[]> pq = new PriorityQueue<int[]>((o1, o2) -> {
			int r = Integer.compare(o1[0], o2[0]);
			if(r == 0)	r = Integer.compare(o1[1], o2[1]);
			return r;
		});
		
		pq.offer(new int[] {0, start});
		int[] cur;
		int dist, node;
		while(!pq.isEmpty()) {
			cur = pq.poll();
			dist = cur[0];
			node = cur[1];
			if(visited[node]) continue;
			
			visited[node] = true;
			distance[index][node] = dist;
			
			for(int[] adj : edges[node]) {
				if(visited[adj[1]])	continue;
				pq.offer(new int[] {dist + adj[0], adj[1]});
			}
		}
	}

    public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	
    	N = Integer.parseInt(st.nextToken());
    	E = Integer.parseInt(st.nextToken());
    	
    	edges = new ArrayList[N+1];
    	visited = new boolean[N+1];
    	distance = new int[3][N+1];
    	
    	
		for(int i=0;i<N+1;i++) {
			edges[i] = new ArrayList<>();
			for(int j=0;j<3;j++) 
			distance[j][i] = (int)1e8 * 7;
		}
    	
    	int a,b,c;
    	for(int i=0;i<E;i++) {
    		st=new StringTokenizer(br.readLine(), " ");
    		a = Integer.parseInt(st.nextToken());
    		b = Integer.parseInt(st.nextToken());
    		c = Integer.parseInt(st.nextToken());
    		
    		edges[a].add(new int[] {c,b});
    		edges[b].add(new int[] {c,a});
    	}
    	st = new StringTokenizer(br.readLine(), " ");
    	int v1 = Integer.parseInt(st.nextToken());
    	int v2 = Integer.parseInt(st.nextToken());
    	
    	Dijkstra(1, 0);
    	Dijkstra(v1, 1);
    	Dijkstra(v2, 2);
    	
    	int route1 = distance[0][v1] + distance[1][v2] + distance[2][N];
    	int route2 = distance[0][v2] + distance[2][v1] + distance[1][N];
    	int result = Math.min(route1, route2);
    	
    	if(result < (int)1e8 * 7)	sb.append(result);
    	else 	sb.append(-1);
    	
    	System.out.println(sb);
    	
    	br.close();
    }
}