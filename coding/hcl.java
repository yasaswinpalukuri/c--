import java.util.*;

public class hcl {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args){
        int t = scan.nextInt();
        while(t-- > 0){
            int n = scan.nextInt(), m = scan.nextInt(), g = scan.nextInt();
            int[] arr = new int[n];
            boolean[] lte = new boolean[n];
            boolean[] div = new boolean[n];
            for(int i = 0; i < n; i++){
                arr[i] = scan.nextInt();
                lte[i] = arr[i] <= m;
                div[i] = arr[i] % g == 0;
            }
            int ans = 0;
            for(int i = 0; i < n; i++){
                if(lte[i] && div[i]){
                    ans++;
                }
            }
            System.out.println(ans);
        }
    }    
}
