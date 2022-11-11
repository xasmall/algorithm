import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            sc.nextLine();
            int[][] a = new int[n+1][n+1];
            for(int i=0;i<n;i++){
                String s = sc.nextLine();
                for(int j=0;j<s.length();j++){
                    a[i+1][j+1] = s.charAt(j) - '0';
                }
            }
            // 转90度的时候,第i列变成第i行，第k行变成第n-k+1列
            // 转180度的时候，第i行变成n-i+1行，第i列变成第n-k+1列
            // 转270度的时候，第i行变成第i列，第i列变成第n-i+1行
            int ans = 0;
            Set<Integer> set = new HashSet<>();
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    int hash = i * n + j;
                    if(set.contains(hash)) continue;
                    // 否则找到其他的三个值
                    int t90x = j, t90y = n - i + 1;
                    int t180x = n - i + 1,t180y = n-j + 1;
                    int t270x = n-j+1,t270y = i;
                    int zero = 0,one = 0;
                    if(a[i][j]==0){
                        zero++;
                    }else{
                        one++;
                    }
                    if(a[t90x][t90y]==0){
                        zero++;
                    }else{
                        one++;
                    }
                    if(a[t180x][t180y]==0){
                        zero++;
                    }else{
                        one++;
                    }
                    if(a[t270x][t270y]==0){
                        zero++;
                    }else{
                        one++;
                    }
                    ans += Math.min(4-zero,4-one);
                    int hash1 = t90x * n + t90y;
                    int hash2 = t180x * n + t180y;
                    int hash3 = t270x * n + t270y;
                    set.add(hash);
                    set.add(hash1);
                    set.add(hash2);
                    set.add(hash3);
                }
            }
            System.out.println(ans);

        }
    }
}