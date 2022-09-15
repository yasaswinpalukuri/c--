import java.util.*;
public class setBits {
    static Scanner scan = new Scanner(System.in);
    public static void main(String args[]){
        int n = scan.nextInt();
        // System.out.println(countSetBits(n)+"#"+positionOfLeastSetBit(n)+"#"+countSetBits(n));
        System.out.println(bitWise(n));
    }

    public static String bitWise(int input1){
        List<Integer> al = new ArrayList<>();
        int one = 0,le = 0,ri = 0;
        while(input1 > 0){
            if(input1%2 == 1) one++;
            al.add(input1%2);
            input1 /= 2;
        }
        Collections.reverse(al);
        System.out.println(al + ",size:" + al.size());
        for(int i=0;i<al.size();i++){
            if(al.get(i) == 1){
                ri = al.size() - i - 1;
                // System.out.println("ri = "  + ri);
                break;
            }
        }
        for(int i=al.size()-1;i>=0;i--){
            if(al.get(i) == 1){
                le = al.size() - i - 1;
                // System.out.println("le = "  + le);
                break;
            }
        }
        return (one + "#" +  (le) + "#" + (ri));
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
