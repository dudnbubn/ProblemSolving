import java.io.*;
import java.util.*;

public class BOJ17070_파이프옮기기1 {
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        
        int N = Integer.parseInt(br.readLine());
        int[][] board = new int[N+1][N+1];
        int[][][] dp = new int[N+1][N+1][3];
        
        for(int i=1;i<=N;i++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	for(int j=1;j<=N;j++)
        		board[i][j] = Integer.parseInt(st.nextToken());
        }
        dp[1][2][0] = 1;
        for(int i=1;i<=N;i++) {
        	for(int j=1;j<=N;j++) {
        		if(board[i][j] == 1)	continue;
        		
        		dp[i][j][0] += dp[i][j-1][0] + dp[i][j-1][1];
        		dp[i][j][2] += dp[i-1][j][2] + dp[i-1][j][1];
        		if(board[i-1][j] != 1 && board[i][j-1] != 1)
        			dp[i][j][1] += dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
        	}
        }

        System.out.println(dp[N][N][0]+dp[N][N][1]+dp[N][N][2]);
        
        br.close();
    }
}