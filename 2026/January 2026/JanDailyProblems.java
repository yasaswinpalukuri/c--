import java.util.*;
import java.math.*;
import javax.swing.*;

public class JanDailyProblems {
    class ListNode{
        int val;
        ListNode next;
        ListNode(int val){
            this.val = val;
        }
        ListNode(int val, ListNode next){
            this.val = val; this.next = next;
        }
    }
    class TrieNode {

        boolean isEnd;
        TrieNode[] children;
    
        TrieNode() {
            isEnd = false;
            children = new TrieNode[26];
        }
    }
    
    class Trie {
    
        TrieNode root;
    
        Trie() {
            root = new TrieNode();
        }
    
        void insert(String word) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                int index = c - 'a';
                if (node.children[index] == null) {
                    node.children[index] = new TrieNode();
                }
                node = node.children[index];
            }
            node.isEnd = true;
        }
    }
    
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Welcome to Jan Daily Leetcode Problems");
        System.out.println("This is Yasaswin Palukuri, with solutions to the Daily Problems of Jan 2026");
        System.out.println("So, without any further ado, let's get started");
        do{
            System.out.println("Enter the day of the problem you want the answer for or 88 to Exit:");
            System.out.println("Day 1: Plus One(Problem: 66)");
            System.out.println("Day 2: ");
            System.out.println("Day 3: ");
            System.out.println("Day 4: ");
            System.out.println("Day 5: ");
            System.out.println("Day 6: ");
            System.out.println("Day 7: ");
            System.out.println("Day 8: ");
            System.out.println("Day 9: ");
            System.out.println("Day 10: ");
            System.out.println("Day 11: ");
            System.out.println("Day 12: ");
            System.out.println("Day 13: ");
            System.out.println("Day 14: ");
            System.out.println("Day 15: ");
            System.out.println("Day 16: ");
            System.out.println("Day 17: ");
            System.out.println("Day 18: ");
            System.out.println("Day 19: ");
            System.out.println("Day 20: ");
            System.out.println("Day 21: ");
            System.out.println("Day 22: ");
            System.out.println("Day 23: ");
            System.out.println("Day 24: ");
            System.out.println("Day 25: ");
            System.out.println("Day 26: ");
            System.out.println("Day 27: ");
            System.out.println("Day 28: ");
            System.out.println("Day 29: ");
            System.out.println("Day 30: ");
            System.out.println("Day 31: ");
            System.out.println("88: Exit");
            int day = scan.nextInt();
            switch(day){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    break;
                case 10:
                    break;
                case 11:
                    break;
                case 12:
                    break;
                case 13:
                    break;
                case 14:
                    break;
                case 15:
                    break;
                case 16:
                    break;
                case 17:
                    break;
                case 18:
                    break;
                case 19:
                    break;
                case 20:
                    break;
                case 21:
                    break;
                case 22:
                    break;
                case 23:
                    break;
                case 24:
                    break;
                case 25:
                    break;
                case 26:
                    break;
                case 27:
                    break;
                case 28:
                    break;
                case 29:
                    break;
                case 30:
                    break;
                case 31:
                    break;
                case 88:
                    System.out.println("Thank you for using the May Daily Leetcode Problems :)");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Sorry, the problem for the day you entered is not available");
                    break;
            }
        }while(true);
    }
    
}