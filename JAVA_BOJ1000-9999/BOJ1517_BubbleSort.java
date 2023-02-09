import java.io.*;
import java.util.*;

public class BOJ1517_BubbleSort {
    static class Pair{
        int first;
        int second;
        Pair(int first, int second){
            this.first = first;
            this.second = second;
        }
    }

    static int[] tree;
    static HashMap<Integer, Integer> leaf = new HashMap<>();

    static void setTree(int start, int end, int node) {
        if(start == end){
            leaf.put(start, node);
            return;
        }

        int mid = (start+end)/2;
        setTree(start, mid, node*2);
        setTree(mid+1,end, node*2+1);
    }

    static int getTree(int start, int end, int node, int left, int right) {
        if(start > right || end < left) return 0;
        if(left <= start && end <= right)   return tree[node];

        int mid = (start+end)/2;
        return getTree(start,mid,node*2,left,right) + getTree(mid+1,end,node*2+1,left,right);
    }

    static void update(int index){
        int node = leaf.get(index);
        while(node > 0) {
            tree[node]++;
            node /= 2;
        }
    }

    public static void main(String[] args) throws  Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine()," ");
        tree = new int[4*N];
        ArrayList<Pair> arrayList = new ArrayList<>();
        for(int i=1;i<=N;i++){
            arrayList.add(new Pair(Integer.parseInt(st.nextToken()), i));
        }

        setTree(1, N, 1);

        Collections.sort(arrayList, (o1, o2) -> {
                if(o1.first == o2.first) return Integer.compare(o1.second, o2.second);
                return Integer.compare(o1.first, o2.first);
        });

        long result = 0;
        int index;

        for(int i=0;i<N;i++) {
            index = arrayList.get(i).second;
            result += (index - 1 - getTree(1, N, 1, 1, index - 1));
            update(index);
        }
        System.out.println(result);
        br.close();
    }
}
