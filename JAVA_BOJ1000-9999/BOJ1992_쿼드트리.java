import java.io.*;
import java.security.cert.CollectionCertStoreParameters;
import java.util.*;

public class BOJ1992_쿼드트리 {	
	
	static char[][] board;
	
	static String QT(int si, int sj, int ei, int ej) {
		char c = board[si][sj];
		boolean flag = true;
		for(int i=si;i<=ei;i++) {
			for(int j=sj;j<=ej;j++) {
				if(board[i][j] != c) {
					flag = false;
					break;
				}
			}
			if(!flag)	break;
		}
		
		if(flag) return ""+c;
		
		String result = "(";
		int mi = (si+ei)/2, mj = (sj+ej)/2;
		result += QT(si, sj, mi, mj);
		result += QT(si, mj+1, mi, ej);
		result += QT(mi+1, sj, ei, mj);
		result += QT(mi+1, mj+1, ei, ej);
		
		result += ")";
		return result;
	}
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		board = new char[N][N];
		
		for(int i=0;i<N;i++) 
			board[i] = br.readLine().toCharArray();
		
		System.out.println(QT(0, 0, N-1, N-1));
		br.close();
	}
}