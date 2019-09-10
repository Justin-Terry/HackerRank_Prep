import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[][] arr = new int[6][6];
        int hourGlassTotal = 0;
        int maxTotal = Integer.MIN_VALUE;


        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }    
        }

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++){
                int tl = arr[i][j];
                int tm = arr[i][j+1];
                int tr = arr[i][j+2];
                int mid = arr[i+1][j+1];
                int bl = arr[i+2][j];
                int bm = arr[i+2][j+1];
                int br = arr[i+2][j+2];

                hourGlassTotal = tl + tm + tr + mid + bl + bm + br;
                if(hourGlassTotal > maxTotal) {
                    maxTotal = hourGlassTotal;
                }
            }
        }
        System.out.println(maxTotal);
        scanner.close();
    }
}
