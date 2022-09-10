import java.util.*;

public class milestone4{
    static Scanner scan =  new Scanner(System.in);
    public static void main(String args[]){
        // System.out.print("Enter n:"); int n = scan.nextInt();
        // int a[] = new int[n];
        // System.out.print("Enter Array:"); for(int i=0;i<n;i++) a[i] = scan.nextInt();
        // System.out.println("PositionBasedSum:"+PositionBasedSum(a,n));
        // System.out.println("sumOfPrimeIndexValues:"+sumOfPrimeIndexValues(a,n));
        // System.out.println("stringDecoder:"+stringDecoder("0010001010000"));
        // System.out.println("findSumOfPrimes:"+findSumOfPrimes(a,n));
        // int k[] = {15,16,1,-2,-13,61,11,4,3,19,-4,17,-3,90,-65,67,12,0,13,2,3,43,21,-17,2,42};
        // System.out.println("findStringWeight:"+findStringWeight(k,"Wipro Limited"));
        // System.out.println("findPin:" + findPin(8530,5620,7532));
        // System.out.println("totalHillWeight : " + totalHillWeight(5,10,2));
        // System.out.println("find2Password : " + find2Password(new int[]{12,2,36,10,217,36,5,36,15,10},10));
        // System.out.println("find3Password : " + find3Password(new int[]{12,2,36,10,217,36,5,36,15,10},10));
        System.out.println("findDashes : " + findDashes(new String[]{".-.-.--",".-.-.-.-.-","...---.-"}));
    }

    public static boolean isPrime(int n){
        if(n == 0 || n==1) return false;
        for(int i=2;i<=Math.sqrt(n);i++) if(n%i==0) return false;
        return true;
    }

    public static int sumOfNonPrimeIndexValues(int[] input1,int input2){
        int sum = 0;
        for(int i=0;i<input2;i++) if(!isPrime(i)){
            // System.out.println(input1[i] + " ");
            sum += input1[i];
        }
        return sum;
    }

    public static int sumOfPrimeIndexValues(int[] input1,int input2){
        int sum = 0;
        for(int i=0;i<input2;i++) if(isPrime(i)){
            // System.out.println(input1[i] + " ");
            sum += input1[i];
        }
        return sum;
    }

    public static int findPin(int input1,int input2,int input3){
        int pin = 0;
        int a[] = new int[10];

        // System.out.print("a:");
        // for(int i=0;i<10;i++) System.out.print(a[i] + " ");
        
        int ma = Integer.MIN_VALUE;
        int mi = Integer.MAX_VALUE; 

        int t = input1%10;
        a[t]++;
        ma = Math.max(a[t],ma);
        mi = Math.min(a[t],mi);
        t = (input1/10)%10;
        a[t]++;
        ma = Math.max(a[t],ma);
        mi = Math.min(a[t],mi);
        t = (input1/100)%10;
        a[t]++;
        ma = Math.max(a[t],ma);
        mi = Math.min(a[t],mi);
        t = (input1/1000);
        a[t]++;
        ma = Math.max(a[t],ma);
        mi = Math.min(a[t],mi);

        t = input2%10;
        a[t]++;
        ma = Math.max(a[t],ma);
        mi = Math.min(a[t],mi);
        t = (input2/10)%10;
        a[t]++;
        ma = Math.max(a[t],ma);
        mi = Math.min(a[t],mi);
        t = (input2/100)%10;
        a[t]++;
        ma = Math.max(a[t],ma);
        mi = Math.min(a[t],mi);
        t = (input2/1000);
        a[t]++;
        ma = Math.max(a[t],ma);
        mi = Math.min(a[t],mi);

        t = input3%10;
        a[t]++;
        ma = Math.max(a[t],ma);
        mi = Math.min(a[t],mi);
        t = (input3/10)%10;
        a[t]++;
        ma = Math.max(a[t],ma);
        mi = Math.min(a[t],mi);
        t = (input3/100)%10;
        a[t]++;
        ma = Math.max(a[t],ma);
        mi = Math.min(a[t],mi);
        t = (input3/1000);
        a[t]++;
        ma = Math.max(a[t],ma);
        mi = Math.min(a[t],mi);

        // System.out.print("\na:");
        // for(int i=0;i<10;i++) System.out.print(a[i] + " ");
        // System.out.println("max = " + ma + " min = " + mi);

        for(int i=9;i>=0;i--) if(a[i] >=1) {pin = pin*10 + i; break;}
        for(int i=0;i<10;i++) if(a[i] >= 1) {pin = pin*10 + i;break;}
        for(int i=9;i>=0;i--) if(a[i] == ma) {pin = pin*10 + i;break;}
        for(int i=0;i<10;i++) if(a[i] == mi) {pin = pin*10 + i;break;}
        return pin;
    }

