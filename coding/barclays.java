import java.util.*;

public class barclays {
    static Scanner scan = new Scanner(System.in);
    public static void main(String args[]){
        System.out.print("Enter n:");
        int n = scan.nextInt();
        int a[] = new int[n];
        System.out.print("Enter coins:");
        for(int i=0;i<n;i++){
            a[i] = scan.nextInt();
        }
        System.out.print("Enter target:");
        int t = scan.nextInt();
        System.out.println(solve(n,a,t));
    }

    static int solve(int n,int[] coins,int target){
        int l = 0, r = 0, b = Integer.MAX_VALUE;
        int t = coins[0];
        while(r < n){
            if(t >= target){
                b = Math.min(b, r - l + 1);
                if(l == r){
                    t-=coins[l];
                    l++;
                    r++;
                    t+=coins[r];
                }else{
                    t-=coins[l];
                    l++;
                }
                continue;
            }
            r++;
            t += coins[r];
        }
       
        if(b == Integer.MAX_VALUE) return n;
        else return b;
    }
}
