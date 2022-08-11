import java.io.*;
import java.util.*;

public class BOJ16637_괄호추가하기 {
	static int N, result = Integer.MIN_VALUE;
	static int[] numbers;
	static char[] opers;
	static boolean[] visited;
	
	static int calc(int a, int b, char oper) {
		switch(oper) {
		case '+':	return a+b;
		case '-':	return a-b;
		case '*':	return a*b;
		}
		return -1;
	}
	
	static void subs(int depth) {
		if(depth == N/2) {
			ArrayDeque<Integer> numDeque = new ArrayDeque<>();
			ArrayDeque<Character> opDeque = new ArrayDeque<>();
			
			opDeque.offer(opers[0]);
			
			for(int i=1;i<N/2;i++) {
				if(visited[i]) 
					numDeque.offer(calc(numbers[i], numbers[i+1], opers[i]));
				else if(visited[i-1]) 
					opDeque.offer(opers[i]);
				else {
					numDeque.offer(numbers[i]);
					opDeque.offer(opers[i]);
				}
			}
			numDeque.offer(numbers[N/2]);
			
			int res = numbers[0];
			while(!opDeque.isEmpty()) 
				res = calc(res, numDeque.poll(), opDeque.poll());
			
			result = result > res ? result : res;
			
			return;
		}
		
		if(!visited[depth-1]) {
			visited[depth] = true;
			subs(depth+1);
		}
		visited[depth] = false;
		subs(depth+1);
		
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
        N = Integer.parseInt(br.readLine());
        char[] ca = br.readLine().toCharArray();
        
        numbers = new int[N/2+1];
        opers = new char[N/2];
        visited = new boolean[N/2];
        
        for(int i=0;i<N;i++) {
        	if(i % 2 == 0)	numbers[i/2] = ca[i] - '0';
        	else 	opers[i/2] = ca[i];
        }
        
        if(N == 1)	System.out.println(numbers[0]);
        else{
        	subs(1);
        	System.out.println(result);
        }
        
        br.close();
    }
}