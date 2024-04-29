package leetcode;
import java.util.*;

public class validNumber65 {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Question 65 - Hard");
        System.out.println("valid Number");
        /*
            A valid number can be split up into these components (in order):

            A decimal number or an integer.
            (Optional) An 'e' or 'E', followed by an integer.
            A decimal number can be split up into these components (in order):

            (Optional) A sign character (either '+' or '-').
            One of the following formats:
            One or more digits, followed by a dot '.'.
            One or more digits, followed by a dot '.', followed by one or more digits.
            A dot '.', followed by one or more digits.
            An integer can be split up into these components (in order):

            (Optional) A sign character (either '+' or '-').
            One or more digits.
         */
        do{
            System.out.println("Enter the string to check if it is a valid number or not:");
            System.out.println("Enter 'exit' to exit the program");
            String s = scan.nextLine();
            if(s.equals("exit")) System.exit(0);
            System.out.println(isNumber(s));
        }while(true);
    }

    static public boolean isNumber(String s){
        int n = s.length();
        boolean numSeen = false;
        boolean dotSeen = false;
        boolean eSeen = false;
        for(int i=0; i<n; i++){
            char c = s.charAt(i);
            if(Character.isDigit(c)){
                numSeen = true;
            }else if(c == '.'){
                if(dotSeen || eSeen){
                    return false;
                }
                dotSeen = true;
            }else if(c == 'e' || c == 'E'){
                if(eSeen || !numSeen){
                    return false;
                }
                eSeen = true;
                numSeen = false;
            }else if(c == '+' || c == '-'){
                if(i>0 && s.charAt(i-1) != 'e' && s.charAt(i-1) != 'E'){
                    return false;
                }
            }else{
                return false;
            }
        }
        return numSeen;
    }
}
