import java.io.*;
import java.util.*;

public class BOJ1704_Z {
	
	static int r, c;
	
	static int Z(int si, int sj, int ei, int ej, int start, int end) {
		if(start == end) {
			return start;
		}
		
		int z2 = (start+end)/2;
		int z1 = (start+z2)/2;
		int z3 = (z2+1+end)/2;
		
		int mi = (si+ei)/2, mj = (sj+ej)/2;
		
		if(r <= mi) {
			if(c <= mj) 	return Z(si, sj, mi, mj, start, z1);
			else 			return Z(si, mj+1, mi, ej, z1+1, z2);
		}
		else {
			if(c <= mj)		return Z(mi+1, sj, ei, mj, z2+1, z3);
			else			return Z(mi+1, mj+1, ei, ej, z3+1, end);
		}
	}
	
    public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	
    	int N = Integer.parseInt(st.nextToken());
    	r = Integer.parseInt(st.nextToken());
    	c = Integer.parseInt(st.nextToken());
    	int sz = 1;
    	for(int i=0;i<N;i++)
    		sz*=2;
    	
    	System.out.println(Z(0, 0, sz-1, sz-1, 0, sz*sz-1));
    	br.close();
    }
}