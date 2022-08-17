import java.io.*;
import java.util.*;

public class BOJ1541_잃어버린괄호 {
	
	static int calc(int a, int b, char oper) {
		if(oper == '+')	return a+b;
		else 	return a-b;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		char[] ca = br.readLine().toCharArray();
		int num = 0;
		
		boolean minusFlag = false;
		
		int result = 0;
		for(int i=0;i<ca.length;i++) {
			if(ca[i] == '+' || ca[i] == '-') {
				if(minusFlag)	result -= num;
				else 			result += num;
				
				num = 0;
				if(ca[i] == '-')
					minusFlag = true;
			}
			else 
				num = (num*10) + (ca[i]-'0');
		}
		if(minusFlag)	result -= num;
		else 			result += num;
		
		System.out.println(result);
		br.close();
	}
}