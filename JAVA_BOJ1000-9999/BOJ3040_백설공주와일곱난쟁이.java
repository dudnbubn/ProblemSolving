import java.io.*;
import java.util.*;

public class BOJ3040_백설공주와일곱난쟁이 {
	
	static StringBuilder sb = new StringBuilder();
	static int[] dwarfs = new int[9];
	static int[] selected = new int[7];
	
	static void comb(int depth, int start, int sum) {
		if(depth == 7) {
			if(sum == 100) {
				for(int i=0;i<7;i++) {
					sb.append(selected[i]).append('\n');
				}
				System.out.println(sb);
				System.exit(0);
			}
			return;
		}
		
		for(int i=start;i<9;i++) {
			selected[depth] = dwarfs[i];
			comb(depth+1, i+1, sum + dwarfs[i]);
		}
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        
        for(int i=0;i<9;i++) 
        	dwarfs[i] = Integer.parseInt(br.readLine());
      
        comb(0, 0, 0);
        
        br.close();
    }
}