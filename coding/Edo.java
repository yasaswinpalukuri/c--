import java.util.*;

public class Edo {
    static Scanner scan = new Scanner(System.in);
    public static void main(String args[]){
        System.out.println(reverse("is3 sentence1 This4 a2"));
        System.out.println(reverse("Me4 Myself3 and2 i1"));
        System.out.println(countStrings("abcdee"));
    }   

    public static String reverse(String s){
        String str[] = s.split(" ");
        // System.out.println(str.length);
        String sb[] = new String[str.length];
        for(String st:str){
            int l = st.length()-1;
            // System.out.println(st.substring(0,l));
            sb[st.charAt(l)- '0' - 1] = st.substring(0,l);
        }
        s = "";
        for(int i=sb.length-1;i>=0;i--) s += (sb[i]+" "); 
        return s;
    }
    
    public static int countStrings(String s){
        int ans = 0;
        HashSet<Character> ch = new HashSet<Character>();
        for(int i = 0; i<s.length()-3; i++){
            // System.out.println(s.substring(i,i+4));
            ch.add(s.charAt(i));
            ch.add(s.charAt(i+1));
            ch.add(s.charAt(i+2));
            ch.add(s.charAt(i+3));
            if(ch.size()==4) ans++;
            ch.clear();
        }
        return ans;
    }
}
