import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Node{
    int k;
    int val;
    Node(int k ,int val){
        this.k = k;
        this.val = val;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            int[] a = new int[n+1];
            List<Node> list = new ArrayList<>();
            for(int i=1;i<=n;i++){
                a[i] = sc.nextInt();
                if(a[i]>=i) continue;
                list.add(new Node(i,a[i]));
            }
            //进行二分查找
            Long ans = 0L;
            for(int i=0;i<list.size();i++){
                Node f = list.get(i);
                int tt = f.val;
                int l = 0, r = i-1;
                while(l<r){
                    int mid = l + r + 1 >> 1;
                    if(list.get(mid).k<tt) l = mid;
                    else r = mid - 1;
                }
                if(list.get(l).k<tt) ans += l + 1;
            }
            System.out.println(ans);
        }
    }
}
