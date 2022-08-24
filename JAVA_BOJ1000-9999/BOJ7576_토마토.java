import java.io.*;
import java.util.*;

public class BOJ7576_토마토 {
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	
    	int M = Integer.parseInt(st.nextToken());
    	int N = Integer.parseInt(st.nextToken());
    	    	
    	int[][] board = new int[N][M];
    	int remain = 0;
    	ArrayDeque<int[]> q = new ArrayDeque<>();
    	for(int i=0;i<N;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		for(int j=0;j<M;j++) {
    			board[i][j] = Integer.parseInt(st.nextToken());
    			if(board[i][j] == 1)	q.offer(new int[] {i, j});
    			else if(board[i][j] == 0)	remain++;
    		}
    	}
    	
    	int[] di = {-1, 0, 1, 0};
    	int[] dj = {0, 1, 0 ,-1};
    	
    	int result = -1;
    	int[] cur;
    	int qsz, ni, nj;
    	while(!q.isEmpty()) {
    		result++;
    		qsz = q.size();
    		for(int sz=0;sz<qsz;sz++) {
    			cur = q.poll();
    			for(int d=0;d<4;d++) {
    				ni = cur[0] + di[d];
    				nj = cur[1] + dj[d];
    				
    				if(ni<0||ni>=N || nj<0||nj>=M)
    					continue;
    				
    				if(board[ni][nj] == 0) {
    					board[ni][nj] = 1;
    					remain--;
    					q.offer(new int[] {ni, nj});
    				}
    			}
    		}
    	}
    	
    	if(remain == 0)	sb.append(result);
    	else 	sb.append(-1);
    	
    	System.out.println(sb);
    	br.close();
    }
}