import java.util.*;

public class milestone4{
    static Scanner scan =  new Scanner(System.in);
    public static void main(String args[]){
        System.out.print("Enter n:"); int n = scan.nextInt();
        int a[] = new int[n];
        System.out.println("Enter Array:"); for(int i=0;i<n;i++) a[i] = scan.nextInt();
        System.out.println("PositionBasedSum:"+PositionBasedSum(a,n));
        System.out.println("sumOfPrimeIndexValues:"+sumOfPrimeIndexValues(a,n));
        System.out.println("stringDecoder:"+stringDecoder("0010001010000"));
        System.out.println("findSumOfPrimes:"+findSumOfPrimes(a,n));
    }

    public static boolean isPrime(int n){
        if(n == 0 || n==1) return false;
        for(int i=2;i<=Math.sqrt(n);i++) if(n%i==0) return false;
        return true;
    }

    public static int sumOfPrimeIndexValues(int[] input1,int input2){
        int sum = 0;
        for(int i=0;i<input2;i++) if(isPrime(i)){
            // System.out.println(input1[i] + " ");
            sum += input1[i];
        }
        return sum;
    }

    public static String stringDecoder(String input1){
        String str[] = input1.split("1");
        StringBuffer ans = new StringBuffer("");
        for(int i=0;i<str.length;i++){
            int n = str[i].length();
            ans.append((char)(90-n+1));
        }
        return ans.toString();
    }

    public static int findSumOfPrimes(int[] input1,int input2){
        int map = Integer.MIN_VALUE,ma = Integer.MIN_VALUE,sum = 0,asum = 0;
        boolean c = false;
        for(int i=0;i<input2;i++){
            asum += input1[i];
            if(isPrime(input1[i])){
                sum += input1[i];
                if(input1[i] > map){
                    map = input1[i];
                    c = true;
                }
            }
            ma = Math.max(ma,input1[i]);
        }
        sum -= map;
        asum -= ma;
        return (c)?sum:asum;
    }

    public static int PositionBasedSum(int input1[],int input2){
        int ans = 0;
        for(int i=0;i<input2;i++){
            int t = (int) (input1[i]%(Math.pow(10,i)));
            t %= 10;
            ans += Math.pow(t,2);
        }
        return ans;
    }
}