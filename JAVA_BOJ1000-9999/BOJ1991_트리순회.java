import java.io.*;
import java.util.*;

public class BOJ1991_트리순회 {
	
	static StringBuilder sb;
	static char[][] children;
	
	static void preOrder(int node) {
		sb.append((char)(node+'A'));
		if(children[node][0] != '.')	preOrder(children[node][0] - 'A');
		if(children[node][1] != '.')	preOrder(children[node][1] - 'A');
	}
	static void inOrder(int node) {
		if(children[node][0] != '.')	inOrder(children[node][0] - 'A');
		sb.append((char)(node+'A'));
		if(children[node][1] != '.')	inOrder(children[node][1] - 'A');
	}
	static void postOrder(int node) {
		if(children[node][0] != '.')	postOrder(children[node][0] - 'A');
		if(children[node][1] != '.')	postOrder(children[node][1] - 'A');
		sb.append((char)(node+'A'));
	}
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	sb = new StringBuilder();
    	StringTokenizer st;
    	
    	int N = Integer.parseInt(br.readLine());
    	children = new char[N][2];
    	for(int i=0;i<N;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		char parent = st.nextToken().charAt(0);
    		for(int j=0;j<2;j++)
    			children[parent-'A'][j] = st.nextToken().charAt(0);
    	}
    	
    	preOrder(0);
    	sb.append('\n');
    	inOrder(0);
    	sb.append('\n');
    	postOrder(0);
    	
    	
    	System.out.println(sb);
    	br.close();
    }
}