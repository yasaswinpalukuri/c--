package leetcode;
import java.util.*;

public class Codes {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        do{
            System.out.println("----MENU----");
            System.out.println("1. Valid Path");
            System.out.println("2. Exit");
            System.out.print("Enter your choice: ");
            int ch = scan.nextInt();
            switch(ch){
                case 1:
                    System.out.print("Enter the number of nodes: ");
                    int n = scan.nextInt();
                    System.out.print("Enter the number of edges: ");
                    int m = scan.nextInt();
                    int[][] edges = new int[m][2];
                    for(int i=0; i<m; i++){
                        System.out.print("Enter the edge " + (i+1) + ": ");
                        edges[i][0] = scan.nextInt();
                        edges[i][1] = scan.nextInt();
                    }
                    System.out.print("Enter the source node: ");
                    int source = scan.nextInt();
                    System.out.print("Enter the destination node: ");
                    int destination = scan.nextInt();
                    System.out.println(validPath(n, edges, source, destination));
                    break;
                case 2:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        }while(true);
    }

    static public boolean validPath(int n, int[][] edges, int source, int destination) {
        if(edges.length == 0) return true;
        boolean[] visited = new boolean[n];
        boolean flag = true;
        visited[source] = true;
        while(flag){
            flag = false;
            for(int[] edge : edges){
                if(visited[edge[0]] != visited[edge[1]]){
                    visited[edge[0]] = true;
                    visited[edge[1]] = true;
                    flag = true;
                }
                if(visited[destination]) return true;
            }
        }
        return false;
    }
}
