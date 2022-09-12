import java.util.*;

public class sumOfDigits {
    static Scanner scan = new Scanner(System.in);
    public static void main(String args[]){
        System.out.print("Enter n:");
        int n = scan.nextInt();
        System.out.print("Enter array:");
        int arr[] = new int[n];
        for(int i=0;i<n;i++) arr[i] = scan.nextInt();
        System.out.println(DifferenceSumOfDigits(arr,n));
    }

    public static int sumDigits(int n){
        System.out.print(n);
        int sum = 0;
        while(n>0){
            sum += n%10;
            n /= 10;
        }
        System.out.println(",digit sum is:"+ sum);
        return sum;
    }

    public static int DifferenceSumOfDigits(int[] arr,int n){
        int f1 = 0,f2 = 0;
        for(int i=0;i<n;i++){
            f1 += sumDigits(arr[i]);
            f2 += arr[i];
        }
        System.out.println("f1:"+f1+",f2:"+f2);
        return (f1%10)-(f2%10);
    }
}
