import java.io.*;
import java.util.*;


public class BOJ2164_카드2 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		Deque<Integer> dq = new ArrayDeque<>();
		
		for(int i=1;i<=N;i++)
			dq.add(i);
		
		while(dq.size() > 1) {
			dq.pollFirst();
			dq.add((dq.poll()));
		}
		sb.append(dq.peek());
		
		System.out.println(sb);
		br.close();
	}
	
}
