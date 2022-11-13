import java.net.Socket;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt(),m = sc.nextInt();
            int[] a = new int[n+1], d = new int[n+1];
            int[] u = new int[m+1], v = new int[m+1];
            for(int i=1;i<=n;i++){
                a[i] = sc.nextInt();
            }
            Arrays.fill(d, 0);
            for(int i=1;i<=m;i++){
                u[i] = sc.nextInt();
                v[i] = sc.nextInt();
                d[u[i]]++;
                d[v[i]]++;
            }
            if(m%2==0){
                System.out.println(0);
            }else{
                int ans = Integer.MAX_VALUE;
                for(int i=1;i<=n;i++){
                    if(d[i]%2==1) ans = Math.min(ans,a[i]);
                }
                for(int i=1;i<=m;i++){
                    int x = u[i], y = v[i];
                    if(d[x]%2==0&&d[y]%2==0){
                        ans = Math.min(ans,a[x] + a[y]);
                    }
                }
                System.out.println(ans);
            }
        }
    }
}
