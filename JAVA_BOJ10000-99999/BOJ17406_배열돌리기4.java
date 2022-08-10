import java.io.*;
import java.util.*;

public class BOJ17406_배열돌리기4 {
	static int N, M, K, result = Integer.MAX_VALUE;
	static boolean[] visited;
	static int[][] oper;
	static int[] di = {-1, 0, 1, 0};
	static int[] dj = {0, 1, 0, -1};
	
	static void operation(int r, int c, int s, int[][] board) {
		int ci, cj, cd, cur, next;
		int ni, nj;
		for(int l=1;l<=s;l++) {
			ci=r-l;	cj=c-l;	cd=1;
			cur = board[ci][cj];
			while(ci != r-l || cj != c-l || cd !=0) {
				ni = ci + di[cd];
				nj = cj + dj[cd];
				
				if(ni<r-l||ni>r+l || nj<c-l||nj>c+l) {
					cd = (cd + 1)%4;
					continue;
				}
				next = board[ni][nj];
				board[ni][nj] = cur;
				cur = next;
				ci = ni;
				cj = nj;
			}
		}
	}
	
	static void perm(int cnt, int[][] board) {
		if(cnt == K) {
			int line;
			for(int i=1;i<=N;i++) {
				line = 0;
				for(int j=1;j<=M;j++) {
					line += board[i][j];
				}
				result = result < line ? result : line;
			}
			return;
		}
		
		int[][] temp;
		for(int k=0;k<K;k++) {
			if(visited[k])	continue;
			visited[k] = true;
			temp = new int[N+1][M+1];
			for(int i=1;i<=N;i++)	
				for(int j=1;j<=M;j++)
				temp[i][j] = board[i][j];
			
			operation(oper[k][0],oper[k][1],oper[k][2],temp);
			perm(cnt+1, temp);
			visited[k] = false;
		}
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        
        int[][] board = new int[N+1][M+1];
        visited = new boolean[K];
        oper = new int[K][3];
        for(int i=1;i<=N;i++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	for(int j=1;j<=M;j++)
        		board[i][j] = Integer.parseInt(st.nextToken());
        }
        for(int k=0;k<K;k++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	for(int i=0;i<3;i++)
        		oper[k][i] = Integer.parseInt(st.nextToken());
        }
        
        perm(0, board);
        System.out.println(result);
        
        br.close();
    }
}