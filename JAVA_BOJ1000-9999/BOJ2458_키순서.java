import java.io.*;
import java.util.*;

public class BOJ2458_키순서 {
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	
    	int N = Integer.parseInt(st.nextToken());
    	int M = Integer.parseInt(st.nextToken());
    	
    	ArrayList<Integer>[] adjList = new ArrayList[N+1];
    	for(int i=1;i<=N;i++)	adjList[i] = new ArrayList<>();
    	boolean[] visited = new boolean[N+1];
    	
    	int a, b;
    	for(int i=0;i<M;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		a = Integer.parseInt(st.nextToken());
    		b = Integer.parseInt(st.nextToken());
    		adjList[a].add(b);
    	}
    	
    	int[] bigger = new int[N+1];
    	int[] smaller = new int[N+1];
    	ArrayDeque<Integer> q = new ArrayDeque<>();
    	for(int i=1;i<=N;i++) {
    		for(int j=1;j<=N;j++)	visited[j] = false;
    		q.offer(i);
    		visited[i] = true;
    		bigger[i] = -1;
    		
    		int cur;
    		while(!q.isEmpty()) {
    			cur = q.poll();
    			bigger[i]++;
    			for(int adj : adjList[cur]) {
    				if(visited[adj])	continue;
    				visited[adj] = true;
    				smaller[adj]++;
    				q.offer(adj);
    			}
    		}
    	}
    	
    	int result = 0;
    	for(int i=1;i<=N;i++) {
    		if(smaller[i] + bigger[i] == N-1)
    			result++;
    	}
    	System.out.println(result);
    	br.close();
    }
}