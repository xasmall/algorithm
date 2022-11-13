import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static int nextInt(){
        int val = 0;
        try{
            val = (int)in.nextToken();
        }catch(Exception e){
            e.printStackTrace();
        }
        return val;
    }
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = nextInt();
        while(t-->0){
            int n = nextInt();
            int[] a = new int[n];
            for(int i=0;i<n;i++){
                a[i] = nextInt();
            }
            Arrays.sort(a);
            long ans = (long) a[n-1] + a[n-2] - a[0] - a[1];
            System.out.println(ans);
        }
    }
}
