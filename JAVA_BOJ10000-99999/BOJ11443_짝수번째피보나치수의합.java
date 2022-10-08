import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class BOJ11443_짝수번째피보나치수의합 {
	
	static final int MOD = 1_000_000_007;
	static HashMap<Long, Long> hm = new HashMap<>();
	
	static long Fibo(long N) {
		if(N == 0)	return 0;
		if(N <= 2)	return 1;
		if(hm.containsKey(N))	return hm.get(N);
		
		long k;
		if((N&1) == 1) {
			k = (N+1)/2;
			hm.put(N, (Fibo(k)*Fibo(k) + Fibo(k-1)*Fibo(k-1))%MOD);
		}
		else {
			k = N/2;
			hm.put(N, ((2*Fibo(k-1)+Fibo(k))*Fibo(k))%MOD);
		}
		return hm.get(N);
	}
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuilder sb = new StringBuilder();
    	StringTokenizer st;
    	
    	long N = Long.parseLong(br.readLine());
    	if(N%2 == 0)	N++;
    	System.out.println(Fibo(N)-1);
    	
    	br.close();
    }
}