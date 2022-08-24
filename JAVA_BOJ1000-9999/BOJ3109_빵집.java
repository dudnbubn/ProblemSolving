import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class BOJ3109_빵집 {

	static int R, C, result;
	static char[][] board;
	static boolean[][] visited;
	static int[] di = {-1, 0, 1};
	static int[] dj = {1, 1, 1};
    static boolean check;
	
	static void recur(int i, int depth) {
		if(check)    return;
		visited[i][depth] = true;
		
		if(depth == C-1)	{
			result++;
            check = true;
			return;
		}
		
		int ni, nj;
		for(int d=0;d<3;d++) {
			ni = i + di[d];
			nj = depth+1;
			
			if(ni < 0 || ni >= R || nj < 0 || nj >= C)
				continue;
			
			if(!visited[ni][nj] && board[ni][nj] == '.') {
				recur(ni, nj);
			}
		}
	}
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	
    	R = Integer.parseInt(st.nextToken());
    	C = Integer.parseInt(st.nextToken());
    	
    	board = new char[R][C];
    	visited = new boolean[R][C];
    	
    	for(int i=0;i<R;i++)
    		board[i] = br.readLine().toCharArray();
    	
    	
    	
    	for(int i=0;i<R;i++){
            check = false;
    		recur(i, 0);
        }
    	
    	System.out.println(result);
    	
    	br.close();
    }
}