    public static int findStringWeight(int[] input1,String input2){
        int ans = 1;
        String[] str = input2.split(" ");
        for(String s:str){
            int sum = 0;
            int i = 1;
            if(s.charAt(0) >= 'a' && s.charAt(0)<='z'){
                int t = input1[s.charAt(0) - 'a'] + (int)(s.charAt(0) - 'a' + 1);
                // System.out.print("sum:" + sum + " " + s.charAt(i) + " " + input1[s.charAt(i) - 'a'] + " " + t + " ");
                if(input1[s.charAt(0) - 'a'] < 0){
                    // System.out.print("Adding t,t=" + t+ ",");
                    sum += t;
                }
                else{
                    // System.out.print("Adding input1,");
                    sum += input1[0];
                }
                // System.out.print("sum:"+sum);
            }
            else if(s.charAt(0) >= 'A' && s.charAt(0) <= 'Z'){
                int t = input1[s.charAt(0) - 'A'] + (int)(s.charAt(0) - 'A' + 1);
                // System.out.print("sum:" + sum + " " + s.charAt(i) + " " + input1[s.charAt(i) - 'A'] + " " + t + " ");
                if(input1[s.charAt(0) - 'A'] < 0){
                    // System.out.print("Adding t,t=" + t + ",");
                    sum += t;
                }
                else{
                    // System.out.print("Adding input1,");
                    sum += input1[0];
                }
                // System.out.println("sum:"+sum);
            }
            for(;i < s.length()-1 ;i++){
                if(s.charAt(i) >= 'a' && s.charAt(i) <= 'z'){
                    // System.out.print("sum:" + sum + " " + s.charAt(i) + " " + input1[s.charAt(i) - 'a'] + " ");
                    sum += input1[s.charAt(i) - 'a'];
                }
                else if(s.charAt(i) >= 'A' && s.charAt(i) <= 'Z'){
                    // System.out.print("sum:" + sum + " " + s.charAt(i) + " " + input1[s.charAt(i) - 'A'] + " ");
                    sum += input1[s.charAt(i) -'A'];
                }
                // System.out.println("sum:"+sum);
            }

            if(s.charAt(i) >= 'a' && s.charAt(i)<='z'){
                int t = input1[s.charAt(i) - 'a'] + (int)(s.charAt(i) - 'a' + 1);
                // System.out.print("sum:" + sum + " " + s.charAt(i) + " " + input1[s.charAt(i) - 'a'] + " " + t + " ");
                if(input1[s.charAt(i) - 'a'] < 0){
                    // System.out.print("Adding t,t=" + t+ ",");
                    sum += t;
                }
                else{
                    // System.out.print("Adding input1,");
                    sum += input1[i];
                }
                // System.out.print("sum:"+sum);
            }
            else if(s.charAt(i) >= 'A' && s.charAt(i) <= 'Z'){
                int t = input1[s.charAt(i) - 'A'] + (int)(s.charAt(i) - 'A' + 1);
                // System.out.print("sum:" + sum + " " + s.charAt(i) + " " + input1[s.charAt(i) - 'A'] + " " + t + " ");
                if(input1[s.charAt(i) - 'A'] < 0){
                    // System.out.print("Adding t,t=" + t + ",");
                    sum += t;
                }
                else{
                    // System.out.print("Adding input1,");
                    sum += input1[i];
                }
                // System.out.println("sum:"+sum);
            }
            ans *= sum;
            // System.out.println();
        }
        
        return ans;
    }

    public static String stringDecoder(String input1){
        String str[] = input1.split("1");
        StringBuffer ans = new StringBuffer("");
        for(int i=0;i<str.length;i++){
            int n = str[i].length();
            ans.append((char)(90-n+1));
        }
        return ans.toString();
    }

