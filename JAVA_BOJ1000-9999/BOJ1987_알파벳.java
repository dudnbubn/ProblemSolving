import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class BOJ1987_알파벳 {
	
	static int R, C, result;
	static char[][] board;
	static int[] di = {-1, 0, 1, 0};
	static int[] dj = {0, 1, 0, -1};
	
	static void recur(int i, int j, int cnt, int state) {
		int shift;
		int ni, nj;
		int nextState;
		boolean flag = false;
		for(int d=0;d<4;d++) {
			ni = i + di[d];
			nj = j + dj[d];
			
			if(ni < 0 || ni >= R || nj < 0 || nj >=C)
				continue;
			
			shift = board[ni][nj] - 'A';
			nextState = state | (1<<shift);
			if((state & (1 << shift)) == 0){
				recur(ni, nj, cnt+1, nextState);
				flag = true;
			}
		}
		
		if(!flag) {
			result = result > cnt ? result : cnt;
			return;
		}
	}

	
    public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    	
    	R = Integer.parseInt(st.nextToken());
    	C = Integer.parseInt(st.nextToken());
    	
    	board = new char[R][C];
    	
    	for(int i=0;i<R;i++)
    		board[i] = br.readLine().toCharArray();
    	
    	recur(0, 0, 1, 1 << (board[0][0] - 'A'));
    	
    	System.out.println(result);
    	
    	br.close();
    }
}