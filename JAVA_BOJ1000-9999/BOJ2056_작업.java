import java.io.*;
import java.util.*;

public class BOJ2056_작업 {
	
    public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st;
    	
    	int N = Integer.parseInt(br.readLine());
    	int[] time = new int[N+1];
    	ArrayList<Integer>[] pre = new ArrayList[N+1];
    	for(int i=1;i<=N;i++) {
    		pre[i] = new ArrayList<>();
    		st = new StringTokenizer(br.readLine(), " ");
    		time[i] = Integer.parseInt(st.nextToken());
    		
    		int cnt = Integer.parseInt(st.nextToken());
    		for(int j=0;j<cnt;j++) 
    			pre[i].add(Integer.parseInt(st.nextToken()));
    		
    	}
    	
    	int result = 0;
    	int[] dp = new int[N+1];
    	
    	for(int i=1;i<=N;i++) {
    		for(int p : pre[i]) 
    			dp[i] = Math.max(dp[i], dp[p]);
    		dp[i] += time[i];
    		result = result > dp[i] ? result : dp[i];
    	}
    	
    	sb.append(result);
    	System.out.println(sb);
    	
    	br.close();
    }
}