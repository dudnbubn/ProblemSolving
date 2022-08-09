import java.io.*;
import java.util.*;

public class BOJ2941_크로아티아알파벳 {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		
		int result = 0;
		for(int i=0;i<s.length();i++) {
			result++;
			if(i == s.length() - 1 ) break;
			switch(s.charAt(i)) {
			case 'c':
				if(s.charAt(i+1) == '-' || s.charAt(i+1) == '=') 
					i++;
				break;
			case 'd':
				if(s.charAt(i+1) == '-') 
					i++;
				
				else if(i < s.length() - 2 && s.charAt(i+1) == 'z' && s.charAt(i+2) == '=') 
					i+=2;
				break;
			case 'n':
			case 'l':
				if(s.charAt(i+1) == 'j') 
					i++;
				break;
			case 's':
			case 'z':
				if(s.charAt(i+1) == '=') 
					i++;
				break;
			}
		}
		System.out.println(result);
	}

}
