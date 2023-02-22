import java.util.*;
import java.io.*;

public class BOJ3653_MovieCollection {

    static final int INF = 200000;
    static int[] arr;
    static int[] tree;
    static int[] leaf;

    static void set_tree(int start, int end, int node){
        if(start == end){
            leaf[start] = node;
            return;
        }
        int mid = (start+end)/2;
        set_tree(start, mid, node*2);
        set_tree(mid+1, end, node*2+1);
    }

    static int get_value(int start, int end, int node, int left, int right){
        if(start > right || end < left) return 0;
        if(left <= start && end <= right)   return tree[node];

        int mid = (start+end)/2;
        return get_value(start, mid, node*2, left, right) + get_value(mid+1, end, node*2+1, left, right);
    }

    static void update(int index){
        int node = leaf[index];
        while(node > 0){
            tree[node]++;
            node /= 2;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int TC = Integer.parseInt(br.readLine());
        int N, M;
        for(int  tc=0;tc<TC;tc++) {
            arr = new int[INF + 1];
            tree = new int[4 * INF];
            leaf = new int[INF + 1];

            st = new StringTokenizer(br.readLine(), " ");
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());


            int[] indexOf = new int[N+1];
            for(int i=1;i<=N;i++) {
                arr[i] = N - i + 1;
                indexOf[N-i+1]=i;
            }
            set_tree(1, INF, 1);
            int start, end = N;

            st = new StringTokenizer(br.readLine()," ");
            int selected;
            for(int i=0;i<M;i++){
                selected = Integer.parseInt(st.nextToken());

                start = indexOf[selected];
                sb.append(end - start - get_value(1, INF, 1, start, end)).append(' ');
                update(start);
                end++;
                arr[end] = selected;
                indexOf[selected] = end;
            }
            sb.append('\n');
        }

        System.out.println(sb);
        br.close();
    }
}
