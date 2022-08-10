import java.io.*;
import java.util.*;

public class BOJ16926_배열돌리기1 {
	static int N, M, R;
	static int[][] board;
	static int[] di = {-1, 0, 1, 0};
	static int[] dj = {0, 1, 0, -1};
	
	static void rotation() {
		int si=1, sj=1, ei=N, ej=M;
		int temp;
		
		while(si <= ei && sj <= ej) {
			temp = board[si][sj];
			if(si == ei) {
				for(int j=sj;j<ej;j++)	board[si][j] = board[si][j+1];
				board[si][ej] = temp;
			}
			else if(sj == ej) {
				for(int i=si;i<ei;i++)	board[i][sj] = board[i+1][sj];
				board[ei][sj] = temp;
			}
			else {
				for(int j=sj;j<ej;j++)	board[si][j] = board[si][j+1];
				for(int i=si;i<ei;i++)	board[i][ej] = board[i+1][ej];
				for(int j=ej;j>sj;j--)	board[ei][j] = board[ei][j-1];
				for(int i=ei;i>si+1;i--)	board[i][sj] = board[i-1][sj];
				board[si+1][sj] = temp;
			}
			si++;	sj++;
			ei--;	ej--;
		}
		
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        
        board = new int[N+1][M+1];
        for(int i=1;i<=N;i++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	for(int j=1;j<=M;j++)
        		board[i][j] = Integer.parseInt(st.nextToken());
        }
        
        for(int i=0;i<R;i++)
        	rotation();
        
        for(int i=1;i<=N;i++) {
        	for(int j=1;j<=M;j++)
        		sb.append(board[i][j]).append(' ');
        	sb.append('\n');
        }
        System.out.println(sb);
        br.close();
    }
}