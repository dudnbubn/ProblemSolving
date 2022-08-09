import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1244_스위치켜고끄기{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N+1];
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for(int i=1;i<=N;i++)
			arr[i] = Integer.parseInt(st.nextToken());
		
		int M = Integer.parseInt(br.readLine());
		int gender, num;
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			gender = Integer.parseInt(st.nextToken());
			num = Integer.parseInt(st.nextToken());
			
			if(gender == 1) {
				for(int j=num;j<=N;j+=num) 
					arr[j] = (arr[j]+1)%2;
			}
			else{
				arr[num] = (arr[num] + 1)%2;
				int left = num - 1, right = num + 1;
				while((left > 0 && right <= N) && (arr[left] == arr[right])) {
					arr[left] = (arr[left]+1)%2;
					arr[right] = (arr[right]+1)%2;
					left--;
					right++;
				}
			}
		}
		
		for(int i=1;i<=N;i++) {
			sb.append(arr[i]).append(' ');
			if(i % 20 == 0)
				sb.append('\n');
		}
		System.out.println(sb);
	}

}
