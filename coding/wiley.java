import java.util.*;

public class wiley {
    static Scanner scan = new Scanner(System.in);
    public static void main(String args[]){
        // printPattern();
        // changeUnreadableChars();
        stringCheck();
    }
    public static void printPattern(){
        int n = scan.nextInt();
        int[][] arr = new int[2*n -1][2*n -1];
        for(int i=0;i<2*n-1;i++) arr[i][i] = arr[i][2*n-2-i] = (i+1 > n) ? 2*n - i - 1 : i+1;
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<2*n-1;j++){
                if(arr[i][j] != 0) System.out.print(arr[i][j]+" ");
                else System.out.print("  ");
            }
            System.out.println();
        }
    }    

    public static void changeUnreadableChars(){
        String s1 = scan.next();
        String s2 = scan.next();
        int max=0,min=0;
        for(int j=0;j<s1.length();j++){
            if(s1.charAt(j)!=s2.charAt(j) && s1.charAt(j)!='?' && s2.charAt(j)!='?'){
                min++;
                max++;
            }
            else if(s1.charAt(j)=='?' || s2.charAt(j)=='?'){
                max++;
            }
        }
        System.out.println(min+" "+max);
    }

    public static void stringCheck(){
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
