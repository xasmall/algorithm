import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            int lim = (int)Math.sqrt(2*n - 2);
            boolean[] used = new boolean[n];
            int[] ans = new int[n];
            for(int i = n-1 ;i>=0; i--){
                int s = (int)Math.sqrt(i);
                for(int j = lim;j>=s;j--){
                    if(j*j - i > n-1) continue;
                    if(!used[j*j - i]){
                        used[j*j - i] = true;
                        ans[i] = j * j - i;
                        break; 
                    }
                }
            }
            StringBuilder sans = new StringBuilder();
            for(int i=0;i<n;i++){
                sans.append(ans[i]+" ");
            }
            System.out.println(sans.toString());
        }
    }
}