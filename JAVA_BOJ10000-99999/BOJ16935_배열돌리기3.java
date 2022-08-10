import java.io.*;
import java.util.*;

public class BOJ16935_배열돌리기3 {
	static int N, M, rot, ei, ej;
	static int[][] board = new int[101][101];
	static int[] di = {-1, 0, 1, 0};
	static int[] dj = {0, 1, 0, -1};
	
	static void rotation(int cmd) {
		if(rot == 0) {
    		ei=N;	ej=M;
    	}
    	else 	{
    		ei=M;	ej=N;
    	}
		int[][] temp = new int[ei+1][ej+1];
		for(int i=1;i<=ei;i++)
			for(int j=1;j<=ej;j++)
				temp[i][j] = board[i][j];
		
		if(cmd == 1) {
			for(int i=1;i<=ei;i++) 
				for(int j=1;j<=ej;j++) 
					board[ei-i+1][j] = temp[i][j];
		}
		else if(cmd == 2) {
			for(int i=1;i<=ei;i++) 
				for(int j=1;j<=ej;j++)
					board[i][ej-j+1] = temp[i][j];
		}
		else if(cmd == 3) {
			rot = (rot + 1) % 2;
			for(int i=1;i<=ei;i++) 
				for(int j=1;j<=ej;j++) 
					board[j][ei-i+1] = temp[i][j];
		}
		else if(cmd == 4) {
			rot = (rot + 1) % 2;
			for(int i=1;i<=ei;i++) 
				for(int j=1;j<=ej;j++) 
					board[ej-j+1][i] = temp[i][j];
			
		}
		else if(cmd == 5) {
			int si=ei/2, sj=ej/2;
			for(int i=1;i<=si;i++) 
				for(int j=1;j<=sj;j++)
					board[i][j+sj] = temp[i][j];
			for(int i=1;i<=si;i++)
				for(int j=sj+1;j<=ej;j++)
					board[i+si][j] = temp[i][j];
			for(int i=si+1;i<=ei;i++)
				for(int j=sj+1;j<=ej;j++)
					board[i][j-sj] = temp[i][j];
			for(int i=si+1;i<=ei;i++) 
				for(int j=1;j<=sj;j++)
					board[i-si][j] = temp[i][j];
		}
		else {
			int si=ei/2, sj=ej/2;
			for(int i=1;i<=si;i++) 
				for(int j=1;j<=sj;j++)
					board[i+si][j] = temp[i][j];
			for(int i=1;i<=si;i++)
				for(int j=sj+1;j<=ej;j++)
					board[i][j-sj] = temp[i][j];
			for(int i=si+1;i<=ei;i++)
				for(int j=sj+1;j<=ej;j++)
					board[i-si][j] = temp[i][j];
			for(int i=si+1;i<=ei;i++) 
				for(int j=1;j<=sj;j++)
					board[i][j+sj] = temp[i][j];
		}
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        
        for(int i=1;i<=N;i++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	for(int j=1;j<=M;j++)
        		board[i][j] = Integer.parseInt(st.nextToken());
        }
        
        st = new StringTokenizer(br.readLine(), " ");
        int cmd, ei=N, ej=M;
        for(int r=0;r<R;r++) {
        	cmd = Integer.parseInt(st.nextToken());
        	rotation(cmd);
        }
        
        if(rot == 0) {
    		ei=N;	ej=M;
    	}
    	else 	{
    		ei=M;	ej=N;
    	}
        for(int i=1;i<=ei;i++) {
        	for(int j=1;j<=ej;j++)
        		sb.append(board[i][j]).append(' ');
        	sb.append('\n');
        }
        System.out.println(sb);
        br.close();
    }
}