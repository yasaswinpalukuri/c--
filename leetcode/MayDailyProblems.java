package leetcode;
import java.util.*;

// This File consists of all the problems solved in May Daily Leetcode Challenge 2024
public class MayDailyProblems {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Welcome to May Daily Leetcode Problems");
        System.out.println("This is Yasaswin Palukuri, with solutions to the Daily Problems of May 2024");
        System.out.println("So, without any further ado, let's get started");
        do{
            System.out.println("Enter the day of the problem you want the answer for:");
            System.out.println("Day 1: Reverse Prefix of Word");
            int day = scan.nextInt();
            switch(day){
                case 1:
                    System.out.println("Enter the word and the character you want to reverse the prefix of:");
                    String word = scan.next();
                    char ch = scan.next().charAt(0);
                    System.out.println("The word after reversing the prefix of the character is: " + reversePrefix(word, ch));
                    break;
                default:
                    System.out.println("Sorry, the problem for the day you entered is not available");
                    break;
            }
        }while(true);
    }

    // 2000 May 1: Reverse Prefix of Word - Easy
    /*
    Example 1:

    Input: word = "abcdefd", ch = "d"
    Output: "dcbaefd"
    Explanation: The first occurrence of "d" is at index 3. 
    Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
    Example 2:

    Input: word = "xyxzxe", ch = "z"
    Output: "zxyxxe"
    Explanation: The first and only occurrence of "z" is at index 3.
    Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
    Example 3:

    Input: word = "abcd", ch = "z"
    Output: "abcd"
    Explanation: "z" does not exist in word.
    You should not do any reverse operation, the resulting string is "abcd".
     */
    static public String reversePrefix(String word, char ch) {
        int index = -1;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == ch) {
                index = i;
                break;
            }
        }
        String fh = word.substring(0, index + 1);
        String sh = word.substring(index + 1);
        
        StringBuilder sb = new StringBuilder(fh);
        sb.reverse();
        sb.append(sh);
        
        return sb.toString();
    }
}
