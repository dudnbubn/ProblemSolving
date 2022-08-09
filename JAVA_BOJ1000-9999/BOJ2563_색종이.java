import java.io.*;
import java.util.*;

public class BOJ2563_색종이 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		boolean check[][] = new boolean[100][100];
		int r, c;
		for(int n=0;n<N;n++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			c = Integer.parseInt(st.nextToken());
			r = Integer.parseInt(st.nextToken());
			
			for(int i=0;i<10;i++)
				for(int j=0;j<10;j++) 
					check[i+r][j+c] = true;
		}
		
		int result = 0;
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				if(check[i][j])
					result++;
		System.out.println(result);
		br.close();
	}
	
}
