import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            sc.nextLine();
            String s = sc.nextLine();
            long ans = n;
            for(int i=1;i<s.length();i++){
                if(s.charAt(i)!=s.charAt(i-1)){
                    ans += i;
                }
            }
            System.out.println(ans);
        }
    }
}
