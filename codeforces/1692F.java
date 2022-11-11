import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            int[] a = new int[10];
            Arrays.fill(a, 0);
            for(int i=0;i<n;i++){
                a[sc.nextInt()%10]++;
            }
            boolean ok = false;
            // 对于每个数字有三个的情况
            for(int i=0;i<10;i++){
                if(a[i]>=3&&(i*3%10==3)) ok = true;
            }
            // 对于每个数字两个自己，其他是别人的情况
            for(int i=0;i<10;i++){
                if(a[i]>=2){
                    for(int j=0;j<10;j++){
                        if(i!=j&&a[j]>=1){
                            if((i*2+j)%10==3) ok = true;
                        }
                    }
                }
            }
            // 对于每个数字不同的三个数字
            for(int i=0;i<10;i++){
                for(int j=i+1;j<10;j++){
                    for(int k=j+1;k<10;k++){
                        if(a[i]!=0&&a[j]!=0&&a[k]!=0){
                            if((i+j+k)%10==3) ok = true;
                        }
                    }
                }
            }
            if(ok) System.out.println("yes");
            else System.out.println("no");
        }
    }
}
