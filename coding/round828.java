import java.util.*;

public class round828 {
    static Scanner scan = new Scanner(System.in);
    public static void main(String args[]){
        evenOddIncrements();
    }

    static void evenOddIncrements(){
        int t = scan.nextInt();
        while(t-- > 0){
            int n = scan.nextInt(),q = scan.nextInt();
            int a[] = new int[n];
            int sum = 0;
            for(int i=0;i<n;i++){
                a[i] = scan.nextInt();
                sum += a[i];
            }
            while(q-- > 0){
                int x = scan.nextInt(),y = scan.nextInt();
                for(int i=0;i<n;i++){
                    if(x == 0){
                        if(a[i]%2 == 0){
                            a[i] += x;
                        }
                    }else{
                        if(a[i]%2 == 1){
                            a[i] += y;
                        }
                    }
                }
                System.out.println(sum);
            }
        }
    }

    static void numberReplacemene(){
        int t = scan.nextInt();
        while(t-- > 0){
            int n = scan.nextInt();
            int a[] = new int[n];
            for(int i=0;i<n;i++) a[i] = scan.nextInt();
            String s = scan.next();
            Map<Integer, Integer> m1 = new HashMap<>();
            Map<Character, Integer> m2 = new HashMap<>();
            for(int i=0;i<n;i++){
                m1.put(a[i], m1.getOrDefault(a[i], 0)+1);
                m2.put(s.charAt(i), m2.getOrDefault(s.charAt(i), 0)+1);
            }
            boolean end = false;
            for(int i=0;i<n;i++){
                if(m1.get(a[i]) != m2.get(s.charAt(i))) continue;
                else end = true;
            }
            System.out.println(end?"YES":"NO");
        }
    }
}
