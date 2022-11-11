import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt(), s = sc.nextInt();
            int[] a = new int[n];
            int maxSum = 0;
            for(int i=0;i<n;i++){
                a[i] = sc.nextInt();
                maxSum += a[i];
            }
            if(maxSum<s){
                System.out.println(-1);
                continue;
            }
            int sum = 0;
            int left = 0, right = 0;
            int ans = Integer.MAX_VALUE;
            while(right<n){
                sum += a[right];
                // 如果当前的sum>k；
                while(sum>s&&left<right){
                    // 从left向前移动
                    sum -= a[left];
                    left++;
                }
                if(sum==s){
                    ans = Math.min(n-right+left-1,ans);
                }
                right++;
            }
            System.out.println(ans);
        }
    }
}
