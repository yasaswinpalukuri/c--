import java.util.*;

public class meetingParadox{
    static Scanner scan = new Scanner(System.in);
    
    static class Interval{
        int start,end;
        Interval(int start, int end){
            this.start=start;
            this.end=end;
        }
    }

    public static int metting(int input1,int[][] input2){ 

        if (input1 <= 0)  return 0;
        
        Interval arr[] = new Interval[input1];
        
        for(int i=0;i<input1;i++) arr[i] = new Interval(input2[i][0],input2[i][1]);
        Stack<Interval> stack=new Stack<>();
        
        Arrays.sort(arr,new Comparator<Interval>(){
            public int compare(Interval i1,Interval i2)
            {
                return i1.start-i2.start;
            }
        });
 
        stack.push(arr[0]); 
    
        for(int i=1;i<input1;i++){ 
            Interval top = stack.peek(); 

            if (top.end < arr[i].start) 
                stack.push(arr[i]); 
            else if (top.end < arr[i].end) 
            { 
                top.end = arr[i].end; 
                stack.pop(); 
                stack.push(top); 
            } 
        }
        return stack.size();
    }
    
    
    
    public static void main(String args[]) {
        int n = scan.nextInt();
        int arr[][] = new int[n][2];
        for(int i=0;i<n;i++){
            arr[i][0] = scan.nextInt();
            arr[i][1] = scan.nextInt();
        }
        System.out.println(metting(n,arr));
    }
    
}