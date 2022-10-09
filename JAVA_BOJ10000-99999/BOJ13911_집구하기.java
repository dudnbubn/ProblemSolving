import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

import org.omg.CORBA.INTERNAL;

public class BOJ13911_집구하기 {
	
	static class Node implements Comparable<Node>{
		long weight;
		int number;
		
		Node(long weight, int number){
			this.weight = weight;
			this.number = number;
		}

		@Override
		public int compareTo(Node o) {
			return Long.compare(this.weight, o.weight);
		}
	}
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	
    	int V = Integer.parseInt(st.nextToken());
    	int E = Integer.parseInt(st.nextToken());
    	
    	ArrayList<int[]>[] adjList = new ArrayList[V+1];
    	boolean[] visited = new boolean[V+1];
    	for(int i=1;i<=V;i++)	adjList[i] = new ArrayList<>();
    	int u,v,w;
    	for(int i=0;i<E;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		u = Integer.parseInt(st.nextToken());
    		v = Integer.parseInt(st.nextToken());
    		w = Integer.parseInt(st.nextToken());
    		adjList[u].add(new int[] {v, w});
    		adjList[v].add(new int[] {u, w});
    	}
    	
    	ArrayList<Integer> mcdonalds = new ArrayList<>();
    	st = new StringTokenizer(br.readLine(), " ");
    	int M = Integer.parseInt(st.nextToken());
    	int x = Integer.parseInt(st.nextToken());
    	st = new StringTokenizer(br.readLine(), " ");
    	for(int i=0;i<M;i++)	mcdonalds.add(Integer.parseInt(st.nextToken()));
    	
    	ArrayList<Integer> starbucks = new ArrayList<>();
    	st = new StringTokenizer(br.readLine(), " ");
    	int S = Integer.parseInt(st.nextToken());
    	int y = Integer.parseInt(st.nextToken());
    	st = new StringTokenizer(br.readLine(), " ");
    	for(int i=0;i<S;i++)	starbucks.add(Integer.parseInt(st.nextToken()));

    	final long INF = 3000000001l;
    	
    	long[] dist_M = new long[V+1];
    	long[] dist_S = new long[V+1];
    	for(int i=1;i<=V;i++)	dist_M[i] = dist_S[i] = INF;
    	
    	PriorityQueue<Node> pq = new PriorityQueue<>();
    	
    	Node cur;
    	long weight;
    	int number;
    	
    	for(int mcdonald : mcdonalds)	pq.offer(new Node(0, mcdonald));
    	while(!pq.isEmpty()) {
    		cur = pq.poll();
    		
    		weight = cur.weight;
    		number = cur.number;
    		if(visited[number])	continue;
    		
    		visited[number] = true;
    		dist_M[number] = weight;
    		
    		for(int[] adj : adjList[number]) {
    			if(visited[adj[0]])	continue;
    			pq.offer(new Node(weight + adj[1], adj[0]));
    		}
    	}
    	
    	for(int i=1;i<=V;i++)	visited[i] = false;
    	for(int starbuck : starbucks)	pq.offer(new Node(0, starbuck));
    	while(!pq.isEmpty()) {
    		cur = pq.poll();
    		
    		weight = cur.weight;
    		number = cur.number;
    		if(visited[number])	continue;
    		
    		visited[number] = true;
    		dist_S[number] = weight;
    		
    		for(int[] adj : adjList[number]) {
    			if(visited[adj[0]])	continue;
    			pq.offer(new Node(weight + adj[1], adj[0]));
    		}
    	}
    	
    	long result = 2 * INF, sum;
    	
    	for(int i=1;i<=V;i++) {
    		if(dist_M[i] > x || dist_S[i] > y)	continue;
    		if(dist_M[i] == 0 || dist_S[i] == 0)	continue;
    		
    		sum = dist_M[i] + dist_S[i];
    		result = result < sum ? result : sum;
    	}
    	System.out.println(result < 2 * INF ? result : -1);
    	
    	br.close();
    }
}