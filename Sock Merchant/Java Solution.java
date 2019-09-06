import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the sockMerchant function below.
    static int sockMerchant(int n, int[] ar) {
        Map<Integer, Double> socks = new HashMap<Integer, Double>();
        int numOfPairs = 0;

        for(int i : ar) {
            if(!socks.containsKey(i)) {
                socks.put(i, .5); // If the map doesn't have the key, add it.
            } else{
                socks.put(i, socks.get(i) +.5); // Increment the key
            }
        }

        for(Map.Entry<Integer, Double> entry : socks.entrySet()) {
            numOfPairs+=Math.floor(entry.getValue()); // Ignore the fractional pairs and print the whole number.
        }

        return numOfPairs;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] ar = new int[n];

        String[] arItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arItem = Integer.parseInt(arItems[i]);
            ar[i] = arItem;
        }

        int result = sockMerchant(n, ar);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
