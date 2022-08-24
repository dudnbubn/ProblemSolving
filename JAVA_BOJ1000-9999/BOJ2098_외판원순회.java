import java.io.*;
import java.util.*;

import org.omg.CORBA.INTERNAL;
public class BOJ2098_외판원순회 {
	
	static int N;
	static int[][] W;
	static int[][] dp;
	static final int MAX_VALUE = (int)1e9;
	
	static int TSP(int state, int cur) {
		state |= (1<<cur);
		
		if(state == (1<<N)-1)	{
			if(W[cur][0] > 0)
				return W[cur][0];
			else
				return MAX_VALUE;
		}
		
		if(dp[state][cur] > 0)	return dp[state][cur];
		
		dp[state][cur] = MAX_VALUE;
		
		for(int i=0;i<N;i++) {
			if(i == cur)	continue;
			
			if((state&(1<<i)) == 0 && W[cur][i] != 0)	
				dp[state][cur] = Math.min(dp[state][cur], TSP(state, i) + W[cur][i]);
		}
		
		return dp[state][cur];
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        W = new int[N][N];
        dp = new int[1<<N][N];
        
        for(int i=0;i<N;i++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	for(int j=0;j<N;j++)
        		W[i][j] = Integer.parseInt(st.nextToken());
        }
        
        System.out.println(TSP(0, 0));
        
        br.close();
    }
}