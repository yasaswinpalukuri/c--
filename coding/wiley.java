import java.util.*;

public class wiley {
    static Scanner scan = new Scanner(System.in);
    // public static void main(String args[]){
    //     int n = scan.nextInt();
    //     for(int i=1;i<=n;i++){
    //         int j = 1;
    //         for(;j<i;j++){
    //             System.out.print(" ");
    //         }
    //         System.out.println(i);
    //         for(j=1;j<n;j++){
    //             System.out.print(" ");
    //         }
    //     }
    // }    

    public static void main(String args[]){
        String s = scan.nextLine();
        int n = s.length();
        // System.out.println(s + " " + n);
        if(n > 100) System.out.println("-1");
        else if(Character.isDigit(s.charAt(n-1))){
            // System.out.println("Yes last character is digit");
            if(s.charAt(n-1) == (n/10)+'0') System.out.println((n-1)%10);
            else System.out.println(-1);
        }
        else{
            // System.out.println("No last character is not digit");
            if(n > 9) System.out.println(-1); 
            else System.out.println(n);
        }
    }
}
