import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class BOJ17135_캐슬디펜스 {
	
	static int N, M, D, result;
	static int[] archers = new int[3];
	static ArrayList<int[]> enemys;
	
	static int depence(ArrayList<int[]> es) {
		int kill = 0;
		boolean[] killed = new boolean[225];
		
		int distance, index=0, tempDistance;
		int tj=0, ei, ej;
		
		while(!es.isEmpty()) {
			for(int i=0;i<es.size();i++)
				killed[i] = false;
			
			for(int i=0;i<3;i++) {
				distance = tj = Integer.MAX_VALUE;
				index = -1;
				for(int j=0;j<es.size();j++){
					ei = es.get(j)[0];
					ej = es.get(j)[1];
					tempDistance = Math.abs(N+1 - ei) + Math.abs(archers[i] - ej);
					
					if(tempDistance > D)	continue;
					
					if(tempDistance < distance) {
						distance = tempDistance;
						tj = ej;
						index = j;
					}
					else if(tempDistance == distance) {
						if(tj > ej) {
							tj = ej;
							index = j;
						}
					}
				}
				if(index != -1)	killed[index] = true;
			}
			for(int i=es.size()-1;i>=0;i--) {
				ei = es.get(i)[0];
				ej = es.get(i)[1];
				if(killed[i]) {
					kill++;
					es.remove(i);
				}
				else if(ei == N) {
					es.remove(i);
				}
				else {
					es.set(i, new int[] {ei+1, ej});
				}
			}
		}
		
		return kill;
	}
	
	static void comb(int depth, int start) {
		if(depth == 3) {
			ArrayList<int[]> tempEnemys = new ArrayList<>();
			for(int[] e : enemys)
				tempEnemys.add(e);
			
			result = Math.max(result, depence(tempEnemys));
			
			return;
		}
		
		for(int i=start;i<=M;i++) {
			archers[depth] = i;
			comb(depth+1, i+1);
		}
	}
	
    public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	
    	N = Integer.parseInt(st.nextToken());
    	M = Integer.parseInt(st.nextToken());
    	D = Integer.parseInt(st.nextToken());
    	
    	enemys = new ArrayList<>();
    	
    	for(int i=1;i<=N;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		for(int j=1;j<=M;j++) {
    			if(Integer.parseInt(st.nextToken()) == 1)
    				enemys.add(new int[] {i, j});
    		}
    	}
    	comb(0, 1);
    	
    	System.out.println(result);
    	
    	br.close();
    }
}