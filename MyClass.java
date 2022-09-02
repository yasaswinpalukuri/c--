import java.util.*;

public class MyClass {
        static Scanner scan = new Scanner(System.in);
    public static void main(String args[]) {
        int n = scan.nextInt();
        List<Integer> al = new ArrayList<Integer>();
        int k;
        for(int i=0;i<n;i++){
            k = scan.nextInt();
            al.add(k);
        }
        k = scan.nextInt();
        System.out.println("count subarrays:"+countSubarrays(al,k));
        int m = scan.nextInt();
        List<String> sl = new ArrayList<>();
        for(int i=0;i<m;i++){
            sl.add(scan.next());
        }
        m = scan.nextInt();
        List<Integer> rep = new ArrayList<>();
        for(int i=0;i<m;i++){
            rep.add(scan.nextInt());
        }
        System.out.println("balancedOrNot:"+balancedOrNot(sl,rep));
        
        String s = scan.next();
        String[] str= s.split(" ");
        StringBuffer sb = new StringBuffer();
        for(int i=0;i<str.length;i++){
            sb.append(str[i].charAt(0));
            sb.append(".");
        }
        sb.append(str[str.length-1]);
        System.out.println(sb);
    }
    
    // static long countSubarrays(List<Integer> num,int k){
    //     int s = 0, e = 0;
    //     int p = num.get(0);
    //     long c = 0;
    //     while(s < num.size() && e < num.size()){
    //         if(p < k){
    //             e++;
    //             if(e >= s) c += e-s;
    //             if(e < num.size()) p *= num.get(e);
    //         }else{
    //             p /= num.get(s);
    //             s++;
    //         }
    //     }
    //     return c;
    // }
    
    static long countSubarrays(List<Integer> num,int k){
        long temp = 1;
        int j = 0;
        int ans = 0;
        for(int i = 0; i < num.size(); i++){
            temp *= num.get(i);
            while(temp >= k && j <= i) {
                temp /= num.get(j);
                j++;
            }
            ans += (i - j + 1);
          }
          return ans;
    }
    
    // static List<Integer> balancedOrNot(List<String> exp,List<Integer> rep){
    //     List<Integer> ans = new ArrayList<>();
    //     System.out.println("exp:"+exp);
    //     System.out.println("rep:"+rep);
    //     for(int i=0;i<exp.size();i++){
    //         System.out.println(exp.get(i)+":"+minChanges(exp.get(i)));
    //         if(minChanges(exp.get(i)) == -1) ans.add(0); 
    //         else if(minChanges(exp.get(i)) <= rep.get(i)) ans.add(1);
    //         else ans.add(0);
    //     }
        
    //     return ans;
    // }
    
    static List<Integer> balancedOrNot(List<String> exp,List<Integer> rep){
        List<Integer> ans = new ArrayList<>();
        System.out.println("exp:"+exp);
        System.out.println("rep:"+rep);
        for(int i=0;i<exp.size();i++){
            String s = exp.get(i);
            int l = 0, r = 0;
            for(int j=0;j<s.length();j++){
                if(s.charAt(j) == '<') l++;
                else r++;
            }
            if(Math.abs(l-r) <= rep.get(i)) ans.add(1);
            else ans.add(0);
        }
        
        return ans;
    }
    
    static int minChanges(String s){
        int l = s.length();
        
        if (l % 2 != 0) return -1;
        Stack<Character> st = new Stack<>();
        
        for (int i = 0; i < l; i++) {
            char c = s.charAt(i);
            if (c == '>' && !st.empty()) {
                if (st.peek() == '<') st.pop();
                else st.push(c);
            }
            else st.push(c);
        }
        
        int r = st.size();
        int n = 0;
        
        while (!st.empty() && st.peek() == '<') {
            st.pop();
            n++;
        }
        
        return (r / 2 + n % 2);
    }
}