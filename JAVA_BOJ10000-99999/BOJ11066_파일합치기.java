import java.io.*;
import java.util.*;

public class BOJ11066_파일합치기 {
	
	static int[] subsum;
	static int[][] dp;
	
	static int cost(int start, int end) {
		if(start == end)	return 0;
		if(dp[start][end] != 0)	return dp[start][end];
		
		int result = Integer.MAX_VALUE;
		
		for(int i=start;i<end;i++) 
			result = Math.min(result, subsum[end] - subsum[start-1] + cost(start, i) + cost(i+1, end));
		
		return dp[start][end] = result;
	}
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st;
    	
    	int T = Integer.parseInt(br.readLine());
    	for(int tc=1;tc<=T;tc++) {
    		int K = Integer.parseInt(br.readLine());
    		subsum = new int[K+1];
    		dp = new int[K+1][K+1];
    		
    		
    		st = new StringTokenizer(br.readLine(), " ");
    		for(int i=1;i<=K;i++)	subsum[i] = subsum[i-1] + Integer.parseInt(st.nextToken());
    		
    		sb.append(cost(1, K)).append('\n');
    	}
    	System.out.println(sb);
    	br.close();
    }
}