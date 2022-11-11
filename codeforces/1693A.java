import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            // 每个位置，前面的和都大于等于0， 如果前面的和大于0，那么当前指针，必然在最左边，如果后面还有内容，就出现了错误
            int n = sc.nextInt();
            int[] a = new int[n];
            long preSum = 0;
            boolean ok = true;
            boolean flag = false;
            for(int i=0;i<n;i++){
                a[i] = sc.nextInt();
                if(flag&&a[i]!=0) ok = false;
                preSum += a[i];
                // System.out.println(preSum);
                if(preSum<0) ok = false;
                if(preSum==0){
                    flag = true;
                }
            }
            if(preSum!=0) System.out.println("no");
            else {
                if(ok) System.out.println("yes");
                else System.out.println("no");
            }
        }
    }
}