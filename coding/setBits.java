import java.util.*;
public class setBits {
    static Scanner scan = new Scanner(System.in);
    public static void main(String args[]){
        int n = scan.nextInt();
        System.out.println(countSetBits(n)+"#"+positionOfLeastSetBit(n)+"#"+countSetBits(n));
    }

    public static int countSetBits(int n){
        int count = 0;
        while(n>0){
            count += n&1;
            n >>= 1;
        }
        return count;
    }

    public static int positionOfLeastSetBit(int n){
        int count = 0;
        while(n>0){
            count++;
            if((n&1)==1) return count;
            n >>= 1;
        }
        return 0;
    }
}
