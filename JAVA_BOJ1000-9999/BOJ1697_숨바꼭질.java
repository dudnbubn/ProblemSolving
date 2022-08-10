import java.io.*;
import java.util.*;

public class BOJ1697_숨바꼭질 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		boolean[] visited = new boolean[100001];
		ArrayDeque<Integer> q = new ArrayDeque<>();
		
		q.offer(N);
		visited[N]=true;
		int t=-1, qsz, cur;
		while(!q.isEmpty()) {
			t++;
			qsz = q.size();
			for(int sz=0;sz<qsz;sz++) {
				cur = q.poll();
				
				if(cur == K) {
					System.out.println(t);
					System.exit(0);
				}
				
				if(cur <= 50000 && !visited[cur*2])	{
					visited[cur*2] = true;
					q.offer(cur*2);
				}
				if(cur+1 <= K && !visited[cur+1])	{
					visited[cur+1] = true;
					q.offer(cur+1);
				}
				if(cur-1 >= 0 && !visited[cur-1])	{
					visited[cur-1] = true;
					q.offer(cur-1);
				}
			}
		}
		br.close();
	}
}
