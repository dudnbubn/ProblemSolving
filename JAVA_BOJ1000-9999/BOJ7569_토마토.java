import java.io.*;
import java.util.*;

public class BOJ7569_토마토 {
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        
        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(st.nextToken());
        
        int[][][] board = new int[N][M][H];
        int[] di = {-1, 0, 1, 0 ,0 ,0};
        int[] dj = {0 ,1 ,0 ,-1, 0, 0};
        int[] dk = {0, 0, 0, 0, 1, -1};
        
        ArrayDeque<int[]> q = new ArrayDeque<>();
        
        for(int k=0;k<H;k++) {
        	for(int i=0;i<N;i++) {
        		st = new StringTokenizer(br.readLine(), " ");
        		for(int j=0;j<M;j++) {
        			board[i][j][k] = Integer.parseInt(st.nextToken());
        			if(board[i][j][k] == 1) {
	        			q.offer(new int[] {i, j, k});
        			}
        		}
        	}
        }
        
        int[] cur;
        int t, qsz;
        int ni, nj, nk;
        
        if(q.isEmpty())	t = 0;
        else t = -1;
        
        while(!q.isEmpty()) {
        	t++;
        	qsz=q.size();
        	for(int sz=0;sz<qsz;sz++) {
        		cur = q.poll();
	        	for(int d=0;d<6;d++) {
	        		ni = cur[0] + di[d];
	        		nj = cur[1] + dj[d];
	        		nk = cur[2] + dk[d];
	        		
	        		if(ni<0||ni>=N || nj<0||nj>=M || nk<0||nk>=H)
	        			continue;
	        		
	        		if(board[ni][nj][nk] == 0) {
	        			board[ni][nj][nk] = 1;
	        			q.offer(new int[] {ni, nj, nk});
	        		}
	        	}
        	}
        }
        
        boolean remain = false;
        for(int i=0;i<N;i++) {
        	for(int j=0;j<M;j++) {
        		for(int k=0;k<H;k++) {
        			if(board[i][j][k] == 0) {
        				remain = true;
        				break;
        			}
        		}
        		if(remain)	break;
        	}
        	if(remain)	break;
        }
        
        if(remain)	System.out.println(-1);
        else 	System.out.println(t);
        
        br.close();
    }
}