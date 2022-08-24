import java.io.*;
import java.util.*;

public class BOJ10026_적록색약 {
	
	static void BFS(boolean blind, int i, int j, char[][] board, boolean[][] visited, int[] di, int[] dj) {
		ArrayDeque<int[]> q = new ArrayDeque<>();
		q.offer(new int[] {i, j});
		visited[i][j] = true;
		
		char color = board[i][j];
		int[] cur;
		int N = board.length, ni, nj;
		while(!q.isEmpty()) {
			cur = q.poll();
			i = cur[0];
			j = cur[1];
			
			for(int d=0;d<4;d++) {
				ni = i + di[d];
				nj = j + dj[d];
				
				if(ni < 0 || ni >= N || nj < 0 || nj >= N)
					continue;
				
				if(!visited[ni][nj]) {
					if(color == board[ni][nj]) {
						visited[ni][nj] = true;
						q.offer(new int[] {ni, nj});
					}
					else if(blind && (color == 'R' || color == 'G') && (board[ni][nj] == 'R' || board[ni][nj] == 'G')) {
						visited[ni][nj] = true;
						q.offer(new int[] {ni, nj});
					}
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st;
    	
    	int N = Integer.parseInt(br.readLine());
    	char[][] board = new char[N][N];
    	boolean[][] visited = new boolean[N][N];
    	int[] di = { -1, 0, 1, 0};
    	int[] dj = { 0, 1, 0, -1};
    	for(int i=0;i<N;i++) board[i] = br.readLine().toCharArray();
    	
    	int blind = 0;
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<N;j++) {
    			if(!visited[i][j]) {
    				BFS(true, i, j, board, visited, di, dj);
    				blind++;
    			}
    		}
    	}
    	for(boolean[] v : visited)	Arrays.fill(v, false);
    	int nonBlind = 0;
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<N;j++) {
    			if(!visited[i][j]) {
    				BFS(false, i, j, board, visited, di, dj);
    				nonBlind++;
    			}
    		}
    	}
    	sb.append(nonBlind).append(' ').append(blind);
    	System.out.println(sb);
    	br.close();
    }
}