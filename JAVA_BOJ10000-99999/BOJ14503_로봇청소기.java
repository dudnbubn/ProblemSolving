import java.io.*;
import java.util.*;

public class BOJ14503_로봇청소기 {
	static int N, M, result = 0;
	static int[][] board;
	static boolean[][] visited;
	static int[] di = {-1, 0, 1, 0};
	static int[] dj = {0, 1, 0, -1};
	static void DFS(int i, int j, int dir) {
		if(!visited[i][j]) {
			visited[i][j] = true;
			result++;
		}
		
		int ni, nj, nd = dir;
		for(int d=0;d<4;d++) {
			nd = (nd + 3) % 4;
			ni = i + di[nd];
			nj = j + dj[nd];
			
			if(0<=ni&&ni<N && 0<=nj&&nj<M && board[ni][nj] == 0 && !visited[ni][nj]) { 
				DFS(ni, nj, nd);
				return;
			}
		}
		ni = i - di[dir];	nj = j - dj[dir];
		if(board[ni][nj] == 0)
			DFS(ni, nj, dir);
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		board = new int[N][M];
		visited = new boolean[N][M];
		
		st = new StringTokenizer(br.readLine(), " ");
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=0;j<M;j++)
				board[i][j] = Integer.parseInt(st.nextToken());
		}
		
		DFS(r, c, d);
		
		System.out.println(result);
		br.close();
	}
	
}
