import java.io.*;
import java.util.*;

public class BOJ3055_탈출 {
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	
    	int R = Integer.parseInt(st.nextToken());
    	int C = Integer.parseInt(st.nextToken());
    	
    	ArrayDeque<int[]> hedge = new ArrayDeque<>();
    	ArrayDeque<int[]> water = new ArrayDeque<>();
    	
    	char[][] board = new char[R][C];
    	boolean[][] visited = new boolean[R][C];
    	
    	for(int i=0;i<R;i++) {
    		board[i] = br.readLine().toCharArray();
    		for(int j=0;j<C;j++) {
    			if(board[i][j] == '.' || board[i][j] == 'D')	continue;
    			
    			if(board[i][j] == 'S')	hedge.offer(new int[] {i, j});
    			else if(board[i][j] == '*')	water.offer(new int[] {i, j});
    			visited[i][j] = true;
    		}
    	}
    	
    	int[] di = {-1, 0, 1, 0};
    	int[] dj = {0, 1, 0, -1};
    	
    	boolean canMove = true, flag = false;
    	int time = -1;
    	int[] cur;
    	int ni, nj, qsz;
    	while(canMove) {
    		time++;
    		
    		qsz = water.size();
    		for(int sz=0;sz<qsz;sz++) {
    			cur = water.poll();
    			
    			for(int d=0;d<4;d++) {
    				ni = cur[0] + di[d];
    				nj = cur[1] + dj[d];
    				
    				if(ni<0||ni>=R || nj<0||nj>=C)	continue;
    				
    				if(!visited[ni][nj] && board[ni][nj] != 'D') {
    					visited[ni][nj] = true;
    					water.offer(new int[] {ni, nj});
    				}
    			}
    		}
    		
    		canMove = false;
    		qsz = hedge.size();
    		for(int sz=0;sz<qsz;sz++) {
    			canMove = true;
    			cur = hedge.poll();
    			if(board[cur[0]][cur[1]] == 'D') {
    				flag = true;
    				break;
    			}
    			for(int d=0;d<4;d++) {
    				ni = cur[0] + di[d];
    				nj = cur[1] + dj[d];
    				
    				if(ni<0||ni>=R || nj<0||nj>=C)	continue;
    				
    				if(!visited[ni][nj]) {
    					visited[ni][nj] = true;
    					hedge.offer(new int[] {ni, nj});
    				}
    			}
    		}
    		if(flag) break;
    	}
    	
    	if(canMove)	sb.append(time);
    	else	sb.append("KAKTUS");
    	
    	System.out.println(sb);
    	br.close();
    }
}