import java.io.*;
import java.util.*;

public class BOJ12891_DNA비밀번호 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int S = Integer.parseInt(st.nextToken());
		int P = Integer.parseInt(st.nextToken());
		
		char[] ca = br.readLine().toCharArray();
		
		st = new StringTokenizer(br.readLine(), " ");
		int A = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		int G = Integer.parseInt(st.nextToken());
		int T = Integer.parseInt(st.nextToken());
		
		int a=0,c=0,g=0,t=0;
		for(int i=0;i<P;i++) {
			switch(ca[i]) {
			case 'A':	a++;	break;
			case 'C':	c++;	break;
			case 'G':	g++;	break;
			case 'T':	t++;	break;
			}
		}
		
		int result = 0;
		if(a >= A && c >= C && g >= G && t >= T)
			result++;
		
		for(int i=P;i<S;i++) {
			switch(ca[i-P]) {
			case 'A':	a--;	break;
			case 'C':	c--;	break;
			case 'G':	g--;	break;
			case 'T':	t--;	break;
			}
			switch(ca[i]) {
			case 'A':	a++;	break;
			case 'C':	c++;	break;
			case 'G':	g++;	break;
			case 'T':	t++;	break;
			}
			if(a >= A && c >= C && g >= G && t >= T)
				result++;
		}
		System.out.println(result);
		
		br.close();
	}
}
