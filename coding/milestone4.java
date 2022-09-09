import java.util.*;

public class milestone4{
    static Scanner scan =  new Scanner(System.in);
    public static void main(String args[]){
        // System.out.print("Enter n:"); int n = scan.nextInt();
        // int a[] = new int[n];
        // System.out.println("Enter Array:"); for(int i=0;i<n;i++) a[i] = scan.nextInt();
        // System.out.println("PositionBasedSum:"+PositionBasedSum(a,n));
        // System.out.println("sumOfPrimeIndexValues:"+sumOfPrimeIndexValues(a,n));
        // System.out.println("stringDecoder:"+stringDecoder("0010001010000"));
        // System.out.println("findSumOfPrimes:"+findSumOfPrimes(a,n));
        // int k[] = {15,16,1,-2,-13,61,11,4,3,19,-4,17,-3,90,-65,67,12,0,13,2,3,43,21,-17,2,42};
        // System.out.println("findStringWeight:"+findStringWeight(k,"Wipro Limited"));
        System.out.println("findPin:" + findPin(8530,5620,7532));
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
        System.out.print("a:");
        for(int i=0;i<10;i++) System.out.print(a[i] + " ");
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

        System.out.print("\na:");
        for(int i=0;i<10;i++) System.out.print(a[i] + " ");
        System.out.println("max = " + ma + " min = " + mi);
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
            int i = 0;
            for(;i < s.length()-1 ;i++){
                if(s.charAt(i) >= 'a' && s.charAt(i) <= 'z'){
                    System.out.print("sum:" + sum + " " + s.charAt(i) + " " + input1[s.charAt(i) - 'a'] + " ");
                    sum += input1[s.charAt(i) - 'a'];
                }
                else if(s.charAt(i) >= 'A' && s.charAt(i) <= 'Z'){
                    System.out.print("sum:" + sum + " " + s.charAt(i) + " " + input1[s.charAt(i) - 'A'] + " ");
                    sum += input1[s.charAt(i) -'A'];
                }
                System.out.println("sum:"+sum);
            }

            if(s.charAt(i) >= 'a' && s.charAt(i)<='z'){
                int t = input1[s.charAt(i) - 'a'] + (int)(s.charAt(i) - 'a' + 1);
                System.out.print("sum:" + sum + " " + s.charAt(i) + " " + input1[s.charAt(i) - 'a'] + " " + t + " ");
                if(input1[s.charAt(i) - 'a'] < 0){
                    System.out.print("Adding t,t=" + t+ ",");
                    sum += t;
                }
                else{
                    System.out.print("Adding input1,");
                    sum += input1[i];
                }
                System.out.print("sum:"+sum);
            }
            else if(s.charAt(i) >= 'A' && s.charAt(i) <= 'Z'){
                int t = input1[s.charAt(i) - 'A'] + (int)(s.charAt(i) - 'A' + 1);
                System.out.print("sum:" + sum + " " + s.charAt(i) + " " + input1[s.charAt(i) - 'A'] + " " + t + " ");
                if(input1[s.charAt(i) - 'A'] < 0){
                    System.out.print("Adding t,t=" + t + ",");
                    sum += t;
                }
                else{
                    System.out.print("Adding input1,");
                    sum += input1[i];
                }
                System.out.println("sum:"+sum);
            }
            ans *= sum;
            System.out.println();
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
                c = true;
                sum += input1[i];
                map = Math.max(map,input1[i]);
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
}