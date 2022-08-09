import java.io.*;
import java.security.cert.CollectionCertStoreParameters;
import java.util.*;

class Pair implements Comparable<Pair> {
	int first;
	int second;
	
	Pair(){}
	
	Pair(int first, int second)  {
		this.first = first;
		this.second = second;
	}
	

	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append(this.first)
			.append(" ")
			.append(this.second);
		return builder.toString();
	}

	@Override
	public int compareTo(Pair o) {
		if(this.first == o.first) {
			if(this.second == o.second)	return 0;
			else if(this.second < o.second)	return -1;
			else 	return 1;
		}
		else if(this.first < o.first)	return -1;
		else 	return 1;
	}
}

class PairComparator implements Comparator<Pair>{
	@Override
	public int compare(Pair o1, Pair o2) {
		return o1.compareTo(o2);
	}
}

public class BOJ16236_아기상어 {	
	static int N;
	static int[][] board = new int[21][21];
	static int[] fish_cnt = new int[7];
	static boolean[][] visited = new boolean[21][21];
	static int shark_i, shark_j, shark_size = 2, eat;
	static int[] di = { -1, 0, 0, 1};
	static int[] dj = { 0, -1, 1, 0};
	static ArrayDeque<Pair> ad = new ArrayDeque<>();
	static ArrayList<Pair> al = new ArrayList<>();
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				board[i][j] = sc.nextInt();
				
				if(board[i][j] == 9) {
					shark_i = i;
					shark_j = j;
				}
				else if(board[i][j] > 0)
					fish_cnt[board[i][j]]++;
			}
		}
		
		int t, T = 0;
		int can_eat = fish_cnt[1];
		while(can_eat > 0) {
			t = getFish();
			if(t == 0)	break;
			
			T += t;
			
			can_eat = 0;
			for(int i=1;i<shark_size;i++)
				can_eat += fish_cnt[i];
		}
		
		System.out.println(T);
	}
	
	static int getFish() {		 
		for(int i=1;i<=N;i++) 
			for(int j=1;j<=N ;j++)
				visited[i][j] = false;
		
		ad.clear();
		ad.addLast(new Pair(shark_i, shark_j));
		visited[shark_i][shark_j] = true;
		
		Pair cur;
		int t = -1, adsz;
		int next_i, next_j;
		while(!ad.isEmpty()) {
			al.clear();
			t++;
			adsz = ad.size();
			for(int sz=0;sz<adsz;sz++) {
				cur = ad.removeFirst();
				if(board[cur.first][cur.second] != 9 && (0<board[cur.first][cur.second]&& board[cur.first][cur.second] < shark_size ) ) {
					fish_cnt[board[cur.first][cur.second]]--;
					if(shark_size < 7) {
						eat++;
						if(eat == shark_size) {
							eat = 0;
							shark_size++;
						}
					}
					
					board[shark_i][shark_j] = 0;
					board[cur.first][cur.second] = 9;
					shark_i = cur.first;
					shark_j = cur.second;
					
					return t;
				}
				
				for(int k=0;k<4;k++) {
					next_i = cur.first + di[k];
					next_j = cur.second + dj[k];
					
					if(next_i < 1 || next_j < 1 || next_i > N || next_j > N)
						continue;
					
					if(!visited[next_i][next_j] && board[next_i][next_j] <= shark_size) {
						visited[next_i][next_j] = true;
						al.add(new Pair(next_i, next_j));
					}
				}
			}
			
			Collections.sort(al);
			while(!al.isEmpty()) {
				ad.addLast(al.remove(0));
			}
		}
			
		return 0;
	}
}