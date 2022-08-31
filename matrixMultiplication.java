import java.util.*;

public class matrixMultiplication {
    static Scanner scan = new Scanner(System.in);
    public static void main(String args[]) {
        int t = scan.nextInt(); // Initial value of array
        int n = scan.nextInt(); // No.of Rows
        int m = scan.nextInt(); // No.of Columns
            
        int[][] a = new int[n][m]; // Matrix
        int[][] b = new int[m][n]; // Tranpose Matrix
        
        // Creating an matrix and it's transpose with given initial value.
        for(int i=0;i<n;i++) for(int j=1;j<=m;j++){
            a[i][j-1] = t;
            b[j-1][i] = t;
            t++;
        }
        
        // Matrix filled with values with given initial value.
        System.out.print("Matrix:\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) System.out.print(a[i][j] + " ");
            System.out.println();
        }
        
        // Tranpose Matrix filled with values with the given initial value.
        System.out.print("Transpose Matrix:\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) System.out.print(b[i][j] + " ");
            System.out.println();
        }
        

        // Matrix multiplication
        // Matrix has nxm => transpose has mxn
        // After Multiplication matrix will be nxm x mxn => nxn
        int[][] rslt = new int[n][n];
        System.out.println("Multiplication of given two matrices is:");
        int i, j, k;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                rslt[i][j] = 0;
                for (k = 0; k < n; k++)
                    rslt[i][j] += a[i][k] * b[k][j];
                    System.out.print(rslt[i][j] + " ");
                }
            System.out.println("");
        }
    }
}