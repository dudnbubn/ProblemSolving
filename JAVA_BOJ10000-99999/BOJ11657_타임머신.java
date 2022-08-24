import java.io.*;
import java.util.*;

public class BOJ11657_타임머신 {
	
	static int N;
	static long[] result;
	static ArrayList<int[]> edges;
	
	static boolean BellmanFord(int start) {
		boolean res = true;
		
		result[start] = 0;
		int A,B,C;
		for(int i=0;i<N-1;i++) {
			for(int[] e : edges) {
				A = e[0];
				B = e[1];
				C = e[2];
				if(result[A] == Integer.MAX_VALUE)	continue;
				if(result[B] > result[A] + C) {
					result[B] = result[A] + C;
				}
			}
		}
		
		for(int[] e : edges) {
			A = e[0];
			B = e[1];
			C = e[2];
			if(result[A] == Integer.MAX_VALUE)	continue;
			if(result[B] > result[A] + C) {
				res = false;
				result[B] = result[A] + C;
			}
		}
		
		return res;
	}
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	
    	N = Integer.parseInt(st.nextToken());
    	int M = Integer.parseInt(st.nextToken());
    	
    	result = new long[N+1];
    	for(int i=1;i<=N;i++) result[i] = Integer.MAX_VALUE;
    	
    	edges = new ArrayList<>();
    	int A,B,C;
    	for(int i=1;i<=M;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		A = Integer.parseInt(st.nextToken());
    		B = Integer.parseInt(st.nextToken());
    		C = Integer.parseInt(st.nextToken());
    		edges.add(new int[] {A,B,C});
    	}
    
    	if(BellmanFord(1)) {
    		for(int i=2;i<=N;i++)
    			sb.append(result[i] == Integer.MAX_VALUE ? -1 : result[i]).append('\n');
    	}
    	else
    		sb.append(-1);
    	
    	System.out.println(sb);
    	br.close();
    }
}