import java.io.*;
import java.util.*;

public class BOJ4195_친구네트워크 {
	
	static int[] parent = new int[200001];
	static int[] relationSize = new int[200001];
	
	static int Find(int x) {
		if(x == parent[x])	return x;
		return parent[x] = Find(parent[x]);
	}
	
	static void Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		
		parent[y] = x;
		relationSize[x] += relationSize[y];
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		int F, hashValue;
		String a, b;
		for(int tc=1;tc<=T;tc++) {
			HashMap<String, Integer> hm = new HashMap<>();
			hashValue = 0;
			
			F = Integer.parseInt(br.readLine());
			
			for(int i=0;i<=2*F;i++) {
				parent[i] = i;
				relationSize[i] = 0;
			}
			for(int f=0;f<F;f++) {
				st = new StringTokenizer(br.readLine(), " ");
				a = st.nextToken();
				b = st.nextToken();
				
				if(!hm.containsKey(a)) {
					hm.put(a, hashValue++);
					relationSize[hm.get(a)] = 1;
				}
				if(!hm.containsKey(b)) {
					hm.put(b, hashValue++);
					relationSize[hm.get(b)] = 1;
				}
				
				if(Find(hm.get(a)) != Find(hm.get(b)))
					Union(hm.get(a), hm.get(b));
				
				sb.append(relationSize[Find(hm.get(a))]).append('\n');
			}
		}
		System.out.println(sb);
		br.close();
	}
		
}