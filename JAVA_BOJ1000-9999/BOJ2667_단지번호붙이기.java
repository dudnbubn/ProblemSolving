import java.io.*;
import java.util.*;

public class BOJ2667_단지번호붙이기 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N=Integer.parseInt(br.readLine());
		
		int[][] board = new int[N][N];
		int[] result = new int[N*N/2+1];
		for(int i=0;i<result.length;i++)
			result[i] = Integer.MAX_VALUE;
		int index = 0;
		int[] di = {-1, 0, 1, 0};
		int[] dj = {0, 1, 0, -1};
		
		final int HOUSE = 1000_000_000;
		char[] ca;
		for(int i=0;i<N;i++) {
			ca = br.readLine().toCharArray();
			for(int j=0;j<N;j++)
				board[i][j] = ca[j]-'0'+HOUSE;
		}
			
		
		ArrayDeque<int[]> q = new ArrayDeque<>();
		int[] cur;
		int ni, nj;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(board[i][j] == HOUSE + 1) {
					board[i][j] = 0;
					result[index] = 0;
					q.offer(new int[] {i, j});
					while(!q.isEmpty()) {
						cur = q.poll();
						result[index]++;
						for(int d=0;d<4;d++) {
							ni = cur[0] + di[d];
							nj = cur[1] + dj[d];
							
							if(ni<0||ni>=N||nj<0||nj>=N)	continue;
							
							if(board[ni][nj]==HOUSE + 1) {
								board[ni][nj] = 0;
								q.offer(new int[] {ni, nj});
							}
						}
					}
					index++;
				}
			}
		}
		Arrays.sort(result);
		sb.append(index).append('\n');
		for(int i=0;i<index;i++)
			sb.append(result[i]).append('\n');
		
		System.out.println(sb);
		
		br.close();
	}
}
