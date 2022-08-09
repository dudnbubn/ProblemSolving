import java.io.*;
import java.util.*;

public class BOJ2751_수정렬하기2 {
	
	static boolean[] check = new boolean[2000001];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		
		for(int i=0;i<N;i++)
			check[Integer.parseInt(br.readLine()) + 1000000] = true;
	
		
		for(int i=0;i<=2000000;i++) {
			if(check[i]) {
				sb.append(i-1000000).append('\n');
			}
		}
		System.out.println(sb.toString());
	}

}
