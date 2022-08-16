import java.io.*;
import java.util.*;

public class BOJ15686_치킨배달 {
	
	static int N,M,hIndex,cIndex, result = Integer.MAX_VALUE;
	static int[][] chicken = new int[13][2];
	static int[][] home;
	static boolean[] selected = new boolean[13];
	
	static void comb(int depth, int start) {
		if(depth == M) {
			int[] dist = new int[2*N];
			for(int i=0;i<2*N;i++)
				dist[i] = Integer.MAX_VALUE;
			
			for(int i=0;i<cIndex;i++) {
				if(!selected[i])	continue;
				for(int j=0;j<hIndex;j++) {
					dist[j] = Math.min(dist[j], Math.abs(chicken[i][0]-home[j][0]) + Math.abs(chicken[i][1]-home[j][1]));
				}
			}
			int res = 0;
			for(int i=0;i<hIndex;i++)
				res += dist[i];
			
			result = result < res ? result : res;
			return;
		}
		
		for(int i=start;i<cIndex;i++) {
			selected[i] = true;
			comb(depth+1, i+1);
			selected[i] = false;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		home = new int[2*N][2];
		
		int num;
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=0;j<N;j++) {
				num = Integer.parseInt(st.nextToken());
				if(num == 2) {
					chicken[cIndex][0] = i;
					chicken[cIndex][1] = j;
					cIndex++;
				}
				else if(num==1) {
					home[hIndex][0] = i;
					home[hIndex][1] = j;
					hIndex++;
				}
			}
		}
		
		comb(0,0);
		
		System.out.println(result);
		
		br.close();
	}
}
