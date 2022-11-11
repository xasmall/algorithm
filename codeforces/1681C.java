import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static PrintWriter out=new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StreamTokenizer st=new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

    static int nextInt(){
		try {
			st.nextToken();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return (int)st.nval;
	}
    public static void main(String[] args) {
        int t = nextInt();
        while(t-->0){
            int n = nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            List<int[]> ans = new ArrayList<>();

            for(int i=0;i<n;i++){
                a[i] = nextInt();
            }
            for(int i=0;i<n;i++){
                b[i] = nextInt();
            }
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(a[i]>a[j]){
                        int tem = a[i];
                        a[i] = a[j];
                        a[j] = tem;
                        tem = b[i];
                        b[i] = b[j];
                        b[j] = tem;
                        ans.add(new int[]{i+1,j+1});
                    }
                }
            }
            // System.out.println(ans.size());
            boolean ok = true;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(b[i]>b[j]){
                        if(a[i]!=a[j]){
                            ok = false;
                        }else{
                            int tem = b[i];
                            b[i] = b[j];
                            b[j] = tem;
                            ans.add(new int[]{i+1,j+1});
                        }
                    }
                }
            }
            if(ok){
                System.out.println(ans.size());
                for(int[] u : ans){
                    out.println(u[0] + " " + u[1]);
                }
            }else{
                out.println(-1);
            }
            out.flush();
        }
    }
}
