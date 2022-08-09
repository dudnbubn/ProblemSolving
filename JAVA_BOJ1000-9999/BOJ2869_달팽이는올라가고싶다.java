import java.io.*;
import java.util.*;

public class BOJ2869_달팽이는올라가고싶다 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		String[] s = br.readLine().split(" ");
		
		long A = Integer.parseInt(s[0]);
		long B = Integer.parseInt(s[1]);
		long V = Integer.parseInt(s[2]);
		
		if(V <= A)	System.out.println(1);
		else {
			V -= A;
			if(V % (A-B) == 0)	System.out.println(V/(A-B) + 1);
			else	System.out.println(V/(A-B) + 2);
		}
	}

}
