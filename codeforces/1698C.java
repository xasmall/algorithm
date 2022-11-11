import java.util.ArrayList;
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
            List<Integer> list = new ArrayList<>();
            int pos = 0, neg = 0, zero = 0;
            for(int i=0;i<n;i++){
                int a = sc.nextInt();
                if(a>0) pos++;
                if(a<0) neg++;
                if(a==0) zero++;
                if(a!=0) list.add(a);
            }
            if(neg>2||pos>2) System.out.println("no");
            else{
                if(zero>=1) list.add(0);
                boolean flag = true;
                Set<Integer> set = new HashSet<>(list);
                for(int i=0;i<list.size();i++){
                    for(int j=i+1;j<list.size();j++){
                        for(int k=j+1;k<list.size();k++){
                            if(!set.contains(list.get(i)+list.get(j)+list.get(k))){
                                flag = false;
                            }
                        }
                    }
                }
                if(!flag) System.out.println("no");
                else System.out.println("yes");
            }
            
        }
    }
    
}
