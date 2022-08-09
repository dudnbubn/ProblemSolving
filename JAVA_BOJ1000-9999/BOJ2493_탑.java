import java.io.*;
import java.util.*;

public class BOJ2493_탑 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		Stack<int[]> stk = new Stack<>();
		
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int top;
		int[] ti;
		for(int i=1;i<=N;i++) {
			top = Integer.parseInt(st.nextToken());
			ti = new int[]{top, i};
			while(!stk.isEmpty() && stk.peek()[0] <= top)
				stk.pop();
			
			if(stk.isEmpty())	sb.append(0).append(' ');
			else 	sb.append(stk.peek()[1]).append(' ');
			
			stk.push(ti);
		}
		
		System.out.println(sb);
		br.close();
	}
	
}
