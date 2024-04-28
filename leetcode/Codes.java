package leetcode;
import java.util.*;
@SuppressWarnings("unchecked")
public class Codes {
    static Scanner scan = new Scanner(System.in);
    public static void main(String[] args) {
        do{
            System.out.println("----MENU----");
            System.out.println("1. Valid Path");
            System.out.println("2. Minimum Height Trees");
            System.out.println("3. N-th Tribonacci Number");
            System.out.println("4. Longest Ideal String");
            System.out.println("5. Minimum Falling Path Sum");
            System.out.println("6. Freedom Trail");
            System.out.println("7. Sum of Distances in Tree");
            System.out.println("8. Open the Lock");
            System.out.println("8888. Exit");
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
                    System.out.print("Enter the number of nodes: ");
                    n = scan.nextInt();
                    System.out.print("Enter the number of edges: ");
                    m = scan.nextInt();
                    edges = new int[m][2];
                    for(int i=0; i<m; i++){
                        System.out.print("Enter the edge " + (i+1) + ": ");
                        edges[i][0] = scan.nextInt();
                        edges[i][1] = scan.nextInt();
                    }
                    System.out.println(findMinHeightTrees(n, edges));
                    break;
                case 3:
                    System.out.print("Enter the value of n: ");
                    n = scan.nextInt();
                    System.out.println(tribonacci(n));
                    break;
                case 4:
                    System.out.print("Enter the string: ");
                    String s = scan.next();
                    System.out.print("Enter the value of k: ");
                    int k = scan.nextInt();
                    System.out.println(longestIdealString(s, k));
                    break;
                case 5:
                    System.out.print("Enter the number of rows: ");
                    int rows = scan.nextInt();
                    System.out.print("Enter the number of columns: ");
                    int cols = scan.nextInt();
                    int[][] grid = new int[rows][cols];
                    for(int i=0; i<rows; i++){
                        for(int j=0; j<cols; j++){
                            System.out.print("Enter the value at " + i + ", " + j + ": ");
                            grid[i][j] = scan.nextInt();
                        }
                    }
                    System.out.println(minFallingPathSum(grid));
                    break;
                case 6:
                    System.out.print("Enter the ring: ");
                    String ring = scan.next();
                    System.out.print("Enter the key: ");
                    String key = scan.next();
                    System.out.println(findRotateSteps(ring, key));
                    break;
                case 7:
                    System.out.print("Enter the number of nodes: ");
                    n = scan.nextInt();
                    System.out.print("Enter the number of edges: ");
                    m = scan.nextInt();
                    edges = new int[m][2];
                    for(int i=0; i<m; i++){
                        System.out.print("Enter the edge " + (i+1) + ": ");
                        edges[i][0] = scan.nextInt();
                        edges[i][1] = scan.nextInt();
                    }
                    System.out.println(Arrays.toString(sumOfDistancesInTree(n, edges)));
                    break;
                case 8:
                    System.out.print("Enter the number of deadends: ");
                    int num = scan.nextInt();
                    String[] deadends = new String[num];
                    for(int i=0; i<num; i++){
                        System.out.print("Enter the deadend " + (i+1) + ": ");
                        deadends[i] = scan.next();
                    }
                    System.out.print("Enter the target: ");
                    String target = scan.next();
                    System.out.println(openLock(deadends, target));
                    break;
                case 8888:
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

    static public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> result = new ArrayList<>();
        if (n == 1) {
            result.add(0);
            return result;
        }
        
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
        
        int[] degree = new int[n];
        
        for (int[] edge : edges) {
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        // queue.offer => is used to verify if the queue is full or not and then inserts the element, if full it return false.
        Queue<Integer> leaves = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leaves.offer(i);
            }
        }
        
        while (n > 2) {
            int size = leaves.size();
            n -= size;
            for (int i = 0; i < size; i++) {
                int leaf = leaves.poll();
                for (int neighbor : adjList.get(leaf)) {
                    if (--degree[neighbor] == 1) {
                        leaves.offer(neighbor);
                    }
                }
            }
        }
        
        result.addAll(leaves);
        return result;
    }

    static public int tribonacci(int n) {
        if(n == 0) return 0;
        else if(n == 1 || n ==2) return 1;
        int t1 = 0;
        int t2 = 1;
        int t3 = 1;
        n-=3;
        while(n>=0){
            int t4 = t3+t2+t1;
            t1 = t2;
            t2 = t3;
            t3 = t4;
            n--;
        }
        return t3;
    }

    static public int longestIdealString(String s, int k) {
        int N = s.length();
        int[] dp = new int[26];

        int res = 0;
        // Updating dp with the i-th character
        for (int i = 0; i < N; i++) {
            int curr = s.charAt(i) - 'a';
            int best = 0;
            for (int prev = 0; prev < 26; prev++) {
                if (Math.abs(prev - curr) <= k) {
                    best = Math.max(best, dp[prev]);
                }
            }

            // Appending s[i] to the previous longest ideal subsequence allowed
            dp[curr] = Math.max(dp[curr], best + 1);
            res = Math.max(res, dp[curr]);
        }
        return res;
    }
    
