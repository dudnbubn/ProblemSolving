import java.io.*;
import java.util.*;

public class BOJ1644_소수의연속합 {
	static boolean[] isPrime;
	
	static void Eratos(int N) {
		for(int i=2;i<=N;i++)
			isPrime[i] = true;
		
		for(int i=2;i*i<=N;i++) {
			if(isPrime[i]) {
				for(int j=i*i;j<=N;j+=i)
					isPrime[j] = false;
			}
		}
	}
	
	
    public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	
    	int N = Integer.parseInt(br.readLine());
    	isPrime = new boolean[N+1];
    	Eratos(N);
    	
    	ArrayList<Integer> al = new ArrayList<>();
    	for(int i=2;i<=N;i++)
    		if(isPrime[i])
    			al.add(i);
    	
    	int start = 0, end = 0, sum = 0, sz = al.size();
    	int result = 0;
    	while(end < sz) {
    		if(sum >= N) {
    			if(sum == N)	result++;
    			sum -= al.get(end++);
    		}
    		else {
    			if(start == sz)	break;
    			sum += al.get(start++);
    		}
    	}
    	sb.append(result);
    	
    	System.out.println(sb);
    	
    	br.close();
    }
}