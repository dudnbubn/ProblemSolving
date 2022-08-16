import java.io.*;
import java.util.*;

import org.omg.CORBA.INTERNAL;
public class BOJ2961_도영이가만든맛있는음식 {
	
	static int N;
	static int[] S;
	static int[] B;
	static int result = Integer.MAX_VALUE;
	
	static void subs(int depth, int s, int b) {
		if(depth == N) {
			result = Math.min(result, Math.abs(s-b));
			return;
		}
		
		subs(depth+1, s*S[depth], b+B[depth]);
		subs(depth+1, s, b);
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        S = new int[N];
        B = new int[N];
        
        for(int i=0;i<N;i++) {
        	st = new StringTokenizer(br.readLine(), " ");
        	S[i] = Integer.parseInt(st.nextToken());
        	B[i] = Integer.parseInt(st.nextToken());
        }
        
        for(int i=0;i<N;i++) 
        	subs(i+1, S[i], B[i]);
        
        System.out.println(result);
        
        br.close();
    }
}