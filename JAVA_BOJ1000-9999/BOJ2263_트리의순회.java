import java.io.*;
import java.util.*;

public class BOJ2263_트리의순회 {
	
	static StringBuilder sb;
	static int[] inOrder, inIndex, postOrder, postIndex;

	static void preOrder(int is, int ie, int ps, int pe) {
		int root = postOrder[pe];
		sb.append(root).append(' ');
		
		int rIndex = inIndex[root];
		int leftCount = rIndex - is;
		int rightCount = ie - rIndex;
		
		if(leftCount > 0)	preOrder(is, rIndex-1, ps, ps+leftCount-1);
		if(rightCount > 0)	preOrder(rIndex+1, ie, pe - rightCount, pe-1);
		
	}
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	sb = new StringBuilder();
    	StringTokenizer st;
    	
    	int N = Integer.parseInt(br.readLine());
    	inOrder = new int[N+1];
    	inIndex = new int[N+1];
    	postOrder = new int[N+1];
    	postIndex = new int[N+1];
    	
    	st = new StringTokenizer(br.readLine(), " ");
    	for(int i=1;i<=N;i++) {
    		inOrder[i] = Integer.parseInt(st.nextToken());
    		inIndex[inOrder[i]] = i;
    	}
    	st = new StringTokenizer(br.readLine(), " ");
    	for(int i=1;i<=N;i++) {
    		postOrder[i] = Integer.parseInt(st.nextToken());
    		postIndex[postOrder[i]] = i;
    	}
    	
    	preOrder(1, N, 1, N);
    	
    	System.out.println(sb);
    	br.close();
    }
}