    static public int minFallingPathSum(int[][] grid) {
        int n = grid.length;
        if (n == 1)
            return grid[0][0];

        int l[] = new int[n];
        int r[] = new int[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int d = Integer.MAX_VALUE;
                if (j > 0) d = Math.min(d, l[j - 1]);
                if (j < n - 1) d = Math.min(d, r[j + 1]);
                grid[i][j] += d;
            }

            l[0] = grid[i][0];
            for (int j = 1; j < n; j++)
                l[j] = Math.min(l[j - 1], grid[i][j]);

            r[n - 1] = grid[i][n - 1];
            for (int j = n - 2; j >= 0; j--)
                r[j] = Math.min(r[j + 1], grid[i][j]);
        }

        return l[n - 1];
    }

    // 514. Freedom Trail - Hard
    /*
    First Example:
    Input: ring = "godding", key = "gd"
    Output: 4

    2nd Example:
    Input: ring = "godding", key = "godding"
    Output: 13
     */
    static public int findRotateSteps(String ring, String key) {
        char[] r = ring.toCharArray();
        List<Integer>[] positions = new List[26];
        for (int i = 0; i < r.length; i++) {
            int c = r[i] - 'a';
            if (positions[c] == null) positions[c] = new ArrayList<>();
            positions[c].add(i);
        }
        int[][] dp = new int[key.length()][r.length];
        return FindRotationStepsHelper(0, 0, positions, key.toCharArray(), r, dp);
    }

    static int FindRotationStepsHelper(int index, int pos, List<Integer>[] positions, char[] key, char[] ring, int[][] dp) {
        if (index == key.length) return 0;
        if (dp[index][pos] > 0) return dp[index][pos];
        char target = key[index];
        List<Integer> possiblePositions = positions[target - 'a'];
        int minSteps = Integer.MAX_VALUE;
        for (int nextPos : possiblePositions) {
            int steps = Math.min(Math.abs(nextPos - pos), ring.length - Math.abs(nextPos - pos));
            int totalSteps = steps + FindRotationStepsHelper(index + 1, nextPos, positions, key, ring, dp);
            minSteps = Math.min(minSteps, totalSteps);
        }
        return dp[index][pos] = minSteps + 1;
    }


    // 834. Sum of Distances in Tree - Hard
    /* 
     * Input: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
     * Output: [8,12,6,10,10,10]
     * 
     * Input: N = 1, edges = []
     * Output: [0]
     * 
     * Input: N = 2, edges = [[1,0]]
     * Output: [1,1]
    */
    static public int[] sumOfDistancesInTree(int n, int[][] edges) {
        // build graph and declare results
        final ArrayList<Integer>[] graph = new ArrayList[n];
        final int[] count = new int[n];
        Arrays.fill(count, 1);
        final int[] answer = new int[n];
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }

        postOrder(0, -1, graph, count, answer);
        // after postOrder, only answer[root] is correct, so do preOrder to update answer
        preOrder(0, -1, graph, count, answer, n);

        return answer;
    }

    // set count et subTreeSum, here use answer[]
    static public void postOrder(int node, int parent, ArrayList<Integer>[] graph, int[] count, int[] answer) {
        for (int child : graph[node]) {
            if (child != parent) {
                postOrder(child, node, graph, count, answer);
                count[node] += count[child];
                answer[node] += answer[child] + count[child];
            }
        }
    }

    static public void preOrder(int node, int parent, ArrayList<Integer>[] graph, int[] count, int[] answer, int n) {
        for (int child : graph[node]) {
            if (child != parent) {
                answer[child] = answer[node] + (n - count[child]) - count[child];
                preOrder(child, node, graph, count, answer, n);
            }
        }
    }

    // 752. Open the Lock - Medium
    /*
       Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
        Output: 6
        Explanation: 
        A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
        Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
        because the wheels of the lock become stuck after the display becomes the dead end "0102".
     */
    static public int openLock(String[] deadends, String target) {
        Set<String> seen = new HashSet<>(Arrays.asList(deadends));
        if (seen.contains("0000"))
          return -1;
        if (target.equals("0000"))
          return 0;
    
        int ans = 0;
        Queue<String> q = new ArrayDeque<>(Arrays.asList("0000"));
    
        while (!q.isEmpty()) {
          ++ans;
          for (int sz = q.size(); sz > 0; --sz) {
            StringBuilder sb = new StringBuilder(q.poll());
            for (int i = 0; i < 4; ++i) {
              final char cache = sb.charAt(i);
              // Increase the i-th digit by 1.
              sb.setCharAt(i, sb.charAt(i) == '9' ? '0' : (char) (sb.charAt(i) + 1));
              String word = sb.toString();
              if (word.equals(target))
                return ans;
              if (!seen.contains(word)) {
                q.offer(word);
                seen.add(word);
              }
              sb.setCharAt(i, cache);
              // Decrease the i-th digit by 1.
              sb.setCharAt(i, sb.charAt(i) == '0' ? '9' : (char) (sb.charAt(i) - 1));
              word = sb.toString();
              if (word.equals(target))
                return ans;
              if (!seen.contains(word)) {
                q.offer(word);
                seen.add(word);
              }
              sb.setCharAt(i, cache);
            }
          }
        }
    
        return -1;
      }
}
