import java.io.*;
import java.util.*;

public class BOJ15683_감시 {
	static int N, M, cctv_cnt;
	static int[][] cctvs = new int[8][3];
	static int[] di = {-1, 0, 1, 0};
	static int[] dj = {0, 1, 0, -1};
	static int[][] direction = {{1}, {1, 3}, {0, 1}, {0, 1, 3}, {0, 1, 2, 3}};
	static int result = 64;
	
	static void check(int cctv_num, int dir, int[][] board) {
		int ci = cctvs[cctv_num][0];
		int cj = cctvs[cctv_num][1];
		int cctv = cctvs[cctv_num][2] - 1;
		
		int ni, nj;
		for(int d=0;d<direction[cctv].length;d++) {
			ni = ci + di[(direction[cctv][d] + dir) % 4];
			nj = cj + dj[(direction[cctv][d] + dir) % 4];
			while(0<=ni&ni<N && 0<=nj&&nj<M && board[ni][nj] < 6) {
				if(board[ni][nj] == 0) 
					board[ni][nj] = -1;
				ni += di[(direction[cctv][d] + dir) % 4];
				nj += dj[(direction[cctv][d] + dir) % 4];
			}
		}
	}
	
	static void recur(int cnt, int[][] board) {
		if(cnt == cctv_cnt) {
			int ret = 0;
			for(int i=0;i<N;i++) 
				for(int j=0;j<M;j++) 
					if(board[i][j] == 0)
						ret++;
			result = result < ret ? result : ret;
			return;
		}
		
		
		for(int d=0;d<4;d++) {
			int[][] temp = new int[N][M];
			for(int i=0;i<N;i++)
				for(int j=0;j<M;j++)
					temp[i][j] = board[i][j];
			
			check(cnt, d, temp);
			recur(cnt+1, temp);
		}
		
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken()); 
		M = Integer.parseInt(st.nextToken());
		int[][] board = new int[N][M];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=0;j<M;j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if(0 < board[i][j] && board[i][j] < 6) {
					cctvs[cctv_cnt][0] = i;
					cctvs[cctv_cnt][1] = j;
					cctvs[cctv_cnt][2] = board[i][j];
					cctv_cnt++;
				}
			}
		}
		recur(0, board);
		System.out.println(result);
		br.close();
	}
	
}
