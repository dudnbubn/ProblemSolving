import java.io.*;
import java.util.*;

public class BOJ1065_한수 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		
		int result = 0;
		for(int i=1;i<=N;i++) {
			if(isHansu(i))
				result++;
		}
		sb.append(result);
		System.out.println(sb);
	}
	
	static boolean isHansu(int num) {
		int d = ((num/10) % 10) - (num % 10) ;
		num /= 10;
		while(num >= 10) {
			if(((num/10) % 10) - (num % 10) != d) 
				return false;
			num /= 10;
		}
		return true;
	}
}
