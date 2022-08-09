import java.io.*;
import java.util.*;


public class BOJ1158_요세푸스문제 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken()) - 1;
		ArrayList<Integer> al = new ArrayList<>();
		for(int i=1;i<=N;i++)
			al.add(i);
		
		sb.append('<');
		int index = 0;
		while(al.size() > 0) {
			index = (index + K) % al.size();
			sb.append(al.remove(index));
			if(al.size() > 0)
				sb.append(", ");
		}
		
		sb.append('>');
		System.out.println(sb);
		br.close();
	}
	
}
