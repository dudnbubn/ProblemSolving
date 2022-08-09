import java.io.*;
import java.util.*;

public class BOJ1181_단어정렬 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		
		String[] arr = new String[N];
		
		for(int i=0;i<N;i++) 
			arr[i] = br.readLine();
		
		Arrays.sort(arr, (o1, o2) -> {
				int result = o1.length() - o2.length();
				if(result == 0)	result = o1.compareTo(o2);
				return result;
			});
		
		sb.append(arr[0] + '\n');
		for(int i=1;i<N;i++) {
			if(arr[i].equals(arr[i-1]))	continue;
			sb.append(arr[i] + '\n');
		}
		
		System.out.println(sb);
	}

}
