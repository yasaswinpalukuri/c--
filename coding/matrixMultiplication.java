import java.util.*;

public class matrixMultiplication {
    static Scanner scan = new Scanner(System.in);
    public static void main(String args[]) {
        int t = scan.nextInt(); // Initial value of array
        int n = scan.nextInt(); // No.of Rows
        int m = scan.nextInt(); // No.of Columns
            
        int[][] a = new int[n][m]; // Matrix
        int[][] b = new int[m][n]; // Tranpose Matrix
        
        /*
        t = 1
        n = 2
        m = 3

        Matrix:
        [1 2 3]
        [4 5 6]

        Transpose Matrix:
        [1 4]
        [2 5]
        [3 6]

        a(0,0) b(0,0) a[i][j-1] = b[j-1][i] = t {i=0,j=0}
        a(0,1) b(1,0) a[i][j-1] = b[j-1][i] = t {i=0,j=1}
        a(0,2) b(2,0) a[i][j-1] = b[j-1][i] = t {i=0,j=2}

        a(1,0) b(0,1) a[i][j-1] = b[j-1][i] = t {i=1,j=0}
        a(1,1) b(1,1) a[i][j-1] = b[j-1][i] = t {i=1,j=1}
        a(1,2) b(2,1) a[i][j-1] = b[j-1][i] = t {i=1,j=2}

        for(int i=0;i<n;i++) for(int j=1;j<=m;j++) a[i][j-1] = b[j-1][i] = t++;

        i = 0
        j = 1
        a[0][0] = b[0][0] = 1
        j = 2
        a[0][1] = b[1][0] = 2
        j = 3
        a[0][2] = b[2][0] = 3

        i = 1
        j = 1
        a[1][0] = b[0][1] = 4
        j = 2
        a[1][1] = b[1][1] = 5
        j = 3
        a[1][2] = b[2][1] = 6

        */
        // Creating an matrix and it's transpose with given initial value.
        for(int i=0;i<n;i++) for(int j=1;j<=m;j++) a[i][j-1] = b[j-1][i] = t++;
        
        
        // Matrix(a[n][m]) filled with values with given initial value.
        System.out.print("Matrix:\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) System.out.print(a[i][j] + " ");
            System.out.println();
        }
        
        // Tranpose Matrix(b[m][n]) filled with values with the given initial value.
        System.out.print("Transpose Matrix:\n");
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) System.out.print(b[i][j] + " ");
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