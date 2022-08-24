import java.io.*;
import java.util.*;

public class BOJ17472_다리만들기2 {
	
	static int N, M;
	static int[][] board;
	static int[] di = {-1, 0, 1, 0};
	static int[] dj = { 0, 1, 0, -1};
	static int[] parent;
	
	static ArrayList<int[]> adjSea = new ArrayList<>();
	
	static void BFS(int si, int sj, int island) {
		ArrayDeque<int[]> q = new ArrayDeque<>();
		q.offer(new int[] {si, sj});
		board[si][sj] = island;
		
		int[] cur;
		int ni, nj;
		while(!q.isEmpty()) {
			cur = q.poll();
			si = cur[0];
			sj = cur[1];
			
			for(int d=0;d<4;d++) {
				ni = si + di[d];
				nj = sj + dj[d];
				
				if(ni < 1 || ni > N || nj < 1 || nj > M)
					continue;
				
				if(board[ni][nj] == 1) {
					board[ni][nj] = island;
					q.offer(new int[] {ni, nj});
				}
				else if(board[ni][nj] == 0) {
					adjSea.add(new int[] {ni, nj, d, island});
				}
			}
		}
	}
	
	static int find(int x) {
		if(x == parent[x])	return x;
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
    	
    	N = Integer.parseInt(st.nextToken());
    	M = Integer.parseInt(st.nextToken());
    	
    	board = new int[N+1][M+1];
    	
    	for(int i=1;i<=N;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		for(int j=1;j<=M;j++)
    			board[i][j] = Integer.parseInt(st.nextToken());
    	}
    	
    	int island = 1;
    	for(int i=1;i<=N;i++) {
    		for(int j=1;j<=M;j++) {
    			if(board[i][j] == 1) 
    				BFS(i, j, ++island);
    		}
    	}
    	
    	parent = new int[island+1];
    	for(int i=2;i<=island;i++)	parent[i] = i;
    	
    	PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2)-> {
    		return Integer.compare(o1[0], o2[0]);
    	});
    	
    	for(int[] sea : adjSea) {
    		int d = sea[2];
    		int i = sea[0];
    		int j = sea[1];
    		int is = sea[3];
    		int len = 0;
    		while(1<=i&&i<=N && 1<=j&&j<=M) {
    			if(board[i][j] > 1) {
    				if(len > 1 && board[i][j] != is) {
	    				pq.offer(new int[] {len, is, board[i][j]});
    				}
    				break;
    			}
    			i += di[d];
    			j += dj[d];
    			len++;
    		}
    	}
    	
    	int result = 0, x, y;
    	int[] edge;
    	for(int i=0;i<island-2;) {
    		if(pq.isEmpty()) {
    			result = -1;
    			break;
    		}
    		edge = pq.poll();
    		x = edge[1];
    		y = edge[2];
    		
    		if(find(x) != find(y)) {
    			result += edge[0];
    			union(x, y);
    			i++;
    		}
    	}
    	
    	
    	System.out.println(result);
    	br.close();
    }
}