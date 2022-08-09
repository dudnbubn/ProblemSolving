import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ11660_구간합구하기5 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int[][] arr = new int[N+1][N+1];
		int[][] subsum = new int[N+1][N+1];
		
		for(int i=1;i<=N;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=1;j<=N;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				subsum[i][j] = subsum[i-1][j] + subsum[i][j-1] - subsum[i-1][j-1] + arr[i][j];
			}
		}
		
		
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int x1 = Integer.parseInt(st.nextToken()), y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken()), y2 = Integer.parseInt(st.nextToken());
			
			sb.append(subsum[x2][y2] - subsum[x1-1][y2] - subsum[x2][y1-1] + subsum[x1-1][y1-1]).append('\n');
		}
		
		System.out.println(sb);
	}
}
