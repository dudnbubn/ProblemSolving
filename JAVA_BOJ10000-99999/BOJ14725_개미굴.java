import java.io.*;
import java.util.*;

public class BOJ14725_개미굴 {
	
	static StringBuilder sb;
	
	static class Node implements Comparable<Node>{
		String name;
		ArrayList<Node> children;
		
		Node(String name){
			this.name = name;
			this.children = new ArrayList<>();
		}

		@Override
		public int compareTo(Node o) {
			return this.name.compareTo(o.name);
		}
	}
	
	static void recur(Node node, String under) {
		sb.append(under + node.name).append('\n');
		Collections.sort(node.children);
		for(Node n : node.children) 
			recur(n, under+"--");
	}
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	sb = new StringBuilder();
    	StringTokenizer st;
    	
    	int N = Integer.parseInt(br.readLine());
    	int K;
    	
    	String input;
    	Node cur = null;
    	boolean flag;
    	ArrayList<Node> nodeList = new ArrayList<>();
    	ArrayList<Node> children;
    	for(int i=1;i<=N;i++) {
    		st = new StringTokenizer(br.readLine(), " ");
    		K = Integer.parseInt(st.nextToken());
    		children = nodeList;
    		for(int k=0;k<K;k++) {
    			flag = false;
    			input = st.nextToken();
	    		for(Node n : children) {
	    			if(n.name.equals(input)) {
	    				cur = n;
	    				flag = true;
	    				break;
	    			}
	    		}
	    		
	    		if(!flag) {
	    			cur = new Node(input);
	    			children.add(cur);
	    		}
    			children = cur.children;
    		}
    	}
    	
    	Collections.sort(nodeList);
    	for(Node n : nodeList)
    		recur(n, "");
    	
    	System.out.println(sb);
    	br.close();
    }
}