import java.io.*;
import java.util.HashMap;
import java.util.Map;

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
        int n = nextInt(), q = nextInt();
        int[] a = new int[n+1];
        long sum = 0;
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=1;i<=n;i++){
            a[i] = nextInt();
            map.put(i,a[i]);
            sum += a[i];
        }
        int preK = -1;
        while(q-->0){
            int t = nextInt();
            if(t==1){
                int index = nextInt(), val = nextInt();
                if(map.containsKey(index)){
                    int k = map.get(index);
                    if(k>val){
                        sum -= k - val;
                    }else{
                        sum += val - k;
                    }
                }else{
                    if(preK>val){
                        sum -= preK - val;
                    }else{
                        sum += val - preK;
                    }
                }
                map.put(index,val);
                out.println(sum);
            }else{
                int val = nextInt();
                preK = val;
                map = new HashMap<>();
                sum = (long)preK * n;
                out.println(sum);
            }
            out.flush();
        }
    }
    
}
