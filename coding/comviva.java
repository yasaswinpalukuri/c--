import java.util.*;

public class comviva {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args){
        int n = scan.nextInt();
        int[] arr = new int[n];
        int k = scan.nextInt();
        for(int i=0;i<n;i++){
            arr[i] = scan.nextInt();
        }
        Arrays.sort(arr);
        int ans = 0;
        for(int i = n-1;i>n-k;i++) ans += arr[i];
        System.out.println(ans);
    }

    public int marathon(int input1,int input2,int[] input3){
        Arrays.sort(input3);
        int ans = 0;
        for(int i = input1-1;i>input1-input2;i++) ans += input3[i];
        return ans;
    }
}
