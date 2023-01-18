import java.util.*;

public class jpmorgan{
    static Scanner scan = new Scanner(System.in);
    public static boolean isPossible1(int a,int b,int c,int d){
        if(a>c||b>d) return false;
        if(a==c&&b==d) return true;
        return (isPossible1(a+b,b,c,d)||isPossible1(a,b+a,c,d));
    }
    public static boolean check(int a,int b,int c,int d){
        if(a>c||b>d) return false;
        if(a==c&&b==d) return true;
        return (check(a+b,b,c,d)||check(a,b+a,c,d));
    }
    public static String isPossible(int a,int b,int c,int d){
        if(check(a,b,c,d)) return "Yes";
        else return "No";
    }
    public static void main(String []args){
        int a=scan.nextInt();
        int b=scan.nextInt();
        int c=scan.nextInt();
        int d=scan.nextInt();
        // if(isPossible(a,b,c,d)) System.out.println("Yes");
        // else System.out.println("No");
    }


    public static boolean isPrime(int n){
        if(n < 2) return false;
        for(int i=2;i<=n/2;i++) if(n%i == 0) return false;
        return true;
    }
    public static void largestPrimeNumber(List<List<Integer>> matrix) {
        int ans = 0, n = matrix.size();
        for(int i=0;i<n;i++){
            if(isPrime(matrix.get(i).get(i))) ans = Math.max(ans,matrix.get(i).get(i));
            if(isPrime(matrix.get(i).get(n-i-1))) ans = Math.max(ans,matrix.get(i).get(n-i-1));
        }
        if(ans == 0) System.out.println(ans);
        else System.out.println("No prime number available");
    }


}