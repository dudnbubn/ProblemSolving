import java.io.*;
import java.util.*;

public class BOJ7568_덩치 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		String[] input;
		int N = Integer.parseInt(br.readLine());
		int[] x = new int[50];
		int[] y = new int[50];
		for(int i=0;i<N;i++) {
			input = br.readLine().split(" ");
			x[i] = Integer.parseInt(input[0]);
			y[i] = Integer.parseInt(input[1]);
		}
		int result = 0;
		for(int i=0;i<N;i++) {
			result = 1;
			for(int j=0;j<N;j++) {
				if(i==j)	continue;
				if(x[i] < x[j] && y[i] < y[j])
					result++;
			}
			sb.append(result + " ");
		}
		System.out.println(sb);
	}

}
