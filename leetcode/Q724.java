package leetcode;

import java.util.*;

public class Q724 {
    static Scanner scan = new Scanner(System.in);
    public static void main(String args[]){
        int n = scan.nextInt();
        int a[] = new int[n];
        for(int i=0;i<n;i++) a[i] = scan.nextInt();
        System.out.println("pivotIndex() : "+pivotIndex(a));
        System.out.println("pivotIndex2() : "+pivotIndex2(a));
    }

    public static int pivotIndex(int[] nums) {
        int sum = 0;
        for(int i=0;i<nums.length;i++) sum += nums[i];
        int leftSum = 0;
        for(int i=0;i<nums.length;i++){
            if(leftSum == sum - leftSum - nums[i]) return i;
            leftSum += nums[i];
        }
        return -1;
    }

    public static int pivotIndex2(int[] nums) {
        for(int i=0;i<nums.length;i++){
            int l=0,r=0;
            for(int j=0;j<i;j++) l += nums[j];
            for(int j=i+1;j<nums.length;j++) r += nums[j];
            if(l == r) return i;
        }
        return -1;
    }
}
