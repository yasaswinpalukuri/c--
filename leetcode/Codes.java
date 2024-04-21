package leetcode;
import java.util.*;
import java.io.*;

public class Codes {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        
    }
    static public boolean validPath(int n, int[][] edges, int source, int destination) {
        int i = source;
        HashMap<Integer,List<Integer>> hm = new HashMap<>();
        for(int s=0;s<edges.length;s++){
            hm.put(edges[s][0],hm.getOrDefault(i, new List<Integer>()).add(edges[s][1]));
            // hm.put(edges[s][1],hm.get(i).add(edges[s][0]));
            hm.put(edges[s][1],hm.getOrDefault(i, new List<Integer>()).add(edges[s][0]));
        }
        // while( i!= destination){
        //     if(hm.containsKey(i)) i = hm.get(i);
        //     else return false;
        // }
        System.out.println(hm);
        return true;
    }
}
