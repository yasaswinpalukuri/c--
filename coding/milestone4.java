import java.util.*;

public class milestone4{
    static Scanner scan =  new Scanner(System.in);
    public static void main(String args[]){
        int n = scan.nextInt();
        int a[] = new int[n];
        System.out.println(PositionBasedSum(a,n));
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