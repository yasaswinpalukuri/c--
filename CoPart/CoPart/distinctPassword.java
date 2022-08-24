package CoPart;

import java.util.*;

public class distinctPassword{
    static Scanner scan = new Scanner(System.in);
    
    private static String customHash(String str){
        int[] hashEven = new int[26];
        int[] hashOdd = new int[26];
        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);
            if((i+1)%2 != 0) hashOdd[c-'a']++;
            else hashEven[c-'a']++;
        }
        StringBuilder hashOfInput = new StringBuilder();
        for(int i = 0; i < 26; i++) hashOfInput.append(hashEven[i]).append("#").append(hashOdd[i]).append("|");
        return hashOfInput.toString();
    }
    
    static int distinctPasswords(int input1, String[] input2){
        Set<String> uniqueHashes = new HashSet<>();
        
        for(int i = 0; i  < input1; i++) {
            String hash = customHash(input2[i]);
            uniqueHashes.add(hash);
        }
        
        return uniqueHashes.size();
    }

    public static void main( String[] args )
    {
        int n = scan.nextInt();
        String[] input = new String[n];
        for(int i = 0; i < n; i++) {
            input[i] = scan.next();
        }
        System.out.println(distinctPasswords(input.length,input));
    }
}