import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt(), m = sc.nextInt();
            int[] intil = new int[m];
            for(int i=0;i<m;i++){
                intil[i] = sc.nextInt();
            }
            Arrays.sort(intil);
            List<Integer> list = new ArrayList<>();
            for(int i=1;i<m;i++){
                list.add(intil[i]-intil[i-1]-1);
            }
            if(intil[0]+n-intil[m-1]-1>0) list.add(intil[0]+n-intil[m-1]-1);
            Collections.sort(list,(a,b)->b-a);
            int infected = 0, protect = 0;
            // 对于每一个区间进行的操作，每次都是操作两天，如果对于操作到一个区间，里面的可以背保护的区间只有一个的时候，当前区间必然只能保护一个，剩下的区间，必然不能保护到了
            // 所以对此的操作是每两天操作一次
            for(int i : list){
                if(i-infected*2>0){
                    protect += Math.max(1,i-infected*2-1);
                }
                infected += 2;
            }
            System.out.println(n-protect);
        }
    }
}