    public static int findSumOfPrimes(int[] input1,int input2){
        int map = Integer.MIN_VALUE,ma = Integer.MIN_VALUE,sum = 0,asum = 0;
        boolean c = false;
        for(int i=0;i<input2;i++){
            asum += input1[i];
            if(isPrime(input1[i])){
                sum += input1[i];
                if(input1[i] > map){
                    map = input1[i];
                    c = true;
                }
            }
            ma = Math.max(ma,input1[i]);
        }
        sum -= map;
        asum -= ma;
        return (c)?sum:asum;
    }

    public static int PositionBasedSum(int input1[],int input2){
        int ans = 0;
        for(int i=0;i<input2;i++){
            int t = (int) (input1[i]%(Math.pow(10,i)));
            t %= 10;
            ans += Math.pow(t,2);
        }
        return ans;
    }

    public static int totalHillWeight(int input1,int input2,int input3){
        int ans = 0;
        int p = input2;
        for(int i=0;i<input1;i++){
            ans += (p*(i+1) + i*(p-input3));
            p += input3;
        }
        return ans;
    }

    public static int findRepArray(int[] input1,int input2){
        Set<Integer> st = new HashSet<Integer>();
        for(int i=0;i<input2;i++){
            if(input1[i] > 0){
                if(st.contains(input1[i])) return input1[i];
                st.add(input1[i]);
            }
        }
        return (st.size() == input2)?input1[0]:0;
    }

    public static int findRoomNo(int[] input1,int[] input2,int[] input3,int input4){
        int ans = 0;
        int[] a = new int[input4];
        for(int i=0;i<input4;i++) a[i] = input1[i] + input2[i] + input3[i];

        return ans;
    }

    public static int find2Password(int[] input1,int input2){
        HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
        for(int i=0;i<input2;i++){
            if(hm.containsKey(input1[i])) hm.put(input1[i],hm.get(input1[i])+1);
            else hm.put(input1[i],1);
        }
        List<Map.Entry<Integer, Integer>> list = new LinkedList<Map.Entry<Integer, Integer>>(hm.entrySet());

        Collections.sort(list,(i1,i2) -> i2.getValue().compareTo(i1.getValue()));

        HashMap<Integer, Integer> temp
            = new LinkedHashMap<Integer, Integer>();
        for (Map.Entry<Integer, Integer> aa : list) {
            temp.put(aa.getKey(), aa.getValue());
        }
        // String str[] =new String[2];
        String s = "";
        int i = 0;
        // for(Map.Entry<Integer,Integer> e : temp.entrySet()){
        //     if(i < 2) str[i++] = Integer.toString(e.getKey());
        //     else break;
        // }
        for(Map.Entry<Integer,Integer> e : temp.entrySet()){
            if(i < 2) s += Integer.toString(e.getKey());
            else break;
            i++;
        }

        return Integer.parseInt(s);
        
        // return Integer.parseInt(str[1] + str[0]);
    }

    public static int find3Password(int[] input1,int input2){
        HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
        for(int i=0;i<input2;i++){
            if(hm.containsKey(input1[i])) hm.put(input1[i],hm.get(input1[i])+1);
            else hm.put(input1[i],1);
        }
        List<Map.Entry<Integer, Integer>> list = new LinkedList<Map.Entry<Integer, Integer>>(hm.entrySet());

        Collections.sort(list,(i1,i2) -> i2.getValue().compareTo(i1.getValue()));

        HashMap<Integer, Integer> temp = new HashMap<Integer, Integer>();

        for (Map.Entry<Integer, Integer> aa : list){
            if(temp.containsKey(aa.getKey())){
                if(temp.get(aa.getKey()) < aa.getValue()) temp.put(aa.getKey(),aa.getValue());
            }
            else temp.put(aa.getKey(), aa.getValue());
        }

        String s[] =new String[3];
        List<Integer> al = new ArrayList<>(temp.values());
        s[0] = Integer.toString(al.get(0));
        s[1] = Integer.toString(al.get(1));
        s[2] = Integer.toString(al.get(al.size()-1));

        return Integer.parseInt(s[2]+s[1]+s[0]);
    }

    public static boolean checkDashes(String s){
        Stack<Character> st = new Stack<Character>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == '.') st.push(s.charAt(i));
            else if(s.charAt(i) == '-'){
                if(st.isEmpty()) return false;
                else st.pop();
            }
        }
        return true;
    }

    public static int findDashes(String[] str){
        int ans = 0;
        for(int i=0;i<str.length;i++){
            if(checkDashes(str[i])) ans++;
        }
        return ans;
    }
}