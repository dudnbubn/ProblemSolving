import java.io.*;
import java.util.*;

public class BOJ2630_색종이만들기 {
	static int[][] board;
	static int blue, white;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		board = new int[N+1][N+1];
		
		StringTokenizer st;
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=1;j<=N;j++)
				board[i][j] = Integer.parseInt(st.nextToken());
		}
		recur(1, 1, N, N);
		
		sb.append(white).append('\n').append(blue);
		
		System.out.println(sb);
	}
	
	static void recur(int si, int sj, int ei, int ej) {
		int color = board[si][sj];
		boolean flag = true;
		
		for(int i=si;i<=ei;i++) {
			for(int j=sj;j<=ej;j++) {
				if(board[i][j] != color) {
					flag = false;
					break;
				}
			}
			if(!flag)	break;
		}
		
		if(flag) {
			if(color == 1)	blue++;
			else 	white++;
		}
		else {
			recur(si, sj, (si+ei)/2, (sj+ej)/2);
			recur(si, (sj+ej)/2 + 1, (si+ei)/2, ej);
			recur((si+ei)/2 + 1, sj, ei, (sj+ej)/2);
			recur((si+ei)/2 + 1, (sj+ej)/2 + 1, ei, ej);
		}
	}
}
