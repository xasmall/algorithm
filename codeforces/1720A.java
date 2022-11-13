import java.util.Scanner;

public class Main {
    public static int gcb(int a,int b){
        return b==0?a:gcb(b, a%b);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t -- > 0){
            int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt(), d = sc.nextInt();
            if(a==0&&c==0){
                System.out.println(0);
            }else if(a==0||c==0){
                System.out.println(1);
            }else{
                int k;
                if(b>d){
                    k = gcb(b, d);
                }else{
                    k = gcb(d, b);
                }
                long f = (long)b * d / k;
                // 最多四次
                long a1 = (long)a * f/b;
                long c1 = (long)c * f/b;
                if(a1==c1) System.out.println(0);
                else{
                    int ans = 0;
                    if(f!=b) ans++;
                    if(f!=d) ans++;
                    if(a%c!=0&&c%a!=0) ans+=2;
                    else ans++;
                    System.out.println(ans);
                }
            }
        }
    }
}
