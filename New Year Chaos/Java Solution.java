import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the minimumBribes function below.
    static void minimumBribes(int[] q) {
        Map<Integer, Integer> mMap = new HashMap();
        int numBribes = 0;
        int thisRound = 1;
        boolean tooChaotic = false;

        while(thisRound > 0){
            thisRound = 0;
            for(int i = 0; i < q.length - 1; i++){
                if(q[i] > q[i+1]){
                    addOne(mMap, q[i]);
                    swap(q, i, i+1);
                    
                    if(mMap.get(q[i+1]) > 2){
                        tooChaotic = true;
                        break;
                    }
                    thisRound++;
                    numBribes++;
                }
            }
            if(tooChaotic){
                break;
            }
        }
        if(tooChaotic){
            System.out.println("Too chaotic");
        }else{
            System.out.println(numBribes);
        }

    }

    private static void swap(int[] q, int i, int j){
        int temp = q[i];
        q[i] = q[j];
        q[j] = temp;
    }

    private static void addOne(Map<Integer, Integer> m, int i){
        if(m.containsKey(i)){
            m.put(i, m.get(i) + 1);
        }else{
            m.put(i, 1);
        }

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] q = new int[n];

            String[] qItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                int qItem = Integer.parseInt(qItems[i]);
                q[i] = qItem;
            }

            minimumBribes(q);
        }

        scanner.close();
    }
}
