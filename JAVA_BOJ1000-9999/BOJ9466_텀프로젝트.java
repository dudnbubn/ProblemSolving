import java.io.*;
import java.util.*;

public class BOJ9466_텀프로젝트 {
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st;
    	
    	int T=Integer.parseInt(br.readLine());
    	int N;
    	int[] degrees, nexts;
    	while(T-- > 0) {
    		N=Integer.parseInt(br.readLine());
    		degrees = new int[N+1];
    		nexts = new int[N+1];
    		
    		st = new StringTokenizer(br.readLine(), " ");
    		for(int i=1;i<=N;i++) {
    			nexts[i] = Integer.parseInt(st.nextToken());
    			degrees[nexts[i]]++;
    		}
    		
    		int result = 0;
    		ArrayDeque<Integer> q = new ArrayDeque<>();
    		for(int i=1;i<=N;i++) 
    			if(degrees[i] == 0)
    				q.offer(i);
    		
    		int cur, next;
    		while(!q.isEmpty()) {
    			cur = q.poll();
    			result++;
    			
    			next = nexts[cur];
    			degrees[next]--;
    			if(degrees[next] == 0)
    				q.offer(next);
    		}
    		
    		sb.append(result).append('\n');
    	}
    	
    	System.out.println(sb);
    	br.close();
    